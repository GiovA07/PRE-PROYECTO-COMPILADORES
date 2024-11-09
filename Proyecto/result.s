.section .data

 .global x

 x: 
    .long 0

.section .text

 hola:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $64, %rsp 
    movl %edi, -16(%rbp)
    movl %esi, -32(%rbp)
    movl -16(%rbp), %eax
    movl -32(%rbp), %edx
    imull %edx, %eax
    movl %eax, -48(%rbp)
    movl -48(%rbp),  %eax
    addq $64, %rsp 
    popq    %rbp
    ret
extend:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $304, %rsp 
    movl %edi, -16(%rbp)
    movl %esi, -32(%rbp)
    movl %edx, -48(%rbp)
    movl %ecx, -64(%rbp)
    movl %r8d, -80(%rbp)
    movl %r9d, -96(%rbp)
    movl -96(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -112(%rbp)
    movl -16(%rbp) , %eax
    cmpl -32(%rbp) , %eax
    setg %al
    movzbl %al, %eax
    movl  %eax, -160(%rbp)
    movl -32(%rbp) , %eax
    cmpl -48(%rbp) , %eax
    setg %al
    movzbl %al, %eax
    movl  %eax, -176(%rbp)
    cmpl $0, -160(%rbp)
    je .LA1 
    cmpl $0, -176(%rbp)
    je .LA1 
    movl $1, %eax
    jmp .LA2 
.LA1: 
    movl $0, %eax
.LA2: 
    movl %eax, -144(%rbp)
    movl -64(%rbp) , %eax
    cmpl  $0 , %eax 
    sete %al
    movzbl %al, %eax
    movl  %eax, -192(%rbp)
    cmpl $0, -144(%rbp)
    jne .LO3 
    cmpl $0, -192(%rbp)
    je .LO4 
.LO3: 
    movl $1, %eax
    jmp .LO5 
.LO4: 
    movl $0, %eax
.LO5: 
    movl %eax, -128(%rbp)
    cmpl  $1,  -128(%rbp)
    jne L1
    movl $10000, %edi
    call printAdvanced
    movl %eax, -208(%rbp)


L1: 
    cmpl  $1,  -80(%rbp)
    jne L2
    movl -16(%rbp), %eax
    movl -32(%rbp), %edx
    addl %edx, %eax
    movl %eax, -224(%rbp)
    movl -224(%rbp), %eax

    movl %eax, -48(%rbp)

    movl -48(%rbp), %eax
    movl -48(%rbp), %edx
    addl %edx, %eax
    movl %eax, -240(%rbp)
    movl -240(%rbp), %eax

    movl %eax, -64(%rbp)

    jmp L3


L2: 
    movl -16(%rbp), %eax
    movl -32(%rbp), %edx
    subl %edx, %eax
    movl %eax, -256(%rbp)
    movl -256(%rbp), %eax

    movl %eax, -48(%rbp)

    movl -48(%rbp), %eax
    movl -48(%rbp), %edx
    imull %edx, %eax
    movl %eax, -272(%rbp)
    movl -272(%rbp), %eax

    movl %eax, -64(%rbp)



L3: 
    movl -64(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -288(%rbp)
    addq $304, %rsp 
    popq    %rbp
    ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $144, %rsp 
    movl $11, -32(%rbp)
    movl $10, -16(%rbp)
    movl $10, -48(%rbp)
    movl $10, -64(%rbp)
    movl -32(%rbp) , %eax
    cmpl -16(%rbp) , %eax
    sete %al
    movzbl %al, %eax
    movl  %eax, -112(%rbp)
    movl -32(%rbp), %eax
    movl %eax, %edi
    movl -16(%rbp), %eax
    movl %eax, %esi
    call hola
    movl %eax, -128(%rbp)
    movl -32(%rbp), %eax
    movl %eax, %edi
    movl -16(%rbp), %eax
    movl %eax, %esi
    movl -48(%rbp), %eax
    movl %eax, %edx
    movl $10, %ecx
    movl -112(%rbp), %eax
    movl %eax, %r8d
    movl -128(%rbp), %eax
    movl %eax, %r9d
    call extend
    movl %eax, -96(%rbp)
    movl -16(%rbp),  %eax
    addq $144, %rsp 
    popq    %rbp
    ret
