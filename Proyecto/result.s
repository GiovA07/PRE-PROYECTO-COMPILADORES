.section .data

 .global z

 z: 
    .long 0

.section .data

 .global x

 x: 
    .long 0

.section .text

 get_num:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $64, %rsp 
    movl %edi, -16(%rbp)
    movl -32(%rbp), %eax
    movl -16(%rbp), %edx
    addl %edx, %eax
    movl %eax, -48(%rbp)
    movl -48(%rbp),  %eax
    addq $64, %rsp 
    popq    %rbp
    ret
get_bool:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $80, %rsp 
    movl %edi, -16(%rbp)
    movl %esi, -32(%rbp)
    movl %edx, -48(%rbp)
    movl %ecx, -64(%rbp)
    movl $1, x(%rip)
    movl $0, x(%rip)
    movl $1,  %eax
    addq $80, %rsp 
    popq    %rbp
    ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $128, %rsp 
    movl $10, -16(%rbp)
    movl $-5, -32(%rbp)


L1: 
    movl -32(%rbp) , %eax
    cmpl  $10 , %eax 
    setl %al
    movzbl %al, %eax
    movl  %eax, -64(%rbp)
    movl -16(%rbp) , %eax
    cmpl  $10 , %eax 
    sete %al
    movzbl %al, %eax
    movl  %eax, -80(%rbp)
    cmpl $0, -64(%rbp)
    je .LA1 
    cmpl $0, -80(%rbp)
    je .LA1 
    movl $1, %eax
    jmp .LA2 
.LA1: 
    movl $0, %eax
.LA2: 
    movl %eax, -48(%rbp)
    cmpl  $1,  -48(%rbp)
    jne L2
    movl -32(%rbp), %eax
    movl %eax, %edi
    call prinInt
    movl %eax, -96(%rbp)
    movl -32(%rbp), %eax
    movl $1, %edx
    addl %edx, %eax
    movl %eax, -112(%rbp)
    movl -112(%rbp), %eax

    movl %eax, -32(%rbp)

    jmp L1


L2: 
    movl $0,  %eax
    addq $128, %rsp 
    popq    %rbp
    ret
