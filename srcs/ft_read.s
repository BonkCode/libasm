extern ___error

section .text
	global _ft_read

_ft_read:
	mov rax, 0x2000003
	syscall
	jc .exit_error
	ret

.exit_error:
	mov r10, rax
	call ___error
    mov QWORD[rax], r10
	mov rax, -1
    ret
