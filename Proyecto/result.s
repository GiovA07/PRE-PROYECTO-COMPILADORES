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
    movl %edi, -16(%rbp)
    movl -16(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -24(%rbp)
    movl -24(%rbp), %eax

    movl %eax, -16(%rbp)

    nop
    leave
    ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    movl $1, -32(%rbp)
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
    movl %eax, -40(%rbp)
    cmpl  $1,  -40(%rbp)
    jne L1
    movl $100, %edi
    call prinInt
    movl %eax, -48(%rbp)
    jmp L2


L1: 
    movl $0, %edi
    call prinInt
    movl %eax, -56(%rbp)


L2: 
    movl $11,  %eax
    popq    %rbp
    ret
