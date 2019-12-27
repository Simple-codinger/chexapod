GCC=avr-g++
RM=rm -f

MCU=atmega328p

F_CPU=16000000UL

PROGRAMMER=arduino
PORT=-P/dev/ttyACM0
BAUD=-B115200

SRCDIR := src
BUILDDIR := build
BINDIR := bin
TARGET := program
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIB := -L lib
INC := -I include
CFLAGS = $(INC)
CFLAGS += -Os
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -Wall -Wstrict-prototypes
CFLAGS += -DF_CPU=$(F_CPU)
CFLAGS += -mmcu=$(MCU)
LDFLAGS=

all: hex eeprom

hex: $(BINDIR)/$(TARGET).hex

eeprom: $(BINDIR)/$(TARGET)_eeprom.hex

$(BINDIR)/$(TARGET).hex: $(BUILDDIR)/$(TARGET).elf
	avr-objcopy -O ihex -j .data -j .text $< $@

$(BINDIR)/$(TARGET)_eeprom.hex: $(BUILDDIR)/$(TARGET).elf
	avr-objcopy -O ihex -j .eeprom --change-section-lma .eeprom=1 $< $@

$(BUILDDIR)/$(TARGET).elf: $(OBJECTS)
	$(GCC) $(CFLAGS) $(OBJECTS) -o $@

$(BUILDDIR)/%.o : $(SRCDIR)/%.cpp
	$(GCC) $< $(CFLAGS) -c -o $@

flash:
	avrdude -p$(MCU) $(PORT) $(BAUD) -c$(PROGRAMMER) -Uflash:w:$(BINDIR)/$(TARGET).hex:a

clean:
	$(RM) $(BINDIR)/* $(OBJECTS) $(BUILDDIR)/*
