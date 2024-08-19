%{

#include <stdlib.h>
#include <stdio.h>

%}

%token INT
%token ID
%token TMENOS
%token BOOLEAN
%token TYPE_INT
%token TYPE_BOOL
%token TYPE_VOID
%token ASIGNACION
%token RETURN

%left '+' TMENOS
%left '*'
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
    | expr '+' expr

    | expr '*' expr

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


