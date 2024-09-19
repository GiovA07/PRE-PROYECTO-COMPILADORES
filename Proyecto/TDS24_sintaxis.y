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
%token <symbol> TTRUE
%token <symbol> TFALSE
%token TYPE_INT
%token TYPE_BOOL
%token TYPE_VOID

/* simbolos */
%token TMAS
%token TPOR
%token TMENOS
%token TDIVISION
%token TRESTO
%token ASIGNACION
%token TPAR_OP
%token TPAR_CL
%token TLLAVE_OP
%token TLLAVE_CL
%token OR
%token AND
%token NOT
%token MAYORQUE
%token MENORQUE
%token EQ

/* palabras reservadas */
%token PROGRAM
%token EXTERN
%token THEN
%token IF
%token ELSE
%token WHILE
%token RETURN
%token MAIN


/* presedencias */
%left OR AND                // ||, &&
%left EQ                    // == 
%left MAYORQUE MENORQUE     // >, <
%left TMAS TMENOS           // +, -
%left TPOR TDIVISION TRESTO // *, /, %
%right NOT                  // La negación es asociativa a la derecha

/*Types*/
%type <arbol> prog expr asignacion retorno valor list_decls declaracion sentencia list_sents if_else while


%%

prog: TYPE_BOOL MAIN TPAR_OP TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  {char * name = "MAIN";interprete(createTreeWhitSymbol(name,RETBOL,1,yylineno,$6, $7));}
    | TYPE_INT MAIN TPAR_OP TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  {char * name = "MAIN";interprete(createTreeWhitSymbol(name,RETINT,1,yylineno,$6, $7));}
    | TYPE_VOID MAIN TPAR_OP TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL {char * name = "MAIN";interprete(createTreeWhitSymbol(name,RETVOID,1,yylineno,$6, $7));}
    ;

list_decls:                                 {$$ = NULL;}
                  |list_decls declaracion   {char * name = "DECLARACION"; $$ = createTreeWhitSymbol(name,DECLA,1,yylineno,$1, $2);}
                  ;
list_sents: sentencia                           {$$ = $1;}
                 |list_sents sentencia           {char * name = "SENTENCIA"; $$ = createTreeWhitSymbol(name,SENTEN,1,yylineno,$1, $2);}
               ;

sentencia: asignacion                               {$$ = $1;}
         | retorno                                  {$$ = $1;}
         | if_else                                  {$$ = $1;}
         | while                                    {$$ = $1;}
         ;

asignacion: ID ASIGNACION expr ';' {char * name = $1->varname;struct AST* aux3 = createTreeWhitSymbol(name,EID,1,yylineno,NULL, NULL);
                                    char * nameAsig = "asignacion";$$ = createTreeWhitSymbol(nameAsig,ASIG,1,yylineno,aux3, $3);}
          ;

declaracion: TYPE_INT ID ';' {char * name = $2->varname; $$ = createTreeWhitSymbol(name,VARINT,1,yylineno,NULL, NULL);}
           | TYPE_BOOL ID ';' {char * name = $2->varname;$$ = createTreeWhitSymbol(name,VARBOOL,1,yylineno,NULL, NULL);}
           ;

        

expr: valor                     {$$ = $1;}
    | NOT expr                  {char * name = "!"; $$ = createTreeWhitSymbol(name,ENOT,1,yylineno,$2, NULL);}
    | TPAR_OP expr TPAR_CL      {$$ = $2;}
    | expr TMAS expr            {char * name = "+"; $$ = createTreeWhitSymbol(name,SUMA,1,yylineno,$1, $3);}
    | expr TMENOS expr          {char * name = "-"; $$ = createTreeWhitSymbol(name,RESTA,1,yylineno,$1, $3);}
    | expr TPOR expr            {char * name = "*"; $$ = createTreeWhitSymbol(name,PROD,1,yylineno,$1, $3);}
    | expr TDIVISION expr       {char * name = "/"; $$ = createTreeWhitSymbol(name,EDIV,1,yylineno,$1, $3);}
    | expr TRESTO expr          {char * name = "%"; $$ = createTreeWhitSymbol(name,ERESTO,1,yylineno,$1, $3);}
    | expr MAYORQUE expr        {char * name = ">"; $$ = createTreeWhitSymbol(name,EMAYORQUE,1,yylineno,$1, $3);}
    | expr MENORQUE expr        {char * name = "<"; $$ = createTreeWhitSymbol(name,EMENORQUE,1,yylineno,$1, $3);}
    | expr EQ expr              {char * name = "=="; $$ = createTreeWhitSymbol(name,EEQ,1,yylineno,$1, $3);}
    | expr AND expr             {char * name = "&&"; $$ = createTreeWhitSymbol(name,EAND,1,yylineno,$1, $3);}
    | expr OR expr              {char * name = "||"; $$ = createTreeWhitSymbol(name,EOR,1,yylineno,$1, $3);}
    ;
       

valor: INT                      {$$ = createTree($1, NULL, NULL);}
     | ID                       {$$ = createTree($1, NULL, NULL);}
     | TMENOS INT               {$$ = createTree($2, NULL, NULL);}
     | TTRUE                    {$$ = createTree($1, NULL, NULL);}
     | TFALSE                   {$$ = createTree($1, NULL, NULL);}
     ;

retorno: RETURN expr ';' {char * name = "return";$$ = createTreeWhitSymbol(name,ERETURN,1,yylineno,$2, NULL);}
       ;

/// chequear errores y evaluarlo 
if_else: IF TPAR_OP expr TPAR_CL THEN TLLAVE_OP list_sents TLLAVE_CL {char * name = "if_then"; $$ = createTreeWhitSymbol(name,EIF,1,yylineno,$3, $7);}
       | IF TPAR_OP expr TPAR_CL THEN TLLAVE_OP list_sents TLLAVE_CL ELSE TLLAVE_OP list_sents TLLAVE_CL {char * name = "then"; char * name2 = "else"; 
                                                                                                            struct AST* aux_else = createTreeWhitSymbol(name2,EELSE,1,yylineno,$11, NULL);
                                                                                                            struct AST* aux_then = createTreeWhitSymbol(name,ETHEN,1,yylineno,$7, aux_else);
                                                                                                           char * name3 = "if_else"; $$ = createTreeWhitSymbol(name3,EIF,1,yylineno,$3, aux_then);}
       ;

while: WHILE TPAR_OP expr TPAR_CL TLLAVE_OP list_sents TLLAVE_CL {char * name = "while"; $$ = createTreeWhitSymbol(name,EWHILE,1,yylineno,$3, $6);}
     ;

%%

void interprete(struct AST* ar){
    createTable(ar);
    typeError(ar);
    retError();
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

