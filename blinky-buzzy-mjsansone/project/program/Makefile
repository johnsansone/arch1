# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o stateassembly.s led.o switches.o programMain.o state.o buzzer.o wdinterruptHandler.o lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^
#enter this to load using assembly      stateassembly.s  
load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf

