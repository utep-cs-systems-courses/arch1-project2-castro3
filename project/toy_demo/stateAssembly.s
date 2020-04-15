	.arch msp430g2553

	.p2align 1,0

	.text

	.global song_play


table:
	.word default
	.word case1
	.word case2
	.word case3
	
song_play:
	cmp #4, r12 ;check range
	jnc default ;out of range or 0 range go to default
	add r12, r12 ;get correct range 
	mov table(r12), r0 ;check for location in table
	
case1:
	ret #1
	jmp end
	

case2:
	ret #2
	jmp end
	
case3:	
	ret #3
	jmp end

default:
	ret #0
	jmp end
	
end:
	pop r0
