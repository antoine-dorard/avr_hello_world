# Hello, AVR!
Repository of tiny projects for getting started with AVR programming in C.

## Setup
For these projects, I am using the ATMega328P and a [USBAsp](https://www.fischl.de/usbasp/) to program it.
### Software Installation
#### Compiling
Get the AVR-GCC toolchain [here](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers).


#### Programming
Install [AVRDUDE](https://github.com/avrdudes/avrdude).
```
sudo apt install avrdude
```

### Hardware Setup
insert schematic here

## Projects
List of projects under this repository.
### Blinking LED
Simple blinking led program, or the "Hello, World!" of embedded programming.
#### Code
#### Schematic

### Not LED
Turn off a led when a button is pressed.
#### Code
#### Schematic

### Who said no light?
Using a light sensor, progressively turn on a led if when the light sensor detects less and less light.
#### Code
#### Schematic

