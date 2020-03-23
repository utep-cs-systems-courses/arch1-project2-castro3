

	.arch msp430g2553

	.p2align 1,0

	.text

	.global off_leds

off_leds:nop

	mov.b r12, &red_on

	mov #0, &red_on


	cmp #0, &led_changed

	jz out

out:

	mov #1, r12

	pop r0	
