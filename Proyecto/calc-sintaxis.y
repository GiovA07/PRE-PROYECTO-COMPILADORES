%{

#include <stdlib.h>
#include <stdio.h>

%}

/*declaraciones*/
%token ID
%token CONSTANTE


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
%left TMAS TMENOS
%left TPOR
%left OR
%left AND
%left NOT
%left TPAR_OP TPAR_CL
%left TLLAVE_OP
%left TLLAVE_CL




%%

prog: main  { printf("No hay errores \n"); }
    ;

type: TYPE_BOOL
    | TYPE_INT
    | TYPE_VOID
    ;


main: constante type MAIN TPAR_OP TPAR_CL TLLAVE_OP list_sentencias TLLAVE_CL
    ;

constante:
         |constante CONSTANTE asignacion
         ;

list_sentencias:
          |list_sentencias sentencia
          ;

sentencia: asignacion
         | declaracion
         | while
         | if_else
         | retorno
         ;
         
int_Asignacion: ID ASIGNACION expr ';'
              | ID ASIGNACION TMENOS expr ';'
              | ID ASIGNACION expr ',' int_Asignacion
              | ID ASIGNACION TMENOS expr ',' int_Asignacion
              ;

bool_Asignacion: ID ASIGNACION expr_bool ';'
              | ID ASIGNACION expr_bool ',' bool_Asignacion
              ;
    
asignacion: bool_Asignacion
          | int_Asignacion
          ;

declaracion: TYPE_INT ID ';'
           | TYPE_BOOL ID ';'
           | TYPE_BOOL asignacion
           | TYPE_INT asignacion
           ;

expr_bool: TTRUE
         | TFALSE
         | expr_bool AND expr_bool
         | expr_bool OR expr_bool
         | NOT expr_bool
         ;

expr: ID
    | INT
    | expr TMAS expr
    | expr TPOR expr
    | expr TMENOS expr
    | TPAR_OP TMENOS INT TPAR_CL
    ;

retorno: RETURN expr_bool ';'
       | RETURN expr ';'
       | RETURN ';'
       ;

if_else: IF TPAR_OP expr_bool TPAR_CL TLLAVE_OP list_sentencias TLLAVE_CL
       | IF TPAR_OP expr_bool TPAR_CL TLLAVE_OP list_sentencias TLLAVE_CL ELSE TLLAVE_OP list_sentencias TLLAVE_CL
       ;

while: WHILE TPAR_OP expr_bool TPAR_CL TLLAVE_OP list_sentencias TLLAVE_CL
     ;


%%


