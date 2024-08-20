%{

#include <stdlib.h>
#include <stdio.h>

%}

/*declaraciones*/
%token ID
%token CONSTANTE

/* tipos de datos */
%token INT
%token BOOLEAN
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
/* %token IF
%token ELSE */
%token RETURN


/* presedencias */
%left TMAS TMENOS
%left TPOR
%left TPAR_OP TPAR_CL
%left TLLAVE_OP
%left TLLAVE_CL
%left OR
%left AND
%left NOT


%%

prog: main  { printf("No hay errores \n"); }
    ;


type: TYPE_BOOL
    | TYPE_INT
    | TYPE_VOID


main: constante type ID TPAR_OP TPAR_CL TLLAVE_OP sentencias TLLAVE_CL

constante:
         |constante CONSTANTE asignacion

sentencias:
          |sentencias asignacion retorno
          |sentencias declaracion retorno
          ;



asignacion: boolAsignacion
          | intAsignacion
          ;

intAsignacion: ID ASIGNACION expr ';'
             | ID ASIGNACION expr ',' asignacion
             ;

boolAsignacion: ID ASIGNACION exprBool ';'
              | ID ASIGNACION exprBool ',' asignacion
              ;

declaracion: TYPE_INT ID ';'
           | TYPE_BOOL ID ';'
           | TYPE_BOOL asignacion
           | TYPE_INT asignacion
           ;


exprBool: BOOLEAN
        | exprBool AND exprBool
        | exprBool OR exprBool
        | NOT exprBool

expr: INT
    | ID
    | expr TMAS expr
    | expr TPOR expr
    | expr TMENOS expr
    | '(' expr ')'
    ;

retorno:
       | RETURN exprBool ';'
       | RETURN expr ';'
       | RETURN ';'
       ;

/*VALOR : INT
       | BOOLEAN
       ;

*/
%%


