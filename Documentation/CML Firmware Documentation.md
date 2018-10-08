# Overview of the Firmware

The Coal Mine Elevator Firmware ("CME Firmware") is written specifically for the Coal Mine Distributed Controller Board ("CMDCB"), an ATmega 328P-powered board that attaches to the Coal Mine Elevator on the Eli Whitney Museum's seasonal train display. The Firmware allows interaction with the Coal Mine Elevator in the following ways:

+ Offer a single arcade button for the public to press
+ Automatically lower and raise the elevator when the arcade button is pressed
+ Offer two under-the-table override buttons for staff to move the elevator up and down
+ Display error codes and realtime endstop engagement to staff via several under-the-table status LEDs

The Firmware utilizes an endstop and encoder to detect potentially erroneous or destructive motor control. In the event that a malfunction does happen, the Firmware will display an error code on the CMDCB's LED and potentially disable the operation of the motor. The Firmware is generally permissive to errors, to prevent non-critical issues from requiring human input.


# Error Codes

See **Error Codes Documentation** for a list of error codes and their operation.
