# paseVGA

An emulation of the ZXSpectrum computer on an ESP32 and VGA Screen using the
bitluni VGA card.

VGA Driver is from ESP32Lib by BitLuni

https://github.com/bitluni/ESP32Lib

You need to upload the SPIFFS filesystem using the plugin in arduino.

https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/

Z80 core is by Marcel de Kogel

Will load SNA snapshots from SPIFF space.

Comment out the 'load_speccy' line in Setup to boot normally or change the
SNA file and startup address in Tapes.INO 

 Look/change plaedefs.h to change vga, keyboard and buzzer pins

Bugs: 

For some reason the SNA snapshot will not run properly using the RETN from the pushed PC on the stack, 
the code in 'tapes' has a hardcoded jumps to the startup address.

