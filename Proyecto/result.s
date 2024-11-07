.section .data

 .global x

 x: 
    .long 0

.section .text

 
.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $112, %rsp 
    call inputVal
    movl %eax, -48(%rbp)
    movl -48(%rbp), %eax

    movl %eax, -32(%rbp)

    call inputVal
    movl %eax, -64(%rbp)
    movl -64(%rbp), %eax

    movl %eax, -16(%rbp)

    movl -32(%rbp), %eax
    movl -16(%rbp), %edx
    addl %edx, %eax
    movl %eax, -96(%rbp)
    movl -96(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -80(%rbp)
    movl -32(%rbp),  %eax
    addq $112, %rsp 
    popq    %rbp
    ret
