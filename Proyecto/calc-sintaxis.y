%{

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AST.h"

%}
%union {
    struct Tsymbol* symbol;
    struct AST *arbol;
}

/*declaraciones*/
%token CONSTANTE
%token <symbol> ID

/* tipos de datos */
%token <symbol> INT
%token <symbol>TTRUE
%token <symbol>TFALSE
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

prog: type MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL  {char * name = "MAIN";struct Tsymbol* aux = CreateSymbol(name,MAIN,1); 
                                                                                            struct AST* arbol = createTree(aux, $6, $7); printDot(arbol,"Arbol.dot");}
    ;

type: TYPE_BOOL
    | TYPE_INT
    | TYPE_VOID
    ;


/* main: type MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL
    ; */

list_declaraciones:                                 {$$ = NULL;}
                  |list_declaraciones declaracion   {char * name = "DECLARACION";struct Tsymbol* aux = CreateSymbol(name,DECLA,1); $$ = createTree(aux, $1, $2);}
                  ;

list_sentencias:sentencia                           {$$ = $1;}
               |list_sentencias sentencia           {char * name = "SENTENCIA";struct Tsymbol* aux = CreateSymbol(name,SENTEN,1); $$ = createTree(aux, $1, $2);}
               ;

sentencia: asignacion                               {$$ = $1;}
         | retorno                                  {$$ = $1;}
         ;

asignacion: ID ASIGNACION expr ';' {char * name = $1->varname;struct Tsymbol* aux = CreateSymbol(name,EID,1);struct AST* aux3 = createTree(aux, NULL, NULL); 
                                    char * nameAsig = "asignacion";struct Tsymbol* aux1 = CreateSymbol(nameAsig,ASIG,1);$$ = createTree(aux1, aux3, $3);}
          ;

declaracion: TYPE_INT ID ';' {char * nameId = $2->varname;struct Tsymbol* auxId = CreateSymbol(nameId,VARINT,1);$$ = createTree(auxId, NULL, NULL);}
           | TYPE_BOOL ID ';' {char * nameId = $2->varname;struct Tsymbol* auxId = CreateSymbol(nameId,VARBOOL,1);$$ = createTree(auxId, NULL, NULL);}
           | TYPE_INT ID ',' declaracion {char * nameId = $2->varname;struct Tsymbol* auxId = CreateSymbol(nameId,VARINT,1);AST* aux3 = createTree(auxId, NULL, NULL);
                                          char * name = "dec";struct Tsymbol* aux = CreateSymbol(name,DECLA,1); $$ = createTree(aux, aux3, $4);}
           | TYPE_BOOL ID ',' declaracion {char * nameId = $2->varname;struct Tsymbol* auxId = CreateSymbol(nameId,VARBOOL,1);AST* aux3 = createTree(auxId, NULL, $4);
                                            char * name = "dec";struct Tsymbol* aux = CreateSymbol(name,DECLA,1); $$ = createTree(aux, aux3, $4);}
           ;

expr: valor                     {$$ = $1;}
    | expr TMAS expr            {char * name = "+";struct Tsymbol* aux = CreateSymbol(name,SUMA,1); $$ = createTree(aux, $1, $3);}
    | expr TPOR expr            {char * name = "*";struct Tsymbol* aux = CreateSymbol(name,PROD,1); $$ = createTree(aux, $1, $3);}
    | TPAR_OP expr TPAR_CL      {$$ = $2;}
    | expr TMENOS expr          {char * name = "-";struct Tsymbol* aux = CreateSymbol(name,RESTA,1); $$ = createTree(aux,$1, $3);}
    | expr AND expr             {char * name = "&&";struct Tsymbol* aux = CreateSymbol(name,EAND,1); $$ = createTree(aux, $1, $3);}
    | expr OR expr              {char * name = "||";struct Tsymbol* aux = CreateSymbol(name,EOR,1); $$ = createTree(aux, $1, $3);}
    | NOT expr                  {char * name = "!";struct Tsymbol* aux = CreateSymbol(name,ENOT,1); $$ = createTree(aux, NULL, $2);}
    ;

valor: INT                      {$$ = createTree($1, NULL, NULL);}
     | ID                       {$$ = createTree($1, NULL, NULL);}
     | TMENOS INT               {$$ = createTree($2, NULL, NULL);}
     | TTRUE                    {$$ = createTree($1, NULL, NULL);}
     | TFALSE                   {$$ = createTree($1, NULL, NULL);}

retorno: RETURN expr ';' {char * name = "return";struct Tsymbol* aux = CreateSymbol(name,ERETURN,1); $$ = createTree(aux, $2, NULL);}
       | RETURN ';'      {char * name = "return";struct Tsymbol* aux = CreateSymbol(name,ERETURN,1); $$ = createTree(aux, NULL, NULL);}
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


