MAIN:
    pushq   %rbp
    movq    %rsp, %rbp
    movl $2, -8(%rbp)
    movl $2, -12(%rbp)
    movl $1, %edx
    movl $6, %eax
    addl %edx, %eax
    movl %eax, -24(%rbp)
    movl -24(%rbp), %eax

    movl %eax, -4(%rbp)

    movl $10, %edx
    cltd
    idivl $5
    movl %eax, -28(%rbp)
    $0, %eax
    movl -28(%rbp), %eax

    movl %eax, -20(%rbp)

    movl $10, %edx
    movl $4, %eax
    imull %edx, %eax
    movl %eax, -32(%rbp)
    movl -32(%rbp), %eax

    movl %eax, -16(%rbp)

    movl $10, %edx
    movl $3, %eax
    subl %edx, %eax
    movl %eax, -36(%rbp)
    movl -36(%rbp), %eax

    movl %eax, -12(%rbp)

    movl $10, %edx
    cltd
    idivl $2
    movl %edx, -40(%rbp)
    $0, %eax
    movl -40(%rbp), %eax

    movl %eax, -8(%rbp)

    movl %eax, -4(%rbp)
    popq    %rbp
    ret
