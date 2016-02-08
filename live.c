
#include <SPI.h>
#include <Ethernet.h>
#include "Wire.h"
#include "BlinkM_funcs.h"

#define blinkm_addr 0x00

// assign a MAC address for the ethernet controller.
// fill in your address here:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
// fill in an available IP address on your network here,
// for manual configuration:
IPAddress ip(192, 168, 0, 177);

// fill in your Domain Name Server address here:
IPAddress myDns(8, 8, 8, 8);

// initialize the library instance:
EthernetClient client;

//char server[] = "www.some.domain";
IPAddress server(192,168,0,3);

unsigned long lastConnectionTime = 0;             // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10L * 1000L; // delay between updates, in milliseconds
// the "L" is needed to use long type numbers

#define RESPONSE_LENGTH 500

char response[RESPONSE_LENGTH]; // string for incoming serial data
int responsePos = 0; // string index counter

void setup() {

  BlinkM_beginWithPower();
  BlinkM_stopScript(blinkm_addr);  // turn off startup script

  // start serial port:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // give the ethernet module time to boot up:
  delay(1000);
  // start the Ethernet connection using a fixed IP address and DNS server:
  Ethernet.begin(mac, ip, myDns);
  // print the Ethernet board/shield's IP address:
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  memset( &response, 0, RESPONSE_LENGTH); // clear response memory
  responsePos = 0;
  int bodyPos = 0;
  int linebreak = 0;
  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      response[responsePos] = c;
      responsePos++;
      if (c == '\r' || c == '\n') {
        linebreak++;
      } else {
        linebreak = 0;
      }
      if (responsePos == RESPONSE_LENGTH || linebreak == 4) {
        bodyPos = responsePos;
        Serial.println("Found body");
        Serial.print(bodyPos);  
        Serial.println("");
      }
      if (bodyPos != 0 && c == 'y') {
        Serial.println("YES!");
        BlinkM_fadeToRGB( blinkm_addr, 0, 255, 0 );
      }
      if (bodyPos != 0 && c == 'n') {
        Serial.println("No!");
        BlinkM_fadeToRGB( blinkm_addr, 255, 0, 0 );
      }
    } 
  }
  // if ten seconds have passed since your last connection,
  // then connect again and send data:
  if (millis() - lastConnectionTime > postingInterval) {
    httpRequest();
  }
}

// this method makes a HTTP connection to the server:
void httpRequest() {
  // close any connection before send a new request.
  // This will free the socket on the WiFi shield
  client.stop();
  // if there's a successful connection:
  if (client.connect(server, 8081)) {
    Serial.println("connecting...");
    // send the HTTP PUT request:
    client.println("GET /latest.txt HTTP/1.1");
    client.println("Host: 192.168.0.3");
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    client.println();
    // note the time that the connection was made:
    lastConnectionTime = millis();
  } else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
}
