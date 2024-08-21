%{

#include <stdlib.h>
#include <stdio.h>

%}

/*declaraciones*/
/* %token CONSTANTE */
%token ID

/* tipos de datos */
%token INT
%token TYPE_INT
%token TYPE_BOOL
%token TYPE_VOID

/* simbolos */
%token TMAS
%token TPOR
%token TMENOS
%token ASIGNACION
%token TPAR_OP
%token TPAR_CL
%token TLLAVE_OP
%token TLLAVE_CL
%token OR
%token AND
%token NOT


/* palabras reservadas */
%token IF
%token ELSE
%token WHILE
%token RETURN
%token TTRUE
%token TFALSE
%token MAIN


/* presedencias */
%left TPAR_CL
%left TMAS TMENOS
%left TPOR
%left OR
%left AND
%left NOT
%left TLLAVE_OP TLLAVE_CL
%left TPAR_OP


%%

prog: main  { printf("No hay errores \n"); }
    ;

type: TYPE_BOOL
    | TYPE_INT
    | TYPE_VOID
    ;


main: type MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL
    ;

list_declaraciones:
                  |list_declaraciones declaracion
                  ;

list_sentencias:
               |list_sentencias sentencia
               ;

sentencia: asignacion
         | retorno
         ;

asignacion: ID ASIGNACION expr ';'
          ;

declaracion: TYPE_INT ID ';'
           | TYPE_BOOL ID ';'
           | TYPE_INT ID ',' declaracion
           | TYPE_BOOL ID ',' declaracion
           ;

expr: valor
    | expr TMAS expr
    | expr TPOR expr
    | TPAR_OP expr TPAR_CL
    | expr TMENOS expr
    | expr AND expr
    | expr OR expr
    | NOT expr
    ;

valor: INT
     | ID
     | TTRUE
     | TFALSE

retorno: RETURN expr ';'
       | RETURN ';'
       ;



/* constante:
         |constante CONSTANTE asignacion
         ; */

/* if_else: IF TPAR_OP expr_bool TPAR_CL TLLAVE_OP list_sentencias TLLAVE_CL
       | IF TPAR_OP expr_bool TPAR_CL TLLAVE_OP list_sentencias TLLAVE_CL ELSE TLLAVE_OP list_sentencias TLLAVE_CL
       ;

while: WHILE TPAR_OP expr_bool TPAR_CL TLLAVE_OP list_sentencias TLLAVE_CL
     ; */


%%


