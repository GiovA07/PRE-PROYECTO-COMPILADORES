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


main: type ID '(' ')' '{' sentencias '}'


sentencias:
            |sentencias asignacion retorno
            |sentencias declaracion retorno
    ;

asignacion: ID ASIGNACION expr ';'

declaracion: TYPE_INT ID ';'
           | TYPE_BOOL ID ';'
           ;

expr: VALOR
    | ID
    | expr TMAS expr

    | expr TPOR expr

    | expr TMENOS expr

    | '(' expr ')'
    ;

retorno:
        | RETURN expr ';'
        | RETURN ';'
        ;

VALOR : INT
       | BOOLEAN
       ;

%%


