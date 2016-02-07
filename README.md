# Tea Light

The Tea Light is described in these posts:

* http://chrisadams.me.uk/tag/tealight/
* https://jimmyg.org/blog/2009/arduino.html
* https://jimmyg.org/life/photo/2009/2009-04-08_arduino_tea_light/index.html

This repository is a re-creation of the tea-light using updated versions of all
the original tools. The recreation is for a Museum piece in Berlin.

The original used the site caniturniton.com but this is gone, so instead we use
the `alt` value of the last `<area>` tag from the graph displayed here:

* http://realtimeweb-prod.nationalgrid.com/Frequency60min.aspx

The actual data is a work in progress, for now this repo contains code for a
demo mode.

## Setup

Download Arduino IDE version 1.6.7 from:

* https://www.arduino.cc/en/Main/Software

Create a new project called `tea-light`:

Checkout the the latest BlinkM code from here:

~~~
git clone https://github.com/todbot/BlinkM-Examples.git
~~~

Now from your project choose `Sketch -> Add File ...` from the menu, and
navigate to the `BlinkM-Examples` directory you just checked out and choose the
file `arduino/BlinkMTester/BlinkM_funcs.h`.

In the `tea-light` tab, copy and paste the code from the `demo.c` file.

Now you can click the tick button on the left of the menu to check your code.

If everything passes, plug your Arduino into the computer via the USB cable.
Tell the Arduino IDE which port the Arduino is on by selecting the correct
option from the `Tools -> Port ->` sub-menu.

Now you can press the arrow next to the tick button to deploy the built code to
your Arduino.

You should see the tea-light start red, and change colour every few minutes.
The demo isn't really random, and might show the same sequence each time
you turn it on.
