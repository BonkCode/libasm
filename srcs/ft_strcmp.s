section .text
	global _ft_strcmp

_ft_strcmp: ; rdi - s1, rsi - s2
	cmp rdi, 0x0
	je .null_exit
	cmp rsi, 0x0
	je .null_exit
	mov r10, 0
	jmp .compare
	
.compare:
	mov r14b, BYTE[rdi + r10]
	cmp r14b, BYTE[rsi + r10]
	jne .exit
	cmp BYTE[rdi + r10], 0
	je .exit
	cmp BYTE[rsi + r10], 0
	je .exit
	inc r10
	jmp .compare

.exit:
	mov rax, 0
	mov al, BYTE[rdi + r10]
	cmp al, BYTE[rsi + r10]
	je  .equ_exit
	jl .less_exit
	jne .greater_exit

.greater_exit:
	mov rax, 1
	ret

.less_exit:
	mov rax, -1
	ret

.equ_exit:
	mov rax, 0
	ret

.null_exit:
	cmp rdi, rsi
	je .equ_exit
	cmp rdi, 0x0
	je .less_exit
	jmp .greater_exit