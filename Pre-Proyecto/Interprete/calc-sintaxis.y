%{

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AST.h"
void interprete(struct AST *arbol);  
struct AST* createTreeWhitSymbol(char * name,enum TYPES type,int size, int line, struct AST *l, struct AST *r);
extern int yylineno;
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

prog: TYPE_BOOL MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL  {char * name = "MAIN";interprete(createTreeWhitSymbol(name,RETBOL,1,yylineno,$6, $7));}
    | TYPE_INT MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL  {char * name = "MAIN";interprete(createTreeWhitSymbol(name,RETINT,1,yylineno,$6, $7));}
    | TYPE_VOID MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL {char * name = "MAIN";interprete(createTreeWhitSymbol(name,RETVOID,1,yylineno,$6, $7));}
    ;

/* type: TYPE_BOOL
    | TYPE_INT 
    | TYPE_VOID 
    ; */


/* main: type MAIN TPAR_OP TPAR_CL TLLAVE_OP list_declaraciones list_sentencias TLLAVE_CL
    ; */

list_declaraciones:                                 {$$ = NULL;}
                  |list_declaraciones declaracion   {char * name = "DECLARACION"; $$ = createTreeWhitSymbol(name,DECLA,1,yylineno,$1, $2);}
                  ;
list_sentencias:sentencia                           {$$ = $1;}
               |list_sentencias sentencia           {char * name = "SENTENCIA"; $$ = createTreeWhitSymbol(name,SENTEN,1,yylineno,$1, $2);}
               ;

sentencia: asignacion                               {$$ = $1;}
         | retorno                                  {$$ = $1;}
         ;

asignacion: ID ASIGNACION expr ';' {char * name = $1->varname;struct AST* aux3 = createTreeWhitSymbol(name,EID,1,yylineno,NULL, NULL);
                                    char * nameAsig = "asignacion";$$ = createTreeWhitSymbol(nameAsig,ASIG,1,yylineno,aux3, $3);}
          ;

declaracion: TYPE_INT ID ';' {char * name = $2->varname; $$ = createTreeWhitSymbol(name,VARINT,1,yylineno,NULL, NULL);}
           | TYPE_BOOL ID ';' {char * name = $2->varname;$$ = createTreeWhitSymbol(name,VARBOOL,1,yylineno,NULL, NULL);}
           /* | TYPE_INT ID ',' declaracion {char * nameId = $2->varname;struct Tsymbol* auxId = CreateSymbol(nameId,VARINT,1);AST* aux3 = createTree(auxId, NULL, NULL);
                                          char * name = "dec";struct Tsymbol* aux = CreateSymbol(name,DECLA,1); $$ = createTree(aux, aux3, $4);} */
           /* | TYPE_BOOL ID ',' declaracion {char * nameId = $2->varname;struct Tsymbol* auxId = CreateSymbol(nameId,VARBOOL,1);AST* aux3 = createTree(auxId, NULL, $4);
                                            char * name = "dec";struct Tsymbol* aux = CreateSymbol(name,DECLA,1); $$ = createTree(aux, aux3, $4);} */
           ;

expr: valor                     {$$ = $1;}
    | expr TMAS expr            {char * name = "+"; $$ = createTreeWhitSymbol(name,SUMA,1,yylineno,$1, $3);}
    | expr TPOR expr            {char * name = "*"; $$ = createTreeWhitSymbol(name,PROD,1,yylineno,$1, $3);}
    | TPAR_OP expr TPAR_CL      {$$ = $2;}
    | expr TMENOS expr          {char * name = "-"; $$ = createTreeWhitSymbol(name,RESTA,1,yylineno,$1, $3);}
    | expr AND expr             {char * name = "&&"; $$ = createTreeWhitSymbol(name,EAND,1,yylineno,$1, $3);}
    | expr OR expr              {char * name = "||"; $$ = createTreeWhitSymbol(name,EOR,1,yylineno,$1, $3);}
    | NOT expr                  {char * name = "!"; $$ = createTreeWhitSymbol(name,ENOT,1,yylineno,$2, NULL);}
    // ver eso, permite !100 lo permite porque true = 100
    ;

valor: INT                      {$$ = createTree($1, NULL, NULL);}
     | ID                       {$$ = createTree($1, NULL, NULL);}
     | TMENOS INT               {$$ = createTree($2, NULL, NULL);}
     | TTRUE                    {$$ = createTree($1, NULL, NULL);}
     | TFALSE                   {$$ = createTree($1, NULL, NULL);}


retorno: RETURN expr ';' {char * name = "return";$$ = createTreeWhitSymbol(name,ERETURN,1,yylineno,$2, NULL);}
       //| RETURN ';'      {char * name = "return";struct Tsymbol* aux = CreateSymbol(name,ERETURN,1,yylineno); $$ = createTree(aux, NULL, NULL);}
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

void interprete(struct AST* ar){
    createTable(ar);
    retError();
    typeError(ar);
    if(getError()) {
    elimArbol(ar);
       exit(1);
    }
    evaluate(ar);
    prinTable(); 
    printDot(ar,"Arbol.dot");
    elimArbol(ar);

}

struct AST* createTreeWhitSymbol(char * name,enum TYPES type,int size, int line, struct AST *l, struct AST *r){
    struct Tsymbol* aux = CreateSymbol(name,type,1,yylineno);
    return createTree(aux,l,r);
}

