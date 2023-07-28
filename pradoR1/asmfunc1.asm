; Ronber Jonathan T. Prado - G01

section .text
bits 64
default rel    ; []
global x86stencil

;extern void x86stencil(size_t ARRAY_SIZE, int* x, int* y);
; ecx - ARRAY_SIZE, rdx - ptr to x, r8 - ptr to y

x86stencil:

L1:
	; calculate adjacent elements
	mov rax, [rdx-12]  ; load X[i-3]
    add rbx, rax
	mov rax, [rdx-8]   ; load X[i-2]
    add rbx, rax
	mov rax, [rdx-4]   ; load X[i-1]
    add rbx, rax
	mov rax, [rdx]     ; load X[i]
    add rbx, rax
	mov rax, [rdx+4]   ; load X[i+1]
    add rbx, rax
	mov rax, [rdx+8]   ; load X[i+2]
    add rbx, rax
	mov rax, [rdx+12]  ; load X[i+3]
    add rbx, rax       ; store ans to rbx

	mov [r8], rbx      ; store to y
	mov rbx, 0         ; reset rbx

	add rdx, 4         ; inc x ptr
	add r8, 4          ; inc y ptr

	loop L1

ret
