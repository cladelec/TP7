#include <iostream>
#include "String.h"


int main () {
	printf("Hello world \n");
	
	String s1;
	bool a= s1.empty();
	printf("%d \n",s1.empty()) ;
	printf("%d \n",s1.capacity()) ;
}
