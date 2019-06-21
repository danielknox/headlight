# HEADLIGHT Library
A easy to use L298N library to control bike headlights with Arduino.

## NOTICE
L298N modules have the ability to drive upto 4 DC devices at once, this library is intended to pilot only one headlight. So if you need to drive more lights (e.g. hazards), you either need another instance of this library or (more likely) the hazard library.

## INSTALL THE LIBRARY
Download this repository as a .zip file and from the Arduino IDE go to *Sketch -> Include library -> Add .ZIP Library*

## IMPORT
You can import the library in your code using the Arduino IDE going to *Sketch -> Include library -> Headlight*
or directly writing the include statement in your code:

```
#include <headlight.h>
```
## INSTANCE THE MODULE
To drive a motor the first think is to create an istance of the library.
```
Headlight myHeadlight(IN1, IN2);
```
* IN1 and IN2 are two digital pin connected to IN1 and IN2 of the module

## Methods
| Method | Params | Description
| :----- | :---------- | :------
|**mainbeam**|none| Run headlight in mainbeam mode (may depends on wires).
|**mainbeamFor**|unsigned long delay| Run headlight in mainbeam mode for a time specified by delay.
|**mainbeamFor**|unsigned long delay, CallBackFunction callback| Run headlight in mainbeam mode for a time specified by delay, after on execute the callback function.
|**dipped**|none| Run headlight in dipped mode (may depends by wires).
|**dippedFor**|unsigned long delay| Run headlight in dipped mode for a time specified by delay.
|**dippedFor**|unsigned long delay, CallBackFunction callback| Run headlight in dipped mode for a time specified by delay, after on execute the callback function.
|**on**|uint8_t mode| Light headlight. To specify the mode use *HEADLAMP::MAINBEAM* or *HEADLAMP::DIPPED*. 
|**off**|none| Turn off the headlight.
|**reset**|none| Used to re-enable headlight after the use of forwardFor and backwardFor methods.
|**isOn**|none| Returns a boolean indicating if headlight is on or not.
