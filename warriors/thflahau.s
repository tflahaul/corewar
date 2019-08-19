.name 		"warrior"
.comment	"definitly not a living being"

init:
	sti		r1, %0, %100
	sti		r1, %0, %150
	sti		r1, %0, %200
	sti		r1, %0, %250
	sti		r1, %0, %300
	sti		r1, %0, %350
	sti		r1, %0, %2147483647
	sti		r1, %0, %:init
	ld		%-4, r1
