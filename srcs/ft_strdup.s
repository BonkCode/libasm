section .text
	global _ft_strdup
	extern _ft_strcpy
	extern _ft_strlen
	extern _malloc

_ft_strdup: ; rdi = src
	cmp rdi, 0x0
	je .exit
	push rdi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	call _malloc
	cmp rax, 0
	je .exit
	mov rdi, rax ; 1st (dst)
	pop rsi
	call _ft_strcpy
	ret

.exit:
	mov rax, 0x0
	ret