@echo off
flex -o .\default\lexer.c .\syntax\TDS24_lexico.l

bison -d .\syntax\TDS24_sintaxis.y -o .\default\syntax_tab.c

gcc -o c-tds .\default\*.c .\src\*.c

@echo on