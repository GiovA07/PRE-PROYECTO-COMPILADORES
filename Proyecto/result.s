getA:
    pushq   %rbp
    movq    %rsp, %rbp
    movl $1, -8(%rbp)
    movl %eax, 0(%rbp)
    popq    %rbp
    ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    movl $0, -24(%rbp)
    movl -16(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -40(%rbp)
    movl -40(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -32(%rbp)
    movl -32(%rbp), %eax

    movl %eax, -16(%rbp)

    movl -16(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -48(%rbp)
    movl %eax, -16(%rbp)
    popq    %rbp
    ret
