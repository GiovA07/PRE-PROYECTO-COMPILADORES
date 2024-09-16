%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol.h"
#include "AST.h"
#include "calc-sintaxis.tab.h"

int yyparse();

void current_token(enum TYPES type_sym);

%}

%option noyywrap
%option yylineno

letra [a-zA-Z]
digito [0-9]

%%

"int"                       { return TYPE_INT;  } /** [int => integer] **/
"void"                      { return TYPE_VOID; }
"bool"                      { return TYPE_BOOL; }

"@define"                   { return CONSTANTE; }

"extern"         			{ printf("%s\n",yytext);   return EXTERN; }
"program"                   { printf("%s\n", yytext); return PROGRAM; }

"main"						{ return MAIN; }
"return"                    { return RETURN; }

"if"         				{ printf("%s\n",yytext);   return IF;   }
"then"                      { printf("%s\n",yytext);   return THEN; }
"else"       				{ printf("%s\n",yytext);   return ELSE; }

"while"                 	{ printf("%s\n",yytext);   return WHILE; }

"true"						{ current_token(CONSBOOL); return TTRUE;  }
"false"						{ current_token(CONSBOOL); return TFALSE; }

{digito}+     				{ current_token(CONSINT); return INT; }

{letra}({letra}|{digito})*  { yylval.symbol = CreateSymbol(strdup(yytext),EID,1,yylineno); return ID; }

"||"                        { return OR;  }
"&&"                        { return AND; }
"!"                   		{ return NOT; }

"="                         { return ASIGNACION; }
"-"                         { return TMENOS;     }
"+"                         { return TMAS;       }
"*"                         { return TPOR;       }

"("                         { return TPAR_OP;   }
")"                         { return TPAR_CL;   }
"{"                         { return TLLAVE_OP; }
"}"                         { return TLLAVE_CL; }

"//".*						/** Comentario de linea **/
"/*"([^*]|[*][^/])*"*/"  	/**  Comentario bloque  **/


[;,]                        { return *yytext; }

.|\n                      ; /** ignore all the rest **/

%%

void current_token(enum TYPES type_sym) {
	yylval.symbol = CreateSymbol(strdup(yytext),type_sym,1,yylineno);
	if (type_sym == CONSINT)
		setValue(yylval.symbol, atoi(yytext));
	else
		setValue(yylval.symbol, 1);
}

void yyerror(){
	 printf("%s%d\n","-> ERROR Sintactico en la linea: ",yylineno);
}

int main(int argc,char *argv[]){
	++argv,--argc;
	if (argc > 0)
		yyin = fopen(argv[0],"r");
	else
		yyin = stdin;

	yyparse();

}
