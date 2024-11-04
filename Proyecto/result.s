get_num:
    pushq   %rbp
    movq    %rsp, %rbp
    movl %edi, -8(%rbp)
    movl -16(%rbp), %edx
    movl -8(%rbp), %eax
    addl %edx, %eax
    movl %eax, -24(%rbp)
    movl %eax, -24(%rbp)
    popq    %rbp
    ret
get_bool:
    pushq   %rbp
    movq    %rsp, %rbp
    movl %edi, -32(%rbp)
    movl %esi, -40(%rbp)
    movl %edx, -48(%rbp)
    movl %ecx, -56(%rbp)
    movl $1, 0(%rbp)
    movl $0, 0(%rbp)
    movl %eax, 0(%rbp)
    popq    %rbp
    ret
.global main
 main:
    pushq   %rbp
    movq    %rsp, %rbp
    movl $1, -64(%rbp)
    cmpl  $1,  -64(rbp)
    jne L1
    movl $1, -72(%rbp)
    movl $0, -80(%rbp)
    jmp L2


L1: 
    movl $1, -80(%rbp)
    movl $0, -72(%rbp)


L2: 
    movl $5, %edi
    call get_num
    movl %eax, -104(%rbp)
    movl -64(%rbp), %eax
    movl %eax, %edi
    movl -72(%rbp), %eax
    movl %eax, %esi
    movl -80(%rbp), %eax
    movl %eax, %edx
    call get_bool
    movl %eax, -96(%rbp)
    movl -96(%rbp), %eax

    movl %eax, -88(%rbp)



L3: 
    cmpl  $1,  0(rbp)
    jne L4
    movl -88(%rbp), %edx
    movl $1, %eax
    addl %edx, %eax
    movl %eax, -112(%rbp)
    movl -112(%rbp), %eax

    movl %eax, -88(%rbp)

    jmp L3


L4: 
    movl %eax, 0(%rbp)
    popq    %rbp
    ret
