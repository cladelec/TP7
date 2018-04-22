#include <iostream>
#include "String.h"
#include <cstdio>
#include <cstdlib>

int main () {
	printf("Hello world \n");
	
	/*String s;
	printf("%d \n",s.length());

	String s1;
	bool a= s1.empty();
	
	printf("%d \n",s1.empty()) ;
	printf("%d \n",s1.capacity()) ;*/
	
	char tab[] = "bonjour" ;
	String s3(tab) ; //test constructeur
	s3.affichage() ;
	
	char tab2[]="abc";
	String s4(tab2) ;
	s4.affichage() ;
	
	printf("%d \n",s3.empty()) ; //test méthode empty
	printf("%d \n",s4.empty()) ;
	
	//delete &s3 ; //test du destructeur
	//std::cout<<&s3<<std::endl;
	//delete &s4 ; 
	//std::cout<<&s4<<std::endl;
	
	/*printf("%d \n",s3.capacity()); //test capacity
	printf("%d \n",s4.capacity());
	
	s3.reserve(16) ; //test reserve
	s4.reserve(10) ;
	printf("%d \n",s3.capacity()); 
	printf("%d \n",s4.capacity());*/
	
	s3="salut"; //test operateur =(char*)
	s3.affichage();
	
	String s5(s3) ; //test constructeur par copie
	s5.affichage() ;
	
	String s6=s3+s4; //test operateur +(string)
	
	s6.affichage() ;
	printf("%d \n",s6.capacity());
	printf("%d \n",s6.size());

}
