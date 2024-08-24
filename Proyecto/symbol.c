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
/*
int main(){
  char *num = "num";
  char *sum = "sum";

  Install(aux,1,1);
  Install(aux1,1,1);
  Install(aux,10,10);
  Install(aux,10,10);
  Install(aux,10,10);
  struct Tsymbol *res = Lookup(aux);
  printf("Tipo : %d \n",res->type);
  printf("Size : %d \n",res->size);
  
  DeleteList();
  
  if(table == NULL) {
    printf("Sin basura");
  }
  return 0;
}

*/



