section .text
	global _test_func
	extern _ft_strcpy
	extern _ft_strlen
	extern _malloc

_test_func: ; rdi = src
	cmp rdi, 0x0
	je .exit
	call _ft_strcpy
	ret
	
.exit:
	mov rax, r13
	ret