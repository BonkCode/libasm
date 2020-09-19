section .text
	global _ft_strcpy

_ft_strcpy: ; rdi = dst, rsi = src
	cmp rsi, 0x0
	je .exit
	mov rcx, 0 ; i
	mov rdx, 0 ; tmp
	jmp .copy

.increment:
	inc rcx

.copy:
	mov dl, BYTE[rsi + rcx]
	mov BYTE[rdi + rcx], dl
	cmp rdx, 0
	jne .increment

.exit:
	mov rax, rdi
	ret