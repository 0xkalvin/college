

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
    c+=2;                     add $s1, $s1, 2
                              add $s0, $s0, 1
                             j for
                        done: la $s2, $s1



li $s0, 3           int a = 3
li $s1, 4           int b = 4
li $s2, 10          int m = 10

lw $t0, 0($s0)      
sw $t0, 0($s2)      m = a

slt $t1, $s1, $s2
beq $t1, 1, target

target: lw $t3, 0($s2)
