        .text
	.global mode_update
	.extern button0
	.extern button1
	.extern button2
	.extern button3
mode_update:

	cmp     #3, r12

	jeq      .B3

	cmp     #2,r12

	jeq      .B2

	cmp    #1,r12

	jeq      .B1

	cmp     #0,r12

	jeq      .B0

	jmp     .BAD

.B0:

	call #button0

	jmp     .BAD

.B1:

	call #button1

	jmp     .BAD

.B2:

	call #button2

	jmp     .BAD

.B3:

	call #button3

.BAD:
	


	
