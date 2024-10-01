%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/AST.h"

void interprete(struct AST *arbol);
struct AST* createTreeWhitSymbol(char * name,enum TYPES type,int size, int line, struct AST *l, struct AST *r);
extern int yylineno;
int blockNum = 0;
%}

%union {
    struct Tsymbol* symbol;
    struct AST *arbol;
}

/*declaraciones*/
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
%type <arbol> prog main retorno
%type <arbol> call_func expr
%type <arbol> asignacion valor argumento
%type <arbol> declaracion sentencia dec_parametro declare_funcion
%type <arbol> list_decls list_sents list_func parametros
%type <arbol> if_else while


%%

prog: PROGRAM TLLAVE_OP list_decls list_func main TLLAVE_CL  { char * name = "PROGRAM_BLOCK"; struct AST* aux= createTreeWhitSymbol(name,EPROGRAM,blockNum,yylineno,$4, $5);
                                                              char * name1 = "PROGRAM"; interprete(createTreeWhitSymbol(name1,OTHERS,blockNum,yylineno,$3, aux));}
    | PROGRAM TLLAVE_OP  main TLLAVE_CL  {char * name = "PROGRAM"; interprete(createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,NULL, $3));}
    | PROGRAM TLLAVE_OP  list_func main TLLAVE_CL  {char * name = "PROGRAM"; interprete(createTreeWhitSymbol(name,EPROGRAM,blockNum,yylineno,$3, $4));}
    | PROGRAM TLLAVE_OP list_decls  main TLLAVE_CL  {char * name = "PROGRAM"; interprete(createTreeWhitSymbol(name,EPROGRAM,blockNum,yylineno,$3, $4));}
    ;

main: TYPE_BOOL MAIN TPAR_OP TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  {blockNum += 1 ;char * name = "MAIN";$$ = createTreeWhitSymbol(name,RETBOL,blockNum-1,yylineno,$6, $7);}
    | TYPE_BOOL MAIN TPAR_OP TPAR_CL TLLAVE_OP list_sents TLLAVE_CL  {blockNum += 1 ;char * name = "MAIN";$$ = createTreeWhitSymbol(name,RETBOL,blockNum-1,yylineno,NULL, $6);}
    | TYPE_INT MAIN TPAR_OP TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  {blockNum += 1 ;char * name = "MAIN";$$ = createTreeWhitSymbol(name,RETINT,blockNum-1,yylineno,$6, $7);}
    | TYPE_INT MAIN TPAR_OP TPAR_CL TLLAVE_OP list_sents TLLAVE_CL  {blockNum += 1 ;char * name = "MAIN";$$ = createTreeWhitSymbol(name,RETINT,blockNum-1,yylineno,NULL, $6);}
    | TYPE_VOID MAIN TPAR_OP TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL {blockNum += 1 ;char * name = "MAIN";$$ = createTreeWhitSymbol(name,RETVOID,blockNum-1,yylineno,$6, $7);}
    | TYPE_VOID MAIN TPAR_OP TPAR_CL TLLAVE_OP list_sents TLLAVE_CL  {blockNum += 1 ;char * name = "MAIN";$$ = createTreeWhitSymbol(name,RETVOID,blockNum-1,yylineno,NULL, $6);}
    ;

list_decls: declaracion              {char * name = "DECLARACION"; $$ = createTreeWhitSymbol(name,DECLA,blockNum,yylineno,$1, NULL);}
          |list_decls declaracion   {char * name = "DECLARACION"; $$ = createTreeWhitSymbol(name,DECLA,blockNum,yylineno,$1, $2);}
          ;

list_sents:                                 {$$ = NULL;}
            |list_sents sentencia           {char * name = "SENTENCIA"; $$ = createTreeWhitSymbol(name,SENTEN,blockNum,yylineno,$1, $2);}
            ;

sentencia: asignacion                               {$$ = $1;}
         | retorno                                  {$$ = $1;}
         | if_else                                  {$$ = $1;}
         | while                                    {$$ = $1;}
         | call_func ';'                            {$$ = $1;}
         ;

asignacion: ID ASIGNACION expr ';' {char * name = $1->varname;struct AST* aux3 = createTreeWhitSymbol(name,EID,blockNum,yylineno,NULL, NULL);
                                    char * nameAsig = "asignacion";$$ = createTreeWhitSymbol(nameAsig,ASIG,1,yylineno,aux3, $3);}
          ;

call_func : ID TPAR_OP argumento TPAR_CL {char * name = $1->varname;struct AST* aux3 = createTreeWhitSymbol(name,EFUNC,blockNum,yylineno,NULL, NULL);
                                    char * nameCall = "LLAMADA_FUNC";$$ = createTreeWhitSymbol(nameCall,CALL_F,blockNum,yylineno,aux3, $3);}
          ;

declaracion: TYPE_INT ID ';'  {char * name = $2->varname; $$ = createTreeWhitSymbol(name,VARINT,blockNum,yylineno,NULL, NULL);}
           | TYPE_BOOL ID ';' {char * name = $2->varname;$$ = createTreeWhitSymbol(name,VARBOOL,blockNum,yylineno,NULL, NULL);}
           ;


argumento:                         {$$ = NULL;}
         | expr                    {$$ = $1;}
         | argumento ',' expr      {char * name = "arguments"; $$ = createTreeWhitSymbol(name,ARGS, blockNum, yylineno, $1, $3);}
         ;


parametros:                                 {$$ = NULL;}
          | dec_parametro                   {$$ = $1;}
          | dec_parametro ',' parametros    {char * name = "DECLARACION"; $$ = createTreeWhitSymbol(name,DECLA,blockNum,yylineno,$1, $3);}
          ;

dec_parametro : TYPE_INT ID  {char * name = $2->varname; $$ = createTreeWhitSymbol(name,PARAMINT,blockNum,yylineno,NULL, NULL);}
              | TYPE_BOOL ID  {char * name = $2->varname;$$ = createTreeWhitSymbol(name,PARAMBOOL,blockNum,yylineno,NULL, NULL);}
              ;



list_func:  declare_funcion                {char * name = "LIS_FUNCION";$$ = createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,$1, NULL);}                //modificar esto
         | list_func declare_funcion        {char * name = "LIS_FUNCION";$$ = createTreeWhitSymbol(name,OTHERS,blockNum,yylineno,$1, $2);}                //modificar esto
         ;

declare_funcion: TYPE_INT ID TPAR_OP parametros TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL   {char * nameAux = "BLOQUE_FUNC"; struct AST* aux = createTreeWhitSymbol(nameAux, EBLOQ, 1, yylineno, $7, $8);
                                                                                                     blockNum ++;char * name = $2->varname;$$ = createTreeWhitSymbol(name,RETINT,blockNum-1,yylineno,$4, aux);}
               |TYPE_INT ID TPAR_OP parametros TPAR_CL TLLAVE_OP  list_sents TLLAVE_CL   {char * nameAux = "BLOQUE_FUNC"; struct AST* aux = createTreeWhitSymbol(nameAux, EBLOQ, 1, yylineno, NULL, $7);
                                                                                                     blockNum ++;char * name = $2->varname;$$ = createTreeWhitSymbol(name,RETINT,blockNum-1,yylineno,$4, aux);}
               | TYPE_BOOL ID TPAR_OP parametros TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  {char * nameAux = "BLOQUE_FUNC"; struct AST* aux = createTreeWhitSymbol(nameAux, EBLOQ, 1, yylineno, $7, $8);
                                                                                                     blockNum ++;char * name = $2->varname;$$ = createTreeWhitSymbol(name,RETBOL,blockNum-1,yylineno,$4, aux);}
               | TYPE_BOOL ID TPAR_OP parametros TPAR_CL TLLAVE_OP  list_sents TLLAVE_CL  {char * nameAux = "BLOQUE_FUNC"; struct AST* aux = createTreeWhitSymbol(nameAux, EBLOQ, 1, yylineno, NULL, $7);
                                                                                                     blockNum ++;char * name = $2->varname;$$ = createTreeWhitSymbol(name,RETBOL,blockNum-1,yylineno,$4, aux);}
               | TYPE_VOID ID TPAR_OP parametros TPAR_CL TLLAVE_OP list_decls list_sents TLLAVE_CL  {char * nameAux = "BLOQUE_FUNC"; struct AST* aux = createTreeWhitSymbol(nameAux, EBLOQ, 1, yylineno, $7, $8);
                                                                                                     blockNum ++;char * name = $2->varname;$$ = createTreeWhitSymbol(name,RETVOID,blockNum-1,yylineno,$4, aux);}
               | TYPE_VOID ID TPAR_OP parametros TPAR_CL TLLAVE_OP  list_sents TLLAVE_CL  {char * nameAux = "BLOQUE_FUNC"; struct AST* aux = createTreeWhitSymbol(nameAux, EBLOQ, 1, yylineno, NULL, $7);
                                                                                                     blockNum ++;char * name = $2->varname;$$ = createTreeWhitSymbol(name,RETVOID,blockNum-1,yylineno,$4, aux);}
               | TYPE_INT ID TPAR_OP parametros TPAR_CL EXTERN ';'                                  {blockNum ++;char * name = $2->varname;$$ = createTreeWhitSymbol(name,RETINT,blockNum-1,yylineno,$4, NULL);}
               | TYPE_BOOL ID TPAR_OP parametros TPAR_CL EXTERN ';'                                 {blockNum ++;char * name = $2->varname;$$ = createTreeWhitSymbol(name,RETBOL,blockNum-1,yylineno,$4, NULL);}
               | TYPE_VOID ID TPAR_OP parametros TPAR_CL EXTERN ';'                                 {blockNum ++;char * name = $2->varname;$$ = createTreeWhitSymbol(name,RETVOID,blockNum-1,yylineno,$4, NULL);}
               ;


expr: valor                     {$$ = $1;}
    | call_func                 {$$ = $1;}
    | expr TMAS expr            {char * name = "+"; $$ = createTreeWhitSymbol(name,SUMA,blockNum,yylineno,$1, $3);}
    | expr TMENOS expr          {char * name = "-"; $$ = createTreeWhitSymbol(name,RESTA,blockNum,yylineno,$1, $3);}
    | expr TPOR expr            {char * name = "*"; $$ = createTreeWhitSymbol(name,PROD,blockNum,yylineno,$1, $3);}
    | expr TDIVISION expr       {char * name = "/"; $$ = createTreeWhitSymbol(name,EDIV,blockNum,yylineno,$1, $3);}
    | expr TRESTO expr          {char * name = "%"; $$ = createTreeWhitSymbol(name,ERESTO,blockNum,yylineno,$1, $3);}
    | expr MAYORQUE expr        {char * name = ">"; $$ = createTreeWhitSymbol(name,EMAYORQUE,blockNum,yylineno,$1, $3);}
    | expr MENORQUE expr        {char * name = "<"; $$ = createTreeWhitSymbol(name,EMENORQUE,blockNum,yylineno,$1, $3);}
    | expr EQ expr              {char * name = "=="; $$ = createTreeWhitSymbol(name,EEQ,blockNum,yylineno,$1, $3);}
    | expr AND expr             {char * name = "&&"; $$ = createTreeWhitSymbol(name,EAND,blockNum,yylineno,$1, $3);}
    | expr OR expr              {char * name = "||"; $$ = createTreeWhitSymbol(name,EOR,blockNum,yylineno,$1, $3);}
    | NOT expr                  {char * name = "!"; $$ = createTreeWhitSymbol(name,ENOT,blockNum,yylineno,$2, NULL);}
    | TPAR_OP expr TPAR_CL      {$$ = $2;}

    ;


valor: INT                      {$$ = createTree($1, NULL, NULL);}
     | ID                       {$$ = createTree($1, NULL, NULL);}
     | TMENOS INT               {$$ = createTree($2, NULL, NULL);}
     | TTRUE                    {$$ = createTree($1, NULL, NULL);}
     | TFALSE                   {$$ = createTree($1, NULL, NULL);}
     ;

retorno: RETURN expr ';' {char * name = "return";$$ = createTreeWhitSymbol(name,ERETURN,blockNum,yylineno,$2, NULL);}
       ;

/// chequear errores y evaluarlo
if_else: IF TPAR_OP expr TPAR_CL THEN TLLAVE_OP list_sents TLLAVE_CL {char * name = "if_then"; $$ = createTreeWhitSymbol(name,EIF,blockNum,yylineno,$3, $7);}
       | IF TPAR_OP expr TPAR_CL THEN TLLAVE_OP list_sents TLLAVE_CL ELSE TLLAVE_OP list_sents TLLAVE_CL { char * name = "then"; char * name2 = "else";
                                                                                                           struct AST* aux_else = createTreeWhitSymbol(name2,EELSE,blockNum,yylineno,$11, NULL);
                                                                                                           struct AST* aux_then = createTreeWhitSymbol(name,ETHEN,blockNum,yylineno,$7, aux_else);
                                                                                                           char * name3 = "if_else"; $$ = createTreeWhitSymbol(name3,EIF,blockNum,yylineno,$3, aux_then);}
       ;

while: WHILE TPAR_OP expr TPAR_CL TLLAVE_OP list_sents TLLAVE_CL {char * name = "while"; $$ = createTreeWhitSymbol(name,EWHILE,blockNum,yylineno,$3, $6);}
     ;

%%

void interprete(struct AST* ar){
    printDot(ar,"output/Arbol.dot");
    createTable(ar);
    /* prinTable(); */

    typeError(ar);
    retError();
    if(getError()) {
        elimArbol(ar);
       exit(1);
    }

    //evaluate(ar);
    prinTable();
    elimArbol(ar);
}

struct AST* createTreeWhitSymbol(char * name,enum TYPES type,int size, int line, struct AST *l, struct AST *r){
    struct Tsymbol* aux = CreateSymbol(name,type,size,yylineno);
    return createTree(aux,l,r);
}

