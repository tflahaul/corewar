.name "roduquen"
.comment "ALIVE"

l1:		fork %10
		sti r1,%:live,%1
		and	r10,r12,r13

live:	live %1
		zjmp %:l1
