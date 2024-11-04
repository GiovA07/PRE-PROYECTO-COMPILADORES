.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    movl $2, -16(%rbp)
    movl -16(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -32(%rbp)
    movl -32(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -24(%rbp)
    movl -24(%rbp), %eax

    movl %eax, -16(%rbp)

    movl -16(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -40(%rbp)
    movl %eax, -16(%rbp)
    popq    %rbp
    ret
