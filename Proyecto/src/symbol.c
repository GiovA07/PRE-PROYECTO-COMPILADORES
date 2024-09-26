#include "../include/symbol.h"
Tsymbol *table = NULL;

int num = 0;

struct Tsymbol * CreateSymbol(char *name, enum TYPES type, int size, int line){
    Tsymbol *newSymbol = (Tsymbol *)malloc(sizeof(Tsymbol));
    newSymbol->id=num++;
    newSymbol->varname = name;
    newSymbol->type = type;
    newSymbol->size = size;
    newSymbol->line = line;
    newSymbol->value = 0;
    newSymbol->table = NULL;
    return newSymbol;
}

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
    printf("Simbolo existente, linea de error: %d", symbol->line);
    exit(1);
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
    printf("| nam   |    typ   | prof | valor \n");
    while(aux != NULL) {
        printf("Func\n");
        printf("| %s |", aux->varname);
        printf(" %s |", string[aux->type]);
        printf(" %d |", aux->size);
        printf(" %d |\n", aux->value);
        if(aux->table != NULL) {
            Tsymbol *aux1 = aux->table;
            while(aux1 != NULL) {
              printf("| %s |", aux1->varname);
              printf(" %s |", string[aux1->type]);
              printf(" %d |", aux1->size);
              printf(" %d |\n", aux1->value);
              aux1 = aux1->next;
            }
        }
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

struct Tsymbol *LookupTable(int size){
  Tsymbol *head = table;
  while(head != NULL) {
    if(size == head->size){
      return head;
    }
    head = head->next;
  }
  return NULL;
}

struct Tsymbol *LookupInTable(char * name,Tsymbol* symTabla){
  Tsymbol *head = symTabla->table;
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

void InstallTable(Tsymbol *symbol,Tsymbol *symTabla){
  if(LookupInTable(symbol->varname,symTabla) == NULL) {
    symbol->next =  symTabla->table;
    symTabla->table = symbol;
  } else {
    printf("Simbolo existente, linea de error: %d", symbol->line);
    exit(1);
  } 
}

// ver 
// void DeleteListTable(Tsymbol* symbol){
//   Tsymbol *aux;
//   while(symbol->table != NULL) {
//     aux  = symbol->table;
//     symbol->table = symbol->next;
//     free(aux);
//   }
// }
