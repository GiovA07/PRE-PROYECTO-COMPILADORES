.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    movl -8(%rbp) , %eax
    cmpl -16(%rbp) , %eax
    sete %al
    movzbl %al, %eax
    movl  %eax, -32(%rbp)
    movl -32(%rbp), %eax

    movl %eax, -24(%rbp)

    movl -8(%rbp) , %eax
    cmpl -16(%rbp) , %eax
    setl %al
    movzbl %al, %eax
    movl  %eax, -40(%rbp)
    movl -40(%rbp), %eax

    movl %eax, -24(%rbp)

    movl -8(%rbp) , %eax
    cmpl -16(%rbp) , %eax
    setg %al
    movzbl %al, %eax
    movl  %eax, -48(%rbp)
    movl -48(%rbp), %eax

    movl %eax, -24(%rbp)

    movl %eax, -8(%rbp)
    popq    %rbp
    ret
