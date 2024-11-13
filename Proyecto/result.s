mcd:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $96, %rsp 
    movl %edi, -16(%rbp)
    movl %esi, -32(%rbp)
    movl -32(%rbp) , %eax
    cmpl  $0 , %eax 
    sete %al
    movzbl %al, %eax
    movl  %eax, -48(%rbp)
    cmpl  $1,  -48(%rbp)
    jne L1
    movl -16(%rbp),  %eax
    addq $96, %rsp 
    popq    %rbp
    ret
    jmp L2


L1: 
    movl -16(%rbp), %eax
    cltd
    idivl -32(%rbp)
    movl %edx, -80(%rbp)
    movl -32(%rbp), %eax
    movl %eax, %edi
    movl -80(%rbp), %eax
    movl %eax, %esi
    call mcd
    movl %eax, -64(%rbp)
    movl -64(%rbp),  %eax
    addq $96, %rsp 
    popq    %rbp
    ret


L2: 

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $48, %rsp 
    movl $100, %edi
    movl $234, %esi
    call mcd
    movl %eax, -32(%rbp)
    movl -32(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -16(%rbp)
    movl $1,  %eax
    addq $48, %rsp 
    popq    %rbp
    ret
