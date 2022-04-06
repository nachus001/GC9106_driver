# GC9106_driver
GC9106 driver for the TFT_eSpi TFT library by Bodmer

This driver was originally converted by Boyeen and discussed here https://github.com/Bodmer/TFT_eSPI/discussions/1310
It manages some issues regarding the cheap chinese displays ST7735S based.

Some of them seems to adjust more to the Galaxycore's GC9106 TFT driver IC
(datasheet available here https://www.phoenixdisplay.com/wp-content/uploads/2019/07/GC9106_DS_V1.0_20170308.pdf)

So, here is my (minimal) correction to the driver

In order to make it work, you need to replace (and add) the repository files to the library structure.
Also, you need to add the following flags to platformio.ini

build_flags =

;minimal TFT display config flags, aside from the i/o pins and clock speed	
	-D USER_SETUP_LOADED=1
	-D GC9106_DRIVER=1
	-D TFT_RGB_ORDER=TFT_RGB	;or TFT_BGR
	-D TFT_INVERSION_ON		;or TFT_INVERSION_OFF
	

