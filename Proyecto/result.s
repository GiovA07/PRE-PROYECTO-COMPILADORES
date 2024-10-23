MAIN:
    pushq   %rbp
    movq    %rsp, %rbp
    comb $0, $(null)
    je .LO0 
    comb $0, $(null)
    je .LO1 
.LO1: 
    movl $1, %%eax
    jmp .LO3 
.LO3: 
    movl $0, %%eax
.LO4: 
    movb %%al, 0(%%rbp) 
     movb %%al, -2(%%rbp)
     andb $1, -2(%%rbp)
     movl -2(%%rbp), %%eax
    ;PRINCIPIO ASIGN
    movl -16(%rbp), %eax

    movl %eax, -12(%rbp)

    ;FINAL ASIGN
    movl -8(%rbp) , %eax
    cmpl -8(%rbp) , %eax
    sete %al
    movzbl %al, %eax
    movl  %eax -24(%rbp)
    movl -24(%rbp) , %eax
    cmpl -12(%rbp) , %eax
    sete %al
    movzbl %al, %eax
    movl  %eax -20(%rbp)
    ;PRINCIPIO ASIGN
    movl -20(%rbp), %eax

    movl %eax, -12(%rbp)

    ;FINAL ASIGN
    ;PRINCIPIO ASIGN
    movl $1, -4(%rbp)
    ;FINAL ASIGN
    ;PRINCIPIO ASIGN
    movl $1, -8(%rbp)
    ;FINAL ASIGN
    movl %eax, -4(%rbp)
    popq    %rbp
    ret
