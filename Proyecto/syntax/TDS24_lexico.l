%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/AST.h"
#include "../default/syntax_tab.h"

int yyparse();

void current_token(enum TYPES type_sym);

%}

%option noyywrap
%option yylineno

letra [a-zA-Z_]
digito [0-9]

%%

"extern"         			{ return EXTERN; }
"Program"                   { return PROGRAM; }
"main"						{ return MAIN; }
"return"                    { return RETURN; }

"if"         				{ return IF;   }
"then"                      { return THEN; }
"else"       				{ return ELSE; }
"while"                 	{ return WHILE; }



"void"                      { return TYPE_VOID; }
"int"                       { return TYPE_INT;  } /** [int => integer] **/
"bool"                      { return TYPE_BOOL; }
"true"						{ current_token(CONSBOOL); return TTRUE;  }
"false"						{ current_token(CONSBOOL); return TFALSE; }


{digito}+     				{ current_token(CONSINT); return INT; }

{letra}({letra}|{digito})*  { yylval.symbol = CreateSymbol(strdup(yytext),EID,1,yylineno); return ID; }


"||"                        { return OR;  }
"&&"                        { return AND; }
"!"                   		{ return NOT; }
"=="                   		{ return EQ;  }
">"                   		{ return MAYORQUE; }
"<"                   		{ return MENORQUE; }


"="                         { return ASIGNACION; }
"-"                         { return TMENOS;     }
"+"                         { return TMAS;       }
"*"                         { return TPOR;       }
"/"                         { return TDIVISION;  }
"%"                         { return TRESTO;     }

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
		if(strcmp("true",strdup(yytext)) == 0){
			setValue(yylval.symbol, 1);
		}else {
			setValue(yylval.symbol, 0);
		}
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
