%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "calc-sintaxis.tab.h"

%}

%option noyywrap
%option yylineno

letra [a-zA-Z]
digito [0-9]

%%
"@define"                   { printf("CONSTANTE "); return CONSTANTE; }
"main"						{ printf("MAIN "); return MAIN; }
"return"                    { printf("%s\n", yytext); return RETURN; }

"int"                       { printf("TIPO ENTERO "); return TYPE_INT; }
"bool"                      { printf("TIPO BOOLEANA "); return TYPE_BOOL; }
"void"                      { printf("%s\n", yytext); return TYPE_VOID; }

"if"         				{  printf("%s\n",yytext);   return IF;}
"else"       				{  printf("%s\n",yytext);   return ELSE;}

"while"                 	{  printf("%s\n",yytext);   return WHILE;}

"TRUE"						{ printf("%s\n", yytext); yylval.bolean = 1; return TTRUE;}
"FALSE"						{ printf("%s\n", yytext); yylval.bolean = 0; return TFALSE; }

{digito}+     				{ printf("INT : %d\n",atoi(yytext)); yylval.i= atoi(yytext);  return INT;}

{letra}({letra}|{digito})*  { printf("ID : %s\n",yytext); return ID; }

"||"                        {  printf(" OR ");;  return OR;}
"&&"                        {  printf(" AND ");  return AND;}
"NOT"|"!"                   {  printf(" NOT ");  return NOT;}

"="                         {  printf("%s\n", yytext); return ASIGNACION; }
"-"                         {  printf("%s\n",yytext);  return TMENOS;}
"+"                         {  printf("%s\n",yytext);  return TMAS;}
"*"                         {  printf("%s\n",yytext);  return TPOR;}

"("                         {  printf("%s\n",yytext);  return TPAR_OP;}
")"                         {  printf("%s\n",yytext);  return TPAR_CL;}
"{"                         {  printf("%s\n",yytext);  return TLLAVE_OP;}
"}"                         {  printf("%s\n",yytext);  return TLLAVE_CL;}


[;,]                        {  printf("%s\n",yytext);  return *yytext;}

.|\n                          ; /* ignore all the rest */

%%

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
