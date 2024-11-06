.section .data

 .global fa

 fa: 
    .long 0

.section .data

 .global aux

 aux: 
    .long 0

.section .data

 .global yyyy

 yyyy: 
    .long 0

.section .data

 .global x

 x: 
    .long 0

.section .text

 mostrarRes:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $48, %rsp 
    movl %edi, -16(%rbp)
    movl $1, %eax
    movl $1, %edx
    addl %edx, %eax
    movl %eax, -32(%rbp)
    movl -32(%rbp), %eax

    movl %eax, -16(%rbp)

    movl $10,  %eax
    addq $48, %rsp 
    popq    %rbp
    ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $112, %rsp 
    movl $1, -16(%rbp)
    movl $99, -32(%rbp)
    movl $1, aux(%rip)
    movl $1, fa(%rip)
    cmpl $0, aux(%rip)
    je .LA1 
    cmpl $0, fa(%rip)
    je .LA1 
    movl $1, %eax
    jmp .LA2 
.LA1: 
    movl $0, %eax
.LA2: 
    movl %eax, -48(%rbp)
    cmpl  $1,  -48(%rbp)
    jne L1
    movl $100, %edi
    call prinInt
    movl %eax, -64(%rbp)
    jmp L2


L1: 
    movl $0, %edi
    call prinInt
    movl %eax, -80(%rbp)


L2: 
    movl -32(%rbp), %eax
    movl %eax, %edi
    call mostrarRes
    movl %eax, -96(%rbp)
    addq $112, %rsp 
    popq    %rbp
    ret
