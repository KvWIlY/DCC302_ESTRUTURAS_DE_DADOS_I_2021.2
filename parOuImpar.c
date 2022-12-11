#include <stdio.h>
#include <stdlib.h>

#define ISNULL(x) (x==NULL)
#define ISEQUAL(a, b)   (a == b)

typedef struct Arraylist{
    int lenght;
    int maxSize;
    int *data;
} Arraylist;

Arraylist* createList();
Arraylist* createListSize(int size);
int insert(Arraylist* n, int value);

Arraylist* createList(){
    Arraylist* temp = (Arraylist*)malloc(sizeof(Arraylist));
    if(ISNULL(temp)){
        printf("erro na alocacao de memoria!\n");
        return (0);
    }
    temp->lenght = 0;
    temp->maxSize = 100;
    temp->data = (int*)malloc(sizeof(int)*temp->maxSize);
    return temp; 
}

Arraylist* createListSize(int size){
    Arraylist* temp = (Arraylist*)malloc(sizeof(Arraylist));
    if(ISNULL(temp)){
        printf("erro na alocacao de memoria!\n");
        return (0);
    }
    temp->lenght = 0;
    temp->maxSize = size;
    temp->data = (int*)malloc(sizeof(int)*temp->maxSize);
    return temp; 
}

int insert(Arraylist* n, int value){
    if(ISNULL(n)){
        printf("lista nula!\n");
        return (0);
    }
    n->data[n->lenght++] = value;
    return (1);
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l, j = h, isPar = (pivot % 2 == 0);
    do {
        if(isPar){
            do{i++;}while(A[i] <= pivot);
            do{j--;}while(A[j] >  pivot);
        }else{
            do{i++;}while(A[i] >= pivot);
            do{j--;}while(A[j] <  pivot);
        }
        if(i < j)
            swap(&A[i], &A[j]);
    }while(i < j);
    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h){
    if(l < h){
        int p = partition(A, l, h);
        quickSort(A,    l,  p);
        quickSort(A, p + 1, h);
    }
}

int main(){
    Arraylist *pares, *impares;

    int N, i;
    scanf("%d", &N);
    pares   = createListSize(N);
    impares = createListSize(N);

    for(i = 0; i < N; i++){

        unsigned int number;
        scanf("%u", &number);
        if(number % 2 == 0)
            insert(pares, number);
        else
            insert(impares, number);

    }
    quickSort(pares->data,   0, pares->lenght);
    quickSort(impares->data, 0, impares->lenght);

    for(i = 0; i < pares->lenght; i++)
        printf("%u\n", pares->data[i]);
    for(i = 0; i < impares->lenght; i++)
        printf("%u\n", impares->data[i]);
    return 0;
}