.name "roduquen_2"
.comment "ALIVE"

init:
		ld		%0, r3
		ld		%1, r3
		ld		%13, r13

start:	live	%:start
		sti		r2, %:start, %0
		fork	
		xor		r11,r12,r14
		zjmp	%:start

rewrite:
		
