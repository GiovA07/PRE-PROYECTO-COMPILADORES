fact:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $96, %rsp 
    movl %edi, -16(%rbp)
    movl $1, -32(%rbp)


L1: 
    movl -16(%rbp) , %eax
    cmpl  $0 , %eax 
    setg %al
    movzbl %al, %eax
    movl  %eax, -48(%rbp)
    cmpl  $1,  -48(%rbp)
    jne L2
    movl -32(%rbp), %eax
    movl -16(%rbp), %edx
    imull %edx, %eax
    movl %eax, -64(%rbp)
    movl -64(%rbp), %eax

    movl %eax, -32(%rbp)

    movl -16(%rbp), %eax
    movl $1, %edx
    subl %edx, %eax
    movl %eax, -80(%rbp)
    movl -80(%rbp), %eax

    movl %eax, -16(%rbp)

    jmp L1


L2: 
    movl -32(%rbp),  %eax
    addq $96, %rsp 
    popq    %rbp
    ret
fact1:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $112, %rsp 
    movl %edi, -16(%rbp)
    movl -16(%rbp) , %eax
    cmpl  $1 , %eax 
    sete %al
    movzbl %al, %eax
    movl  %eax, -32(%rbp)
    cmpl  $1,  -32(%rbp)
    jne L3
    movl $1,  %eax
    jmp L4


L3: 
    movl -16(%rbp), %eax
    movl $1, %edx
    subl %edx, %eax
    movl %eax, -64(%rbp)
    movl -64(%rbp), %eax

    movl %eax, -48(%rbp)

    movl -48(%rbp), %eax
    movl %eax, %edi
    call fact1
    movl %eax, -96(%rbp)
    movl -96(%rbp), %eax
    movl -16(%rbp), %edx
    imull %edx, %eax
    movl %eax, -80(%rbp)
    movl -80(%rbp),  %eax


L4: 
    addq $112, %rsp 
    popq    %rbp
    ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $96, %rsp 
    movl $5, %edi
    call fact
    movl %eax, -48(%rbp)
    movl -48(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -32(%rbp)
    movl $5, %edi
    call fact1
    movl %eax, -80(%rbp)
    movl -80(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -64(%rbp)
    addq $96, %rsp 
    popq    %rbp
    ret
