
SRC_PATH=src
BUILD_PATH=build

PROJECT=click


.PHONY: build burn clean

build: $(BUILD_PATH)/$(PROJECT).hex

burn: build
	avrdude -p m328p -v -c usbasp -P usb  -B 32 -U flash:w:$(BUILD_PATH)/$(PROJECT).hex:i

clean:
	rm -f $(BUILD_PATH)/*
	

$(BUILD_PATH)/$(PROJECT).hex: $(BUILD_PATH)/$(PROJECT).elf
	avr-objcopy -j .text -j .data -O ihex $< $@

$(BUILD_PATH)/$(PROJECT).elf: $(SRC_PATH)/$(PROJECT).c
	@mkdir -p $(BUILD_PATH)
	avr-gcc -mmcu=atmega328p -D__AVR_ATmega328P__ -Wall -Os -o $@ $<
