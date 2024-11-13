.section .data

 .global res2

 res2: 
    .long 0

.section .text

 esPrimo:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $160, %rsp 
    movl %edi, -16(%rbp)
    movl -16(%%rbp) , %%eax
    cmpl  $1 , %%eax 
    setl %al
    movzbl %%al, %%eax
    movl  %%eax, -64(%%rbp)
    movl -16(%%rbp) , %%eax
    cmpl  $1 , %%eax 
    sete %al
    movzbl %%al, %%eax
    movl  %%eax, -80(%%rbp)
    cmpl $0, -64(%rbp)
    jne .LO1 
    cmpl $0, -80(%rbp)
    je .LO2 
.LO1: 
    movl $1, %eax
    jmp .LO3 
.LO2: 
    movl $0, %eax
.LO3: 
    movl %eax, -48(%rbp)
    cmpl  $1,  -48(%rbp)
    jne L1
    movl $0,  %eax
    addq $160, %rsp 
    popq    %rbp
    ret


L1: 
    movl $2, -32(%rbp)
    movl $1, res2(%rip)


L2: 
    movl -32(%%rbp) , %%eax
    cmpl -16(%%rbp) , %%eax
    setl %al
    movzbl %%al, %%eax
    movl  %%eax, -96(%%rbp)
    cmpl  $1,  -96(%rbp)
    jne L3
    movl -16(%%rbp), %%eax
    cltd
    idivl -32(%%rbp)
    movl %%edx, -128(%%rbp)
    movl -128(%%rbp) , %%eax
    cmpl  $0 , %%eax 
    sete %al
    movzbl %%al, %%eax
    movl  %%eax, -112(%%rbp)
    cmpl  $1,  -112(%rbp)
    jne L4
    movl $0,  %eax
    addq $160, %rsp 
    popq    %rbp
    ret


L4: 
    movl -32(%%rbp), %%eax
    movl $1, %%edx
    addl %edx, %eax
    movl %%eax, -144(%%rbp)
    movl -144(%rbp), %eax

    movl %eax, -32(%rbp)

    jmp L2


L3: 
    movl $1,  %eax
    addq $160, %rsp 
    popq    %rbp
    ret
funcionBolleana:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $96, %rsp 
    movl %edi, -16(%rbp)
    movl %esi, -32(%rbp)
    movl -16(%%rbp) , %%eax
    cmpl -32(%%rbp) , %%eax
    sete %al
    movzbl %%al, %%eax
    movl  %%eax, -64(%%rbp)
    cmpl  $1,  -64(%rbp)
    jne L5
    movl $0, -48(%rbp)
    jmp L6


L5: 
    movl $1, -48(%rbp)


L6: 
    cmpl $0, -48(%rbp)
    sete  %al
    movzbl  %al, %eax
    movl %eax, -80(%rbp)
    movl -80(%rbp),  %eax
    addq $96, %rsp 
    popq    %rbp
    ret
printVar:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $48, %rsp 
    movl %edi, -16(%rbp)
    movl -16(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -32(%rbp)
    addq $48, %rsp 
    popq    %rbp
    ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $160, %rsp 
    call inputVal
    movl %eax, -48(%rbp)
    movl -48(%rbp), %eax

    movl %eax, -16(%rbp)

    call inputVal
    movl %eax, -64(%rbp)
    movl -64(%rbp), %eax

    movl %eax, -32(%rbp)

    movl -16(%rbp), %eax
    movl %eax, %edi
    movl -32(%rbp), %eax
    movl %eax, %esi
    call funcionBolleana
    movl %eax, -80(%rbp)
    cmpl  $1,  -80(%rbp)
    jne L7
    movl $1, %edi
    call prinInt
    movl %eax, -96(%rbp)
    jmp L8


L7: 
    movl $0, %edi
    call prinInt
    movl %eax, -112(%rbp)


L8: 
    movl $1000000, %edi
    call printVar
    movl %eax, -128(%rbp)
    movl -16(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -144(%rbp)
    movl $1,  %eax
    addq $160, %rsp 
    popq    %rbp
    ret
