potenciaHastaCiertoNum:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $144, %rsp 
    movl %edi, -16(%rbp)
    movl %esi, -32(%rbp)
    movl -32(%rbp) , %eax
    cmpl  $0 , %eax 
    sete %al
    movzbl %al, %eax
    movl  %eax, -80(%rbp)
    cmpl  $1,  -80(%rbp)
    jne L1
    movl $1,  %eax


L1: 
    movl $1, -48(%rbp)
    movl -16(%rbp), %eax

    movl %eax, -64(%rbp)



L2: 
    movl -48(%rbp) , %eax
    cmpl -32(%rbp) , %eax
    setl %al
    movzbl %al, %eax
    movl  %eax, -96(%rbp)
    cmpl  $1,  -96(%rbp)
    jne L3
    movl -64(%rbp), %eax
    movl -16(%rbp), %edx
    imull %edx, %eax
    movl %eax, -112(%rbp)
    movl -112(%rbp), %eax

    movl %eax, -64(%rbp)

    movl -48(%rbp), %eax
    movl $1, %edx
    addl %edx, %eax
    movl %eax, -128(%rbp)
    movl -128(%rbp), %eax

    movl %eax, -48(%rbp)

    jmp L2


L3: 
    movl -64(%rbp),  %eax
    addq $144, %rsp 
    popq    %rbp
    ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $64, %rsp 
    movl $2, %edi
    movl $5, %esi
    call potenciaHastaCiertoNum
    movl %eax, -48(%rbp)
    movl -48(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -32(%rbp)
    movl $1,  %eax
    addq $64, %rsp 
    popq    %rbp
    ret
