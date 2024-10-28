func_1:
    pushq   %rbp
    movq    %rsp, %rbp
mult:
    pushq   %rbp
    movq    %rsp, %rbp
     ;Cargando parametro
    movl %rdi, -8(%rbp)
     ;TERMINO CARGAR parametro
     ;Cargando parametro
    movl %rsi, -16(%rbp)
     ;TERMINO CARGAR parametro
    movl -8(%rbp), %edx
    movl -16(%rbp), %eax
    imull %edx, %eax
    movl %eax, -32(%rbp)
    movl %eax, -32(%rbp)
    popq    %rbp
    ret
llamadoFunc:
    pushq   %rbp
    movq    %rsp, %rbp
     ;Cargando parametro
    movl %rdi, -40(%rbp)
     ;TERMINO CARGAR parametro
     ;Cargando parametro
    movl %rsi, -48(%rbp)
     ;TERMINO CARGAR parametro
    movl -40(%rbp), %edx
    movl -48(%rbp), %eax
    imull %edx, %eax
    movl %eax, -64(%rbp)
    movl %eax, -64(%rbp)
    popq    %rbp
    ret
MAIN:
    pushq   %rbp
    movq    %rsp, %rbp
    ;CARGANDO PARAMETRO
    movl $5, %rdi
    ;FIN DEL CARGO DE PARAMETRO
    ;CARGANDO PARAMETRO
    movl $6, %rsi
    ;FIN DEL CARGO DE PARAMETRO
    call mult
    movl %eax, -80(%rbp)
    ;PRINCIPIO ASIGN
    movl -80(%rbp), %eax

    movl %eax, -72(%rbp)

    ;FINAL ASIGN
    ;CARGANDO PARAMETRO
    movl $9, %rdi
    ;FIN DEL CARGO DE PARAMETRO
    ;CARGANDO PARAMETRO
    movl $10, %rsi
    ;FIN DEL CARGO DE PARAMETRO
    call llamadoFunc
    movl %eax, -88(%rbp)
    ;PRINCIPIO ASIGN
    movl -88(%rbp), %eax

    movl %eax, -72(%rbp)

    ;FINAL ASIGN
    movl %eax, 0(%rbp)
    popq    %rbp
    ret
