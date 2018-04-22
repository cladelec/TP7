#include <iostream>
#include "String.h"
#include <cstdio>
#include <cstdlib>

int main () {
	printf("Hello world \n");
	
	String s;
	printf("%d \n",s.length());

	String s1;
	bool a= s1.empty();
	
	printf("%d \n",s1.empty()) ;
	printf("%d \n",s1.capacity()) ;
	printf("%d \n",s.max_size());


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
	printf("%d \n",s6.size()); //test size()
	printf("%s \n",s6.c_str()); //test c_str() <-> méthode affichage
  printf("%d \n",s6.length()); //test length()
	printf("%d \n",s6.max_size()); //test max_size()
	
	s5.clear(); // test clear()
	s5.affichage(); // affiche un vide -> plus rien dans tableau (car 1er terme = \0)
	
	String s7(s3); // nouveau String = "salut" (par copie)
	s7.affichage();
	s7=s6; // test Operateur =(string)
	s6.affichage();
	s7.affichage(); // affiche bien "salutabc" comme ligne précédente

	char c1='d';
	String s8; // nouveau String (par défaut)
	s8=s4+c1; //test Operateur +(char)
	s8.affichage(); // affiche bien abcd
  
  s6.resize(5,'a'); //test resize
	s6.affichage();
	
	String s9(s6);
	s9.affichage();
	s9=c1; // test Operateur =(char)
	s9.affichage();
	
	String s10;
	char tab3[]="ebat";
	s10=s9+tab3; //test Operateur +(char*)
	s10.affichage();
}
