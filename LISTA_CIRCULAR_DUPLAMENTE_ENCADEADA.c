#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

void CircList_print(Circ_list* L){
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

        printf("\nL -> end = %d", L->end->val);
    }
    printf("\nsize: %lu\n\n",L->size);
}

void CircList_add_last(Circ_list *L, int val){
    CircNode* p = create_node(val);
    p->val = val;
    p->prev = L->end;
    p->next = NULL;
    if(L->end != NULL){
        L->end->next = p;
    }else{
        L->begin = p;
    }
    L->end = p;
}

void CircList_print_add_last(Circ_list* L){
    if(Circlist_is_empty(L)){
        printf("L -> NULL\n");
        printf("L -> Begin -> NULL\n");
    } else {
        CircNode* p= L->begin;
        printf("L -> ");
        while (p != NULL){
            printf("%d -> ", p->val);
            p = p->next;
        }
    
        printf("\n");
        (L->begin == NULL)? printf("L -> begin = NULL\n") : printf("L -> end = %d\n", L->end->val);
        printf("Size: %lu\n", L->size);
    }
}

void CircList_remove(Circ_list *L, int valor){
    CircNode* p = L->begin;
    if(!Circlist_is_empty(L)){
        if(L->begin->val == valor){
            L->begin = p->next;
            if(L->end = p){
                L->end = NULL;
            }else{
                L->begin->prev = NULL;
            }
            free(p);
        } else{
            p = p->next;
            while(p != NULL){
                if(p->val == valor){
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    break;  
                    free(p);  
                }
                p = p->next;
            }
        }
    }
}

void CircList_print_remove(Circ_list* L){
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
    }
}

Circ_list* CircList_removeDuplicated(Circ_list *L){
    CircNode *p = NULL;
    CircNode *k = NULL;
    p = L->begin;
    Circ_list *m = create_list();
        do{
            int qualqueum = p->val;
            bool duplicada = false;
            if(!Circlist_is_empty(m)){
                k = m->begin;
                do{
                    if(k->val == qualqueum){
                        duplicada = true;
                    }
                    k = k->next;
                }while(k != m->begin);   
                if(!duplicada){
                    CircList_add_first(m,qualqueum);
                } 
            }else{
                CircList_add_first(m,qualqueum);
            }
            p = p->next;
        }while( p != L->begin);
        destroy_list(&L);
    return m;
}

void CircList_print_removeDuplicated(Circ_list* L){
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
    }
}

void CircList_Soma(Circ_list *l,Circ_list *p){
    CircNode *t = NULL;
    t = l->end;
    char opa[l->size +1];
    char eita[p->size + 1];
    int i=0;
    do{  
        opa[i]=t->val + '0';
        t = t->prev;
        i++;
    }while(t != l->end);
    t = p->end;
    opa[i+1] = '\0';
    i=0;
    do{
        eita[i]=t->val+'0';
        t = t->prev;
        i++;
    }while(t != p->end);
    eita[i+1] = '\0';
    printf("Soma = %d ",atoi(opa)+atoi(eita));
}


// ---------------------- Teste de Códigos -------------------
void main(){
    Circ_list *L = create_list();

    CircList_add_first(L,3);
    CircList_add_first(L,4);
    CircList_add_first(L,1);
    CircList_add_first(L,3);
    CircList_add_first(L,1);
    CircList_add_first(L,5);
    CircList_add_first(L,9);
    CircList_add_first(L,4);
    CircList_add_first(L,3);

//-------- print da lista ----------------
    printf("Lista BRabar\n");
    CircList_print(L);

//     printf("\n");
// //------- função inserir -----------
//     printf("Lista inserindo 7 no final da lista \n");
//     CircList_add_last(L,7);
//     CircList_print_add_last(L);
    
//     printf("\n");
// //------- função remove -------------
//     // printf("Lista com o valor 7 removido \n");
//     // CircList_remove(L,7);
//     // CircList_print_remove(L);

//     // printf("\n");
//------- questao 1 da lista ---------
    printf("Lista com valores duplicados removidos \n");
    L = CircList_removeDuplicated(L);
    CircList_print_removeDuplicated(L);

    printf("\n");

//----- questao  2 da Lista --------- 
    printf("\n");
    Circ_list *t = create_list();
    Circ_list *k = create_list();
 
    CircList_add_first(t,5);
    CircList_add_first(t,1);
    CircList_add_first(t,3);
    CircList_add_first(k,2);
    CircList_add_first(k,9);
    CircList_add_first(k,5);

    printf("Soma de (3 -> 1 -> 5), (5 -> 9 -> 2) \n");
    CircList_Soma(t,k);
//------ destruidor de lista --------
    destroy_list(&L);
}