.name "zorkbeater"
.comment "having a fight with zork"

st r1, 6
live %0
st r1, 6
live %0

work:
fork %:thief
st r1, 6
live %0

looplive:
sti r1, %:live, %1
ld %0, r16

live: 
live %1
zjmp%:live


thief:
ld %0, r16
zjmp %510

