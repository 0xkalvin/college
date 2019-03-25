

int x = 10    --->      li $s0, 10
                            or
                        x: .text 10
                        la $s0, x

c[10]           --->    c: .text 1,2,3,4,5,6,7,8,9,10
                        la $s0, c
                        lw $t0,10 ($s0) 

if(x == y)      --->    # x = $s0; y = $s1; z = $s2
    z = x + y           beq $s0, $s1, else
else                    add $s2, $s0, $s1
    z = x - y           else: sub $s2, $s0, $s1


c = 0           --->    # i = $s0; c = $s1
for(i = 0; i < 10; i++) for: beq $s0, 10, done
    c++;                     add $s1, $s1, 1
                             add $s0, $s0, 1
                             j for
                        done: la $s2, $s1

