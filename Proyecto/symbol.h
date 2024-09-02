#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SYMBOL_H
#define SYMBOL_H

enum TYPES {
    VAR,
    EMAIN,
    VARINT,
    VARBOOL,
    CONSINT,
    CONSBOOL,
    CONS,
    SUMA,
    RESTA,
    PROD,
    EOR,
    EAND,
    ENOT,
    ASIG,
    DECLA,
    SENTEN,
    EID,
    ERETURN,
    OTHERS
};

char static string[19][20] = {"VAR","EMAIN","VARINT","VARBOOL","CONSINT","CONSBOOL","CONS","SUMA","RESTA","PROD","EOR","EAND","ENOT","ASIG","DECLA","SENTEN","EID","ERETURN","OTHERS"};


typedef struct Tsymbol {
    int id;
    enum TYPES type;
    char* varname;       // name of the variable
    int size;         // size of the type of the variable
    struct Tsymbol *next;
    int line;
} Tsymbol;

struct Tsymbol *Lookup(char * name);  // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(Tsymbol *symbol);   // Creates a symbol table entry.

void DeleteList();

void prinTable();

struct Tsymbol * CreateSymbol(char *name, enum TYPES type, int size, int line);


#endif
