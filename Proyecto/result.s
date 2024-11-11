.section .data

 .global ss

 ss: 
    .long 0

.section .data

 .global x

 x: 
    .long 0

.section .text

 seisParam:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $544, %rsp 
    movl %edi, -16(%rbp)
    movl %esi, -32(%rbp)
    movl %edx, -48(%rbp)
    movl %ecx, -64(%rbp)
    movl %r8d, -80(%rbp)
    movl %r9d, -96(%rbp)
    movl  16(%rbp), %eax
    movl %eax, -160(%rbp)
    movl  32(%rbp), %eax
    movl %eax, -144(%rbp)
    movl  48(%rbp), %eax
    movl %eax, -128(%rbp)
    movl  64(%rbp), %eax
    movl %eax, -112(%rbp)
    cmpl $0, -32(%rbp)
    je .LA1 
    cmpl $0, -160(%rbp)
    je .LA1 
    movl $1, %eax
    jmp .LA2 
.LA1: 
    movl $0, %eax
.LA2: 
    movl %eax, -176(%rbp)
    cmpl  $1,  -176(%rbp)
    jne L1
    movl -16(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -192(%rbp)
    movl -48(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -208(%rbp)
    movl -64(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -224(%rbp)
    movl -80(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -240(%rbp)
    movl -96(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -256(%rbp)
    movl -112(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -272(%rbp)
    movl -128(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -288(%rbp)
    movl -144(%rbp), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -304(%rbp)
    movl -16(%rbp), %eax
    movl -48(%rbp), %edx
    addl %edx, %eax
    movl %eax, -416(%rbp)
    movl -416(%rbp), %eax
    movl -64(%rbp), %edx
    addl %edx, %eax
    movl %eax, -400(%rbp)
    movl -400(%rbp), %eax
    movl -80(%rbp), %edx
    addl %edx, %eax
    movl %eax, -384(%rbp)
    movl -384(%rbp), %eax
    movl -96(%rbp), %edx
    addl %edx, %eax
    movl %eax, -368(%rbp)
    movl -368(%rbp), %eax
    movl -112(%rbp), %edx
    addl %edx, %eax
    movl %eax, -352(%rbp)
    movl -352(%rbp), %eax
    movl -128(%rbp), %edx
    addl %edx, %eax
    movl %eax, -336(%rbp)
    movl -336(%rbp), %eax
    movl -144(%rbp), %edx
    addl %edx, %eax
    movl %eax, -320(%rbp)
    movl -320(%rbp),  %eax
    jmp L2


L1: 
    movl -16(%rbp), %eax
    movl -48(%rbp), %edx
    addl %edx, %eax
    movl %eax, -528(%rbp)
    movl -528(%rbp), %eax
    movl -64(%rbp), %edx
    addl %edx, %eax
    movl %eax, -512(%rbp)
    movl -512(%rbp), %eax
    movl -80(%rbp), %edx
    addl %edx, %eax
    movl %eax, -496(%rbp)
    movl -496(%rbp), %eax
    movl -96(%rbp), %edx
    addl %edx, %eax
    movl %eax, -480(%rbp)
    movl -480(%rbp), %eax
    movl -112(%rbp), %edx
    addl %edx, %eax
    movl %eax, -464(%rbp)
    movl -464(%rbp), %eax
    movl -128(%rbp), %edx
    addl %edx, %eax
    movl %eax, -448(%rbp)
    movl -448(%rbp), %eax
    movl $0, %edx
    imull %edx, %eax
    movl %eax, -432(%rbp)
    movl -432(%rbp),  %eax


L2: 
    addq $544, %rsp 
    popq    %rbp
    ret

.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    subq $96, %rsp 
    movl $7, x(%rip)
    movl $1, ss(%rip)
    cmpl $0, ss(%rip)
    je .LA3 
    movl $1, %eax
    cmpl $0, %eax
    je .LA3 
    movl $1, %eax
    jmp .LA4 
.LA3: 
    movl $0, %eax
.LA4: 
    movl %eax, -64(%rbp)
    cmpl $0, ss(%rip)
    je .LA5 
    movl $1, %eax
    cmpl $0, %eax
    je .LA5 
    movl $1, %eax
    jmp .LA6 
.LA5: 
    movl $0, %eax
.LA6: 
    movl %eax, -64(%rbp)
    cmpl $0, -64(%rbp)
    jne .LO7 
    movl $0, %eax
    cmpl $0, %eax
    je .LO8 
.LO7: 
    movl $1, %eax
    jmp .LO9 
.LO8: 
    movl $0, %eax
.LO9: 
    movl %eax, -48(%rbp)
    movl $1, %edi
    movl $1, %esi
    movl $3, %edx
    movl $4, %ecx
    movl $5, %r8d
    movl $6, %r9d
    subq $8, %rsp
    pushq $2
    subq $8, %rsp
    pushq $9
    subq $8, %rsp
    pushq $10
    subq $8, %rsp
    pushq -48(%rbp)
    call seisParam
    addq $64,  %rsp
    movl %eax, -32(%rbp)
    movl -32(%rbp), %eax

    movl %eax, x(%rip)

    movl x(%rip), %eax
    movl %eax, %edi
    call printAdvanced
    movl %eax, -80(%rbp)
    movl x(%rip),  %eax
    addq $96, %rsp 
    popq    %rbp
    ret
