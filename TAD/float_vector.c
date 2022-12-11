#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

FloatVector* create(int capacity){
  FloatVector *vec = (FloatVector*) malloc(sizeof(FloatVector));
  vec ->capacity = capacity;
  vec ->size = 0;
  vec ->data = calloc(capacity, sizeof(float));
  return vec;
}

FloatVector* clone(FloatVector* vec){
	FloatVector* NewVector = create(vec -> capacity);
	for(int i=0; i < vec -> size; i++) {
		append (NewVector, vec -> data[i]);
	}
	return NewVector;
}

void destroy(FloatVector** vec_ref){
  FloatVector* vec = *vec_ref;
  free(vec -> data);
  free(vec);
  *vec_ref = NULL;
}

void removefv(FloatVector* vec, int index){
	float* NewVector = calloc(vec -> capacity-1, sizeof(float));
	int offset = 0;
	for(int i=0; i < vec->size; i++) {
		if (i != index){
			NewVector [i]= vec -> data[i + offset];
			
		} 
		else{
			offset++;
			
		}
	}
	vec -> size--;
	free (vec-> data);
	vec -> data = NewVector;
}

void erase(FloatVector* vec){
	for( int i=0; i < vec -> size; i++){
		vec -> data[i]=0;
	}
	vec -> size = 0;
}

int size(FloatVector* vec){
  return vec->size;
}

int capacity(FloatVector* vec){
  return vec->capacity;
}

float get(FloatVector* vec,int index){
  if(index >= vec->size ){
    fprintf(stderr,"ERROR in get()\n");
    fprintf(stderr,"Index [%d] is out of bounds: [0, %d]\n", index,vec->size-1);
    exit(EXIT_FAILURE);
  }
  return vec->data[index];
}

void append(FloatVector* vec,float val){
  if(vec->size == vec->capacity){
    fprintf(stderr,"ERROR in append()\n");
    fprintf(stderr,"Vector is full\n");
    exit(EXIT_FAILURE);
  }
  vec->data[vec->size++] = val;
}

void set(FloatVector* vec,int index,float val){
  if(vec->size == vec->capacity){
    fprintf(stderr,"ERROR in set()\n");
    fprintf(stderr,"Vector is full\n");
    exit(EXIT_FAILURE);
  }
  if(index >= vec->size ){
    fprintf(stderr,"ERROR in set()\n");
    fprintf(stderr,"Index [%d] is out of bounds: [0, %d]\n", index,vec->size-1);
    exit(EXIT_FAILURE);
  }
  append(vec, vec->data[index]);

  vec->data[index] = val;
}
void print(FloatVector* vec){
  puts("-----------Float-Vector------------");
  printf("Size: %d\n", vec->size);
  printf("Capacity: %d\n", vec->capacity);
  puts("-------------------");
  int i;
  for(i=0; i < vec->size; i++){
    printf("| %.2f | " , vec->data[i]);
    printf(" ( %d ) \n", i);
  }
  puts("----------------");
}
