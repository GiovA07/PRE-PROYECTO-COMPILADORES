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
    EBLOQ,
    CALL_F,
    ARGS,
    PARAMINT,
    PARAMBOOL,
    OTHERS,
    BLOCK,
    BLOCK_FIN
};

char static string[40][41] = {"VAR","EMAIN","VARINT","VARBOOL","CONSINT","CONSBOOL","SUMA","RESTA","PROD","EDIV","ERESTO","EOR","EAND","ENOT","ASIG","DECLA","SENTEN","EID","ERETURN","RETINT","RETBOL","RETVOID","EIF","ETHEN","EELSE","EWHILE","EMAYORQUE","EMENORQUE","EEQ","EFUNC","EFUNCEXTERN","EPROGRAM","EBLOQ","CALL_F","ARGS", "PARAMINT", "PARAMBOOL","OTHERS","BLOCK","BLOCK_FIN"};


typedef struct Tsymbol {
    int id;
    enum TYPES type;
    char* varname;       // name of the variable
    int size;         // lo uso para saber en que bloque esta la variable (preguntar)
    struct Tsymbol *next;
    int line;
    int value;
    int offset;
    struct Tsymbol *table;
} Tsymbol;

struct Tsymbol *Lookup(char * name);  // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void Install(Tsymbol *symbol);   // Creates a symbol table entry.
void DeleteList();
void prinTable();
struct Tsymbol * CreateSymbol(char *name, enum TYPES type, int size, int line);
void setValue(Tsymbol* symbol, int value);
void addOffset(Tsymbol* symbol, int offset);
int getScope();
// Nuevas funciones para el alcance de las variables

void InstallInCurrentScope (Tsymbol *symbol);

void PopScope();

void InstallParam (Tsymbol *param,Tsymbol *tablaFunc);
void InstallScope();

struct Tsymbol *LookupInCurrentLevel(char * name);
struct Tsymbol *LookupInTableAux(char * name, Tsymbol *symTable);
struct Tsymbol *LookupExternVar(char * name);


//void InstallTable(Tsymbol *symbol,Tsymbol *symTabla);
//struct Tsymbol *LookupTable(int size);
int cantArguments(Tsymbol* symTabla);
int* typeParam(Tsymbol* symTabla);

#endif
