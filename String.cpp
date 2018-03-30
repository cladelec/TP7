#include "String.h"
int String::MAX_SIZE=100;

String::String() {
	taille_=0;
	chaine_=nullptr;
	capacite_=0;
}


/*
String::String(int taille, char* chaine) {
	taille_=taille;
	chaine_=chaine;
}*/

int String::length(){
  return taille_;
}
  
