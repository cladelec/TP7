#include <iostream>
#include "String.h"


int main () {
	printf("Hello world \n") ;
	
	String s;
	printf("%d \n",s.length());

	String s1;
	bool a= s1.empty();
	
	printf("%d \n",s1.empty()) ;
	printf("%d \n",s1.capacity()) ;
	printf("%d \n",s.max_size());
}
