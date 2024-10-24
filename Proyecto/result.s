MAIN:
    pushq   %rbp
    movq    %rsp, %rbp
    movl -8(%rbp) , %eax
    cmpl -16(%rbp) , %eax
    sete %al
    movzbl %al, %eax
    movl  %eax -32(%rbp)
    ;PRINCIPIO ASIGN
    movl -32(%rbp), %eax

    movl %eax, -24(%rbp)

    ;FINAL ASIGN
    movl -8(%rbp) , %eax
    cmpl -16(%rbp) , %eax
    setl %al
    movzbl %al, %eax
    movl  %eax -40(%rbp)
    ;PRINCIPIO ASIGN
    movl -40(%rbp), %eax

    movl %eax, -24(%rbp)

    ;FINAL ASIGN
    movl -8(%rbp) , %eax
    cmpl -16(%rbp) , %eax
    setg %al
    movzbl %al, %eax
    movl  %eax -48(%rbp)
    ;PRINCIPIO ASIGN
    movl -48(%rbp), %eax

    movl %eax, -24(%rbp)

    ;FINAL ASIGN
    movl %eax, -8(%rbp)
    popq    %rbp
    ret
