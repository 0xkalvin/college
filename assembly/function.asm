

.data
arr: .word 1, 2, 3, 4, 5, 6, 7, 8, 9

.text
la $a0, arr
li $a1, 1   # primeiro
li $a2, 9   # ultimo
jal soma

soma:
	    la $t0, $a1   # inicio do for
	    la $t1, $a2   # fim do for
        li $t2, 0   # soma

for:    beq $t0, $t1, done
        lw $t4, ($a0)       # $t4 = arr[i]
        add $t2, $t2, $t4   # soma += arr[i]
        addi $t0, $t0, 1    # i++
        addi $a0,$a0,4      # arruma endereco
        j for
	
done:
    la $s1, $t2             # salva resultado em $s1
	jr $ra


div $s1, $a2

# quociente $LO
# resto $HI



