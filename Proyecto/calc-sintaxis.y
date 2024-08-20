%{

#include <stdlib.h>
#include <stdio.h>

%}

%token ID
%token INT
%token TMAS
%token TPOR
%token TMENOS
%token BOOLEAN
%token TYPE_INT
%token TYPE_BOOL
%token TYPE_VOID
%token ASIGNACION
%token RETURN
%token CONSTANTE

%left TMAS TMENOS
%left TPOR
%left ')' '('
%left '{'
%left '}'


%%

prog: main  { printf("No hay errores \n"); }
    ;


type: TYPE_BOOL
    |TYPE_INT
    |TYPE_VOID


main: constante type ID '(' ')' '{' sentencias '}'

constante: 
            |constante CONSTANTE asignacion

sentencias:
            |sentencias asignacion retorno
            |sentencias declaracion retorno
    ;



asignacion: ID ASIGNACION expr ';'
          | ID ASIGNACION exprBool ';' 
          ;

declaracion: TYPE_INT ID ';'
           | TYPE_BOOL ID ';'
           | TYPE_BOOL asignacion
           | TYPE_INT asignacion
           ;

exprBool: BOOLEAN 
        


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


