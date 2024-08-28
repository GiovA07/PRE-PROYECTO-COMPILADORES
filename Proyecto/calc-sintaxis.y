%{

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AST.h"



%}
%union {
    char* id;
    int i;
    int bolean;
    struct AST *arbol;
}

/*declaraciones*/
%token CONSTANTE
%token <id> ID

/* tipos de datos */
%token <i> INT
%token <bolean>TTRUE
%token <bolean>TFALSE
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

/*Types*/
%type <arbol> prog expr asignacion retorno valor list_declaraciones declaracion sentencia list_sentencias


%%

prog: type MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL  { $$ = createTree(MAIN, "main pro", $6, $7); showTree($$);}
    ;

type: TYPE_BOOL
    | TYPE_INT
    | TYPE_VOID
    ;


/* main: type MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL
    ; */

list_declaraciones:                                 {$$ = NULL;}
                  |list_declaraciones declaracion   {$$ = createTree(DECLA, "DECLARACION", $1, $2);}
                  ;

list_sentencias:sentencia                           {$$ = $1;}
               |list_sentencias sentencia           {$$ = createTree(SENTEN, "SENTENCIA", $1, $2);}
               ;

sentencia: asignacion                               {$$ = $1;}
         | retorno                                  {$$ = $1;}
         ;

asignacion: ID ASIGNACION expr ';' {$$ = createTree(ASIG, "asignacion", $1, $3);}
          ;

declaracion: TYPE_INT ID ';'
           | TYPE_BOOL ID ';'
           | TYPE_INT ID ',' declaracion
           | TYPE_BOOL ID ',' declaracion
           ;

expr: valor                     {$$ = $1;}
    | expr TMAS expr            {$$ = createTree(SUMA, "+", $1, $3);}
    | expr TPOR expr            {$$ = createTree(PROD, "*", $1, $3);}
    | TPAR_OP expr TPAR_CL      {$$ = $2;}
    | expr TMENOS expr          {$$ = createTree(RESTA, "-", $1, $3);}
    | expr AND expr             {$$ = createTree(EAND, "&&", $1, $3);}
    | expr OR expr              {$$ = createTree(EOR, "||", $1, $3);}
    | NOT expr                  {$$ = createTree(ENOT, "!", NULL, $2);}
    ;

valor: INT                      {$$ = createTree(CONSINT, "int", NULL, NULL);}
     | ID                       {$$ = createTree(OTHERS, "ID", NULL, NULL);}
     | TMENOS INT               {$$ = createTree(CONSINT, "int", NULL, NULL);}
     | TTRUE                    {$$ = createTree(CONSBOOL, "TRUE", NULL, NULL);}
     | TFALSE                   {$$ = createTree(CONSBOOL, "FALSE", NULL, NULL);}

retorno: RETURN expr ';' {$$ = createTree(ERETURN, "return", $2, NULL);}
       | RETURN ';'      {$$ = createTree(ERETURN, "return", NULL, NULL);}
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


