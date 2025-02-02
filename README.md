
Example Arduino project using EEZ-Studio and LVGL.

Configured for Raspberry Pi Pico using the arduino-pico core and an ILI9488 320x480 SPI touchscreen.

Brief instructions:

1. install LVGL library version 8.3.11 (not version 9)
2. install TFT_eSPI library version 2.5.43
3. copy the provided lvlg.h to the Arduino libraries folder (above, not in, the lvgl library folder)
4. copy the provided User_Setup_Select.h to the TFT_eSPI library folder
5. copy the provided Setup321_Pico_ILI9488_CV_Programmer.h to the User_Setups folder in the TFT_eSPI library folder
6. edit this file if your hardware or pin usage differs from mine
7. copy the Arduino project to your Arduino sketchbook folder
8. compile and upload

The first time you run the program, it will be necessary to calibrate the touchscreen. This runs automatically.

If you wish to modify the UI, install EEZ-Studio from https://www.envox.eu/studio/studio-introduction/.

Note that the UI design is configured for a 320x480 pixel display. You will need to modify the layout if your hardware differs from this.

The summary workflow for amending the UI:

1. make the desired changes in EEZ-Studio and save your changes
2. click the build (spanner) icon
3. copy the generated .c and .h files to the Arduino sketch folder
4. edit these files and change any #include of <lvgl/lvgl.h> to just <lvgl.h>
5. any new UI 'actions' (event handlers) will require a matching implementaton of the callback functions defined in actions.h
6. recompile and upload

