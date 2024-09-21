#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef SYMBOL_H
#define SYMBOL_H

enum TYPES {
    VAR,
    EMAIN,
    VARINT,
    VARBOOL,
    CONSINT,
    CONSBOOL,
    SUMA,
    RESTA,
    PROD,
    EDIV,
    ERESTO,
    EOR,
    EAND,
    ENOT,
    ASIG,
    DECLA,
    SENTEN,
    EID,
    ERETURN,
    RETINT,
    RETBOL,
    RETVOID,
    EIF,
    ETHEN,
    EELSE,
    EWHILE,
    EMAYORQUE,
    EMENORQUE,
    EEQ,
    EFUNC,
    EFUNCEXTERN,
    EPROGRAM,
};

char static string[22][23] = {"VAR","EMAIN","VARINT","VARBOOL","CONSINT","CONSBOOL","SUMA","RESTA","PROD","EOR","EAND","ENOT","ASIG","DECLA","SENTEN","EID","ERETURN","RETINT","RETBOL","RETVOID","OTHERS"};


typedef struct Tsymbol {
    int id;
    enum TYPES type;
    char* varname;       // name of the variable
    int size;         // size of the type of the variable
    struct Tsymbol *next;
    int line;
    int value;
} Tsymbol;

struct Tsymbol *Lookup(char * name);  // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(Tsymbol *symbol);   // Creates a symbol table entry.

void DeleteList();

void prinTable();

struct Tsymbol * CreateSymbol(char *name, enum TYPES type, int size, int line);

void setValue(Tsymbol* symbol, int value);

#endif
