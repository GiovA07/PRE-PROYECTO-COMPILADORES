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
%type <arbol> prog expr asignacion retorno valor


%%

prog: type MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL  {  }
    ;

type: TYPE_BOOL
    | TYPE_INT
    | TYPE_VOID
    ;


/* main: type MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL
    ; */

list_declaraciones:
                  |list_declaraciones declaracion
                  ;

list_sentencias: sentencia
               |list_sentencias sentencia
               ;

sentencia: asignacion
         | retorno
         ;

asignacion: ID ASIGNACION expr ';' {$$ = createTree(OTHERS, "asignacion", $1, $3);}
          ;

declaracion: TYPE_INT ID ';'
           | TYPE_BOOL ID ';'
           | TYPE_INT ID ',' declaracion
           | TYPE_BOOL ID ',' declaracion
           ;

expr: valor                     {$$ = $1;}
    | expr TMAS expr            {$$ = createTree(OTHERS, "+", $1, $3);}
    | expr TPOR expr            {$$ = createTree(OTHERS, "*", $1, $3);}
    | TPAR_OP expr TPAR_CL      {$$ = $2;}
    | expr TMENOS expr          {$$ = createTree(OTHERS, "-", $1, $3);}
    | expr AND expr             {$$ = createTree(OTHERS, "&&", $1, $3);}
    | expr OR expr              {$$ = createTree(OTHERS, "||", $1, $3);}
    | NOT expr                  {$$ = createTree(OTHERS, "!", NULL, $2);}
    ;

valor: INT                      {$$ = createTree($1, NULL, NULL, NULL);}
     | ID                       {$$ = createTree($1, NULL, NULL, NULL);}
     | TMENOS INT               {$$ = createTree($2, NULL, NULL, NULL);}
     | TTRUE                    {$$ = createTree($1, NULL, NULL, NULL);}
     | TFALSE                   {$$ = createTree($1, NULL, NULL, NULL);}

retorno: RETURN expr ';' {$$ = createTree(FUNC, "return", $2, NULL);}
       | RETURN ';'      {$$ = createTree(FUNC, "return", NULL, NULL);}
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


