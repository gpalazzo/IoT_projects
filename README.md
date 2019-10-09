**This project aims to show how to switch a light on based on a time-driven event.**

It was built only as a prototype since my main goal with this was learning how to use Arduino in a house automation project.

_Files:_<br>
electrical_schematic.pdf --> project's electrical schematic with all components and connections.<br>
main.c --> source code as a c language file;<br>
schematics.fzz --> source file for the electrical schematic from the software Fritzing.

_Directories:_<br>
main --> contains the main.ino file which can be inserted into an Arduino board;<br>
photos_functional_prototype --> contains 3 photos of the functional prototype.

_Materials:_
- 1 Arduino Uno (Rev3);
- 1 Breadboard;
- 1 LCD 16x2;
- 1 Potentiometer 10k OHMs;
- 1 Pushbutton;
- 1 Resistor 10k OHM;
- 1 RTC DS3231;
- 1 Relay with 2 channels (JQC-3FF-S-Z) -- you don't need to use 2 channel relay actually, I used it because it was the only one I had;
- 1 Source of energy (power plug) -- in this project it's been represented by 110mAh 3.7V battery;
- 1 Lamp -- in this project it's been represented by a LED;

Obs: in the schematics I'm using a different relay (WeMos D1 Mini Relay Shield V1), because it was as similar as possible to the relay mentioned in the materials. So, due to that, that might be some minor changes in the code to make it functional.

_I'm pretty new to this Arduino world, so feel free to reach out in case you didn't understand something, or there's something wrong._
