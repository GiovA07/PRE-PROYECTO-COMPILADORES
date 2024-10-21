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
    newSymbol->offset = 0;
    return newSymbol;
}


//push - instalo en la tabla el scope
void InstallScope(){
  char *aux = "scope";
  Tsymbol *scope = CreateSymbol(aux,OTHERS, 0, 0);
  scope->next =  table;
  table = scope;
}

struct Tsymbol *LookupInCurrentLevel(char * name){
  Tsymbol *head = table->table;
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

struct Tsymbol *LookupInTableAux(char * name, Tsymbol *symTable){
  Tsymbol *head = symTable->table;
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

void InstallInCurrentScope (Tsymbol *symbol){
  Tsymbol *head = table;
  if(LookupInCurrentLevel(symbol->varname) == NULL) {
    symbol->next =  head->table;
    head->table = symbol;
  } else {
    printf("Simbolo existente, linea de error: %d", symbol->line);
    exit(1);
  }
}

void PopScope(){
  Tsymbol* elim = table;
  table = table -> next;
  free(elim);
}



void InstallParam (Tsymbol *param,Tsymbol *tablaFunc){
  Tsymbol *head = tablaFunc;
  if(LookupInTableAux(param->varname,head) == NULL) {
    param->next =  head->table;
    head->table = param;
  } else {
    printf("Simbolo existente, linea de error: %d", param->line);
    exit(1);
  }
}


struct Tsymbol *LookupExternVar(char * name) {
  Tsymbol *head = table;
  if(LookupInTableAux(name,head) == NULL){
    while(head != NULL) {
      Tsymbol *aux = LookupInTableAux(name, head);
      if(aux){
        return aux;
      }
      head = head->next;
    }
  }
}


void setValue(Tsymbol* symbol, int valor){
    if(symbol != NULL) {
      symbol->value = valor;
    } else {
        printf("Error: simbolo es NULL\n");
    }
}

int* typeParam(Tsymbol* symTabla){
  int index = cantArguments(symTabla);
  int* types = (int*) malloc(index * sizeof(int));
  index -= 1;
  Tsymbol *aux = symTabla->table;
  while(aux != NULL) {
    if (aux->type == PARAMINT || aux->type == PARAMBOOL) {
      types[index] = aux->type;
      index -= 1;
    }
    aux = aux->next;
  }
  return types;
}

int cantArguments(Tsymbol* symTabla){
  int cant = 0;
  Tsymbol *aux = symTabla->table;
  while(aux != NULL) {
    if (aux->type == PARAMBOOL || aux->type == PARAMINT) {
      cant += 1;
    }
    aux = aux->next;
  }
  return cant;
}

void prinTable(){
    Tsymbol *aux = table;
    printf("TABLA DE SIMBOLOS\n");
    printf("| nam   |    typ   | prof | valor \n");
    while(aux != NULL) {
        //printf("Func\n");
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


void addOffset(Tsymbol* symbol, int offset) {
  symbol->offset = offset;
}


// struct Tsymbol *Lookup(char * name){
//   Tsymbol *head = table;
//   if(name == NULL) {
//     return NULL;
//   }
//   while(head != NULL) {
//     if(strcmp(name, head->varname)==0){
//       return head;
//     }
//     head = head->next;
//   }
//   return NULL;
// }

// para tabla global
// void Install(Tsymbol *symbol){
//   if(Lookup(symbol->varname) == NULL){
//     symbol->next =  table;
//     table = symbol;
//   } else {
//     printf("Simbolo existente, linea de error: %d", symbol->line);
//     exit(1);
//   }
// }

// void DeleteList(){
//   Tsymbol *aux;
//   while(table != NULL) {
//     aux  = table;
//     table = table->next;
//     free(aux);
//   }
// }
