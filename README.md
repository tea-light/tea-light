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

Assemble the arduino by putting the BlinkM in place as shown here:

* https://jimmyg.org/blog/2009/arduino/IMG_8003.jpg

(You don't need the Ethernet shield for the demo, the BlinkM just goes in the
equivalent holes below)

Now download Arduino IDE version 1.6.7 from:

* https://www.arduino.cc/en/Main/Software

Tip: On Mac OS X, you might need to run it from Downloads, and right click and
choose Open to accept that it isn't verified first.

You'll need to git repos. First get the tea-light code:

~~~
git clone https://github.com/tea-light/tea-light.git
~~~

Then checkout the the latest BlinkM code from here:

~~~
git clone https://github.com/todbot/BlinkM-Examples.git
~~~

Create a new project called `tea-light` by choosing `File -> New` from the
Arduino IDE menu. Call it `tea-light`.

Now from your project choose `Sketch -> Add File ...` from the menu, and
navigate to the `BlinkM-Examples` directory you just checked out and choose the
file `arduino/BlinkMTester/BlinkM_funcs.h`.

Back in the IDE, click the `tea-light` tab, then copy and paste the code in the
`demo.c` file in the `tea-light` directory you checked out earlier.

Now you can click the tick button on the left of the menu to check your code.

If everything passes, plug your Arduino into the computer via the USB cable.

Next you'll need to tell the Arduino IDE which port the Arduino is on. You can
do this by selecting the correct option from the `Tools -> Port ->` sub-menu.

Now you can press the `Upload` arrow (next to the tick button you just clicked
in the toolbar) to deploy the built code to your Arduino.

You should see the tea-light start red, and change colour every few minutes.
The demo isn't really random, and might show the same sequence each time
you turn it on.


## Unexpected press coverage and citations:

- [Are Smart Gadgets Making us Dumb?](http://www.wsj.com/articles/SB10001424127887324503204578318462215991802) - Evgeny Morozov, the Wall Street Journal 
- [The costs of public involvement: everyday devices of carbon accounting and the materialization of participation](http://www.tandfonline.com/doi/pdf/10.1080/03085147.2011.602294) - Noortje Marres, Economy and Society,  Volume 40, Issue 4, 2011
- [Material Participation: Technology, the Environment and Everyday Publics](http://www.palgrave.com/us/book/9780230232112) - Noortje Marres, 2012

