# Custom SAMD21E17A Board Integration for PlatformIO

## Description 

Per https://community.platformio.org/t/programm-samd21-directly/18139.

## Opening the project 

Just clone this repository and use the "PIO Home screen" -> "Open Project" method. 

## Configuration

The board's JSON file and `platformio.ini` is already configured for the custom board and an Atmel ICE as upload and debugging tool. 

A custom Arduino variant folder has been created in the `custom_arduino_variant` folder, as a copy and slight modification of the Adafruit Trinket M0. Pin definitions can be expanded or changed at will in the corresponding `variant.cpp`/`variant.h` file. 

The board is assumed to have no crystall oscillator on board and therefore uses the `CRYSTALLESS` macro define in the board definition.

It is assumed that no bootloader is used (like SAM-BA), therefore the board's JSON file specifies `flash_without_bootloader.ld` and an application flash offset of 0.

