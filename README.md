# AVR Lチカ

## ターゲット
* ATMEGA8-16PU
* 電源はmbedから5Vを供給.
* PD7->LED->抵抗->GND

## プログラマ
* AVRISPmkII + Ubuntu

```
$ sudo apt-get install binutils-avr gcc-avr avr-libc avrdude
$ avr-gcc -mmcu=atmega8 ./led.c -o ./led.out
$ sudo avrdude -c avrispmkII -P usb -p m8 -U flash:w:led.out:e -v
```

書き込み時のログ(3つめのコマンドの出力)
```
avrdude: Version 6.2
         Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
         Copyright (c) 2007-2014 Joerg Wunsch

         System wide configuration file is "/etc/avrdude.conf"
         User configuration file is "/home/owner/.avrduderc"
         User configuration file does not exist or is not a regular file, skipping

         Using Port                    : usb
         Using Programmer              : avrispmkII
avrdude: usbdev_open(): Found AVRISP mkII, serno: 000200222429
         AVR Part                      : ATmega8
         Chip Erase delay              : 10000 us
         PAGEL                         : PD7
         BS2                           : PC2
         RESET disposition             : dedicated
         RETRY pulse                   : SCK
         serial program mode           : yes
         parallel program mode         : yes
         Timeout                       : 200
         StabDelay                     : 100
         CmdexeDelay                   : 25
         SyncLoops                     : 32
         ByteDelay                     : 0
         PollIndex                     : 3
         PollValue                     : 0x53
         Memory Detail                 :

                                  Block Poll               Page                       Polled
           Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
           ----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
           eeprom         4    20   128    0 no        512    4      0  9000  9000 0xff 0xff
           flash         33    10    64    0 yes      8192   64    128  4500  4500 0xff 0x00
           lfuse          0     0     0    0 no          1    0      0  2000  2000 0x00 0x00
           hfuse          0     0     0    0 no          1    0      0  2000  2000 0x00 0x00
           lock           0     0     0    0 no          1    0      0  2000  2000 0x00 0x00
           calibration    0     0     0    0 no          4    0      0     0     0 0x00 0x00
           signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00

         Programmer Type : STK500V2
         Description     : Atmel AVR ISP mkII
         Programmer Model: AVRISP mkII
         Hardware Version: 1
         Firmware Version Master : 1.23
         Vtarget         : 4.8 V
         SCK period      : 8.00 us

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e9307 (probably m8)
avrdude: safemode: hfuse reads as D9
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file "led.out"
avrdude: writing flash (230 bytes):

Writing | ################################################## | 100% 0.09s

avrdude: 230 bytes of flash written
avrdude: verifying flash memory against led.out:
avrdude: load data flash data from input file led.out:
avrdude: input file led.out contains 230 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.08s

avrdude: verifying ...
avrdude: 230 bytes of flash verified

avrdude: safemode: hfuse reads as D9
avrdude: safemode: Fuses OK (E:FF, H:D9, L:E1)

avrdude done.  Thank you.
```
