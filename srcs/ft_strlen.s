section .text
	global _ft_strlen

_ft_strlen:
	cmp rdi, 0x0
	je .null_exit
	mov rax, 0
	jmp .comapre
	
.increment:
	inc rax

.comapre:
	cmp BYTE[rdi + rax], 0
	jne .increment

.exit:
	ret

.null_exit:
	mov rax, 0
	ret