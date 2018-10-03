Sketch for Teensy 2.0 Arduino musical instrument. Originally a hobby project, this grew into my final project for my junior year Computer Organization and Architecture class. Fingerings and usage meant to be identical to a Great Highland Bagpipe practice chanter. toneAC library must be installed to compile, available here:

https://forum.arduino.cc/index.php?topic=142097.0

Wiring is as follows:

FreeScale MPXV4006GP Pressure Sensor <- Analog 10
For accurate breath sensing, vinyl tubing attached to the sensor may be required

Momentary push buttons:
 o <- Digital 1
 o <- Digital 2
 o <- Digital 3

 o <- Digital 4
 o <- Digital 5
 o <- Digital 6
o  <- Digital 7

Speaker/3.5mm Audio Jack
Audio Signal - Pin 13
Ground - Pin 14
Note that you do not connect ground on the speaker/jack to ground on the board

Based on the work of Gordon Good:
http://gordophone.blogspot.com/