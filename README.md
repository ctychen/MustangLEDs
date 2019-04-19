# Mustang LEDS #

Using an Arduino to interface with the RoboRIO over and Ethernet shield and receive commands for color changing LEDs.
Sample animations can be found in the folder.

## Parts List

* RoboRIO
* Arduino with Ethernet. This can be an Arduino with an Ethernet shield, or something like the Yun which has it built in
* Neopixel strip (WS2812 Integrated Light Source)
* Ethernet switch for extra Ethernet ports, so you can use Ethernet on RoboRio both for all your necessities and the fancy lights too

## Setting up for your team / Code checklist

Neopixels connected to Arduino pin 6. Using RGB format at 800KHZ bitstream

![LEDS to Arduino](https://lh3.googleusercontent.com/-gFxHv0gW18o/XDo4LhdlO5I/AAAAAAABkuw/7t_E-fPhBMYgM4TPLr6VMoqpOA2vIxaYQCK8BGAs/s512/8225756110042778619%253Faccount_id%253D0)

* Pin 6 on Arduino/Ethernet shield to white wire (DATAIN) on Neopixel strip 
* 5v pin on Arduino/Ethernet shield to red wire (VIN) on Neopixel strip
* GND pin on Arduino/Ethernet shield to black wire (GND) on Neopixel strip
* Arduino Ethernet shield to robot radio (as long as it's somehow connected to Ethernet on the robot side)
* Arduino to USB power 


In the Arduino code, to set up IP addresses: 

```cpp

IPAddress ip(10,te,am,3);                            //Defines a static IP for the Arduino/Ethernet Shield.
                                                     // For example: 10,6,70 for ours
IPAddress robotIp(10,te,am,2);                       //Defines the robot's IP

...
    
robotClient.connect(robotIp, 5801);               //Connects the client instance to the robot's socket at 5801;
```

On the RIO-side, make sure you have this in robotInit:

```java
 public void robotInit() {
    ...
    leds.socketSetup(5801);
    ...
  }
```

To run on RIO, deploy robotside code with gradle `./gradlew deploy` and also upload the Arduino sketch to the Arduino.


## Some sample animations included:

### Rainbow cycle

![rainbow cycle](https://lh3.googleusercontent.com/-pbeW7AVWYQ8/XG4rpIQArTI/AAAAAAABskk/z2AglVXCeWUnE2vlOIvMP7XHa_aw26YnwCK8BGAs/s512/7538046630114585539%253Faccount_id%253D0)


### Theatre chase

![theatre chase](https://lh3.googleusercontent.com/--bgKk-oODX4/XG4B1vi_7-I/AAAAAAABsgQ/r7O1cZODwD8kyDfdWAcZ5dU9ThrYYT1JACK8BGAs/s512/5723407278498003423%253Faccount_id%253D0)


### Meteor rain

![meteor](https://lh3.googleusercontent.com/-sn9jT64IJp8/XG4FiydE0PI/AAAAAAABshc/jeZfW0ammC8mPGr9Mxivw7FsT5_DA5h0QCK8BGAs/s512/846928781189907298%253Faccount_id%253D0)

