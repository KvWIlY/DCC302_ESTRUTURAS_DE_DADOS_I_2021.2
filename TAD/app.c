#include "float_vector.h"
#include <stdio.h>

int main(){
	FloatVector *vec = create(10);
	print(vec);
	append(vec, 4.6);
	append(vec, 22.4);
	append(vec, 8.5);
	print(vec);
	
	removefv(vec, 0);
	print(vec);
	
	
	FloatVector *aeee = clone(vec);
	print(aeee);

	erase (vec);
	print (vec);
}