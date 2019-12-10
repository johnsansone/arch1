This toy contains 4 different state M's with 4 states each. button1 cycles
through sounds with no leds. button 2 cycles through sounds with dimmed
leds. button3 cycles through leds and sounds. button4 cycles through sounds
and leds in a different pattern than3. each buttons state is saved when going
to a different buttons state.

There were many issues with this program there is a memory leak somewhere in
lcd draw. the buttons change sound and led's but not the screen as you can not
controll the position of the box from structs. most of the changes are in
main or wdinterrupthandler.  
