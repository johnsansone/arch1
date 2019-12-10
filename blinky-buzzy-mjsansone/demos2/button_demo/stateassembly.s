mode_update:

	push    rbp

	mov     rbp, rsp

	sub     rsp, 16

	mov     eax, edi

	mov     WORD PTR [rbp-4], ax

	movsx   eax, WORD PTR [rbp-4]

	cmp     eax, 3

	je      .L2

	cmp     eax, 3

	jg      .L7

	cmp     eax, 2

	je      .L4

	cmp     eax, 2

	jg      .L7

	test    eax, eax

	je      .L5

	cmp     eax, 1

	je      .L6

	jmp     .L7

	.L5:

	mov     eax, 0

	call    button0

	jmp     .L3

	.L6:

	mov     eax, 0

	call    button1

	jmp     .L3

	.L4:

	mov     eax, 0

	call    button2

	jmp     .L3

	.L2:

	mov     eax, 0

	call    button3

	nop

	.L3:

	.L7:

	nop

	leave

	        ret
