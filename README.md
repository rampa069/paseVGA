# paseVGA

An emulation of the ZXSpectrum computer on an ESP32 and VGA Screen using the
bitluni VGA card.

VGA Driver is from ESP32Lib by BitLuni

https://github.com/bitluni/ESP32Lib

You need to upload the SPIFFS filesystem using the plugin in arduino.

https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/

Z80 core is by Marcel de Kogel

Will load SNA snapshots from SPIFF space.


set run_snaphot to false  to boot normally or set it to true ans  change the
SNA file and startup address in Tapes.INO 

 There is no copyrighted games in the data folder, if you have the right to
use on, copy it to the data folder.

 Look/change paledefs.h to change vga, keyboard and buzzer pins

Bugs: 

For some reason the SNA snapshot will not run properly using the RETN from the pushed PC on the stack, 
the code in 'tapes' has a hardcoded jump to the startup address.

