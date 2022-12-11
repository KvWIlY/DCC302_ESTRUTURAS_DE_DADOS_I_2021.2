typedef struct{
  int capacity;
  int size;
  float *data;
} FloatVector;

FloatVector* create(int capacity);
FloatVector* clone(FloatVector* vec);
void destroy(FloatVector** vec_ref);
void removefv(FloatVector* vec,int index);
void erase(FloatVector* vec);
int size(FloatVector* vec);
int capacity(FloatVector* vec);
float get(FloatVector* vec,int index);
void append(FloatVector* vec,float val);
void set(FloatVector* vec,int index,float val);
void print(FloatVector* vec);
