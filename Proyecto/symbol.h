#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SYMBOL_H
#define SYMBOL_H

typedef struct Tsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable
    int size;         // size of the type of the variable
    struct Tsymbol *next;
} Tsymbol;

struct Tsymbol *Lookup(char * name);  // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(char *name, int type, int size);   // Creates a symbol table entry.

void DeleteList();

void prinTable();

#endif