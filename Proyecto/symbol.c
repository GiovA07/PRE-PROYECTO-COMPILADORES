#include "symbol.h"
Tsymbol *table = NULL;

struct Tsymbol *Lookup(char * name){
  Tsymbol *head = table;
  if(name == NULL) {
    return NULL;
  }
  while(head != NULL) {
    if(strcmp(name, head->name)==0){
      return head;
    }
    head = head->next;
  }
  return NULL;
}

void Install(char *name, int type, int size){
  if(Lookup(name) == NULL){
    Tsymbol *newSymbol = (Tsymbol *)malloc(sizeof(Tsymbol));
    newSymbol->name = name;
    newSymbol->type = type;
    newSymbol->size = size;
    newSymbol->next =  table;
    table = newSymbol;
  }
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
        printf("| %s |", aux->name);
        printf(" %d |", aux->type);
        printf(" %d |\n", aux->size);
        aux = aux->next;
    }
}