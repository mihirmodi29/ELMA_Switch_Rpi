# ELMA_Switch_Rpi

Project Goals
---
The goal of project is to implement a switching of light on and off using a UV sensor or switch button and Raspberry Pi. This project is extention of ELMA: https://github.com/klavinslab/elma. 
I will extend the given example https://github.com/klavinslab/elma/blob/master/examples/toggle-switch.cc to Rapberry Pi.

Project Success
---
When the UV sensor senses an object it will turn the red led light on or when the user presses the button it will turn the red led light on. 
When there is no object around it will turn green led light on or when the  user releases the button it will turn the green led light on.

Resources
---
- Rapberry Pi
- LED's
- Visual studio C++
- UV Sensor
- Switch Button
- ELMA

Milestones
---
- Setting up Raspberry pi 3. (3/12/2019)
- Setting up ELMA into Raspberry pi 3. (3/14/2019)
- Gathering sensors and LED's. (3/15/2019)
- Prototype phase 1 and run initial code to ensure Rpi is setup. (3/18/2019)
- Final setup and final code with sensor implementation. (3/20/2019)
- Documentation and final submission. (3/22/2019) 

Progress Report (3/17/2019)
---
- I have setup my Raspberry pi with Raspbian OS. I have also used ELMA as library (https://github.com/klavinslab/elma) into my project from an example (https://github.com/klavinslab/elma_project). I have also gathered UV sensor along with LED's and developed starter code to blink LED's on and off. Currently I can blink LED on/off using WiringPi library. Next step is to set UV sensor and change state of LED depending on UV sensor output.  
