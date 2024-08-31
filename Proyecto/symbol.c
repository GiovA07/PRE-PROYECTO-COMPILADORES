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

void Install(char *name, enum TYPES type, int size){
  if(Lookup(name) == NULL){
    Tsymbol *newSymbol = (Tsymbol *)malloc(sizeof(Tsymbol));
    newSymbol->varname = name;
    newSymbol->type = type;
    newSymbol->size = size;
    newSymbol->next =  table;
    table = newSymbol;
  }
}

struct Tsymbol * CreateSymbol(char *name, enum TYPES type, int size){
    Tsymbol *newSymbol = (Tsymbol *)malloc(sizeof(Tsymbol));
    newSymbol->id=num++;
    newSymbol->varname = name;
    newSymbol->type = type;
    newSymbol->size = size;
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
    printf("| nam |typ|siz|\n");
    while(aux != NULL) {
        printf("| %s |", aux->varname);
        //printf(" %s |", aux->type);
        printf(" %d |\n", aux->size);
        aux = aux->next;
    }
}
