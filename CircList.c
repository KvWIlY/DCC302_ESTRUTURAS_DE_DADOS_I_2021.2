#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//---------------------Definição das Estruturas -----------------

typedef struct _circ_node{
  int val;
  struct _circ_node *next;
  struct _circ_node *prev;
} CircNode;

typedef struct _circ_list{
  CircNode *begin;
  CircNode *end;
  size_t size; // alias unsing long (int)
} Circ_list;

// -------- Construtores e Destrutores das Estruturas -------
CircNode *create_node(int val){
  CircNode *cnode = (CircNode *) malloc(sizeof (CircNode));
  cnode->val = val;
  cnode->next = cnode;
  cnode->prev = cnode;
  return cnode;
}

Circ_list *create_list(){
  Circ_list *L = (Circ_list *) malloc(sizeof(Circ_list));
  L->begin = NULL;
  L->end = NULL;
  L->size = 0;
  return L;
}

void destroy_list(Circ_list **L_ref){
    Circ_list *L = *L_ref;

    CircNode *p = L ->begin;
    CircNode *aux = NULL;

    for (size_t i = 0; i < L->size; i++){
       aux = p;
       p = p->next;
       free(aux); 
    }

    free(L);
    *L_ref = NULL;
}

// ---------------------- FUNÇOES --------------------------
bool Circlist_is_empty(Circ_list *L){return L ->size == 0;}

void CircList_add_first(Circ_list *L, int val){
    CircNode *p = create_node(val);
    //caso 1: A lista está vazia
    if(Circlist_is_empty(L)){
       L->begin = p;
       L->end = p; 
    } else {
        // caso 2: Lista não está vazia
        p->next = L->begin;
        L->begin->prev = p;
        L->begin = p;
        //parte CIRCULAR
        p -> prev = L->end;
        L ->end->next = p;
    }
    L->size++; 
}

void Circ_list_print(Circ_list* L){
    if(Circlist_is_empty(L)){
        printf("L -> NULL\n");
        printf("L -> Begin -> NULL\n");
    } else {
        CircNode *p = L->begin;
        printf("L -> ");
        do{
            printf("%d -> ", p->val);
            p = p->next;
        }while(p != L->begin);
        printf("\nL -> end -> %d", L->end->val);
    }
    printf("\nsize: %lu\n\n",L->size);
}

// ---------------------- Teste de Códigos -------------------
int main(){
  Circ_list *L = create_list();
  puts("add first: 7,5,4,2,10");
  CircList_add_first(L,7);
  CircList_add_first(L,5);
  CircList_add_first(L,4);
  CircList_add_first(L,2);
  CircList_add_first(L,10);

  printf("Lista BRabar\n");
  Circ_list_print(L);

  destroy_list(&L);

  return 0;
}