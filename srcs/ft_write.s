extern ___error

section .text
	global _ft_write

_ft_write:
	mov rax, 0x2000004
	syscall
	jc .exit_error
	ret

.exit_error:
	mov r10, rax
	call ___error
    mov QWORD[rax], r10
	mov rax, -1
    ret
