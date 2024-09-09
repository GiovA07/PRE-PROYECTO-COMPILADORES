#include "symbol.h"
Tsymbol *table = NULL;

int num = 0;

struct Tsymbol *Lookup(char * name){
  Tsymbol *head = table;
  if(name == NULL) {
    return NULL;
  }
  while(head != NULL) {
    if(strcmp(name, head->varname)==0){
      return head;
    }
    head = head->next;
  }
  return NULL;
}

void Install(Tsymbol *symbol){
  if(Lookup(symbol->varname) == NULL){
    symbol->next =  table;
    table = symbol;
  } else {
    printf("Simbolo existen, linea de error: %d", symbol->line);
    exit(1);
  }
}

struct Tsymbol * CreateSymbol(char *name, enum TYPES type, int size, int line){
    Tsymbol *newSymbol = (Tsymbol *)malloc(sizeof(Tsymbol));
    newSymbol->id=num++;
    newSymbol->varname = name;
    newSymbol->type = type;
    newSymbol->size = size;
    newSymbol->line = line;
    newSymbol->value = 0;
    return newSymbol;
}

void DeleteList(){
  Tsymbol *aux;
  while(table != NULL) {
    aux  = table;
    table = table->next;
    free(aux);
  }
}

void prinTable(){
    Tsymbol *aux = table;
    printf("TABLA DE SIMBOLOS\n");
    printf("| nam | typ | siz | valor |\n");
    while(aux != NULL) {
        printf("| %s |", aux->varname);
        printf(" %s |", string[aux->type]);
        printf(" %d |", aux->size);
        printf(" %d |\n", aux->value);
        aux = aux->next;
    }
}

void setValue(Tsymbol* symbol, int valor){
    if(symbol != NULL) { 
      symbol->value = valor;
    } else {
        printf("Error: simbolo es NULL\n");
    }
}