#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ISNULL(x) (x==NULL)
#define ISEQUAL(a, b)   (a == b)
#define MAX_SIZE_ARRAY 100010
typedef long long int64;

typedef struct Arraylist{
    int lenght;
    int maxSize;
    int64 data[MAX_SIZE_ARRAY];
} Arraylist;

void insert(Arraylist* n, int64 value){
    if(ISNULL(n)){
        printf("lista nula!\n");
        return;
    }
    n->data[n->lenght++] = value;    
}

void clear(Arraylist* n){
    n->lenght = 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void infoGanhador(int64 iteration){
    if(iteration % 2 != 0){
        printf("Marcelo\n");
        return;
    }
    printf("Carlos\n");
}

int64 B[MAX_SIZE_ARRAY];
int64 merge(int64 A[], int64 begin, int64 mid, int64 end){
    int64 i = begin,
          j = mid+1,
          k = begin;
    int64 iteration = 0;
    while(i <= mid && j <= end){
        if(A[i] <= A[j]){
            B[k++] = A[i++]; 
        } else {
            B[k++] = A[j++];
            iteration += mid + 1 - i; 
        }     
    }    
    for(i; i <= mid ;i++)
        B[k++] = A[i];
    for(j; j <= end ;j++)
        B[k++] = A[j];
    for(i = begin; i <= end; i++)
        A[i] = B[i];    
    return iteration;
}

int64 mergeSort(int64 A[], int64 begin, int64 end){
    int64 iteration = 0, mid;        
    if(begin < end){
        mid = (begin+end)/2;
        iteration = mergeSort(A, begin, mid);
        iteration += mergeSort(A, mid+1, end);
        iteration += merge(A, begin, mid, end);
    }
    return iteration;
}

void main(){
    Arraylist lista;
    int N, i;
    while(scanf("%d", &N)&&N!=0){     
        for(i = 0; i < N; i++){
            int number;
            scanf("%d", &number);
            insert(&lista, number);       
        }
        infoGanhador(mergeSort(lista.data, 0, lista.lenght-1));
        clear(&lista);
    }
}