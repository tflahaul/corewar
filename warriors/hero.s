.name "hero"
.comment "fire on the mood"

starter:
ld %285212671, r13 #10ffffff
ld %0, r16
zjmp %:begin
zjmp %:liveflood

begin:
st r1, 6
live %0
st r1, 6
live %0
ld %0, r16
st r13, -34
zjmp %:jumper

flooding:
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0

jumper:
zjmp %:soldier

liveflood:
fork %:live
ld %0, r16
zjmp %30

live:
sti r1, %:flood, %1
ld %0, r16

flood:
live %1

soldier:
ld %190056457 , r2  #0b540809
ld %101253600, r8   #060901e0
ld %4294967041, r10 #ffffff01
ld %4294967295, r11 #ffffffff
ld %495 , r9
ld %0, r6
st r10, 498	
st r11, 497
st r2, 497  
st r8, 496
fork %:soldier2
ld %190056201, r8   #0b540709
ld %4294967043 ,r7  #ffffff03
ld %83887619, r5    #50000603
ld %0, r16
zjmp %437

soldier2:
ld %1879375874, r5  #70050002
ld %1879375874, r7  #70050002
ld %4, r6
ld %0, r16
zjmp %400
