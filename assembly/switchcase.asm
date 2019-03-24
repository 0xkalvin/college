.data
table: .word L1, L2, L3, L4

.text

la $t4, table
li $s1, 1
li $s2, 2
li $s3, 3
li $s4, 10


slt $t3, $s5, $zero
bne $t3, $zero, EXIT
slti $t3, $s5, 4
beq $t3, $zero, EXIT

sll $t1, $s5, 2
add $t1, $t1, $t4
lw $t0, 0($t1)

jr $t0

# if
L0:	bne $s1, $s2, Else
	add $s0, $s1, $s2
	j EXIT

# if/else
L1:	bne $s1, $s2, Else
	add $s0, $s1, $s2
Else:   sub $s0, $s1, $s2
	j EXIT

# while
L2:	j WHILE

WHILE:	beq $s0, $s4, EXIT
		addi $s0, $s0, 1
		j WHILE
j EXIT
	

# do/while
L3:	j DOWHILE

DOWHILE:	addi $s0, $s4, 10
			beq $s0, $s4, EXIT
			j DOWHILE

EXIT: