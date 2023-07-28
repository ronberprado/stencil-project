; Ronber Jonathan T. Prado - G01

section .data
var dq 0, 0

section .text
bits 64
default rel    ; []
global SIMDstencil

;extern void SIMDstencil(size_t ARRAY_SIZE, int* x, int* y);
; rcx - ARRAY_SIZE, rdx - ptr to x, r8 - ptr to y

SIMDstencil:
	vmovdqu ymm2, [var]     ; rbx to 0
	shr rcx, 3

L1:
	vmovdqu ymm1, [rdx-12]  ; load X[i-3]
    vpaddd ymm2, ymm1, ymm2
	vmovdqu ymm1, [rdx-8]   ; load X[i-2]
    vpaddd ymm2, ymm1, ymm2
	vmovdqu ymm1, [rdx-4]   ; load X[i-1]
    vpaddd ymm2, ymm1, ymm2
	vmovdqu ymm1, [rdx]     ; load X[i]
    vpaddd ymm2, ymm1, ymm2
	vmovdqu ymm1, [rdx+4]   ; load X[i+1]
    vpaddd ymm2, ymm1, ymm2
	vmovdqu ymm1, [rdx+8]   ; load X[i+2]
    vpaddd ymm2, ymm1, ymm2
	vmovdqu ymm1, [rdx+12]  ; load X[i+3]
    vpaddd ymm2, ymm1, ymm2 ; store ans to rbx

	vmovdqu [r8], ymm2      ; store to y
	vmovdqu ymm2, [var]     ; reset rbx

	add rdx, 32         ; inc x ptr
	add r8, 32          ; inc y ptr

	loop L1

ret
