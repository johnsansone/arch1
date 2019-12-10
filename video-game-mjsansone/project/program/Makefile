# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf libLcd.a


libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o 

	$(AR) crs $@ $^

lcdutils.o: lcdutils.c lcdutils.h

lcddraw.o: lcddraw.c lcddraw.h

button.elf: ${COMMON_OBJECTS} lcdutils.o lcddraw.o libLcd.a p2_interrupt_handler.o stateassembly.s led.o switches.o programMain.o state.o buzzer.o wdinterruptHandler.o lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
#enter this to load using assembly      stateassembly.s  
load: libLcd.a button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf

