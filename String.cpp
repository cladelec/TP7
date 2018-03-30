#include "String.h"
int String::MAX_SIZE=100;

String::String() {
	taille_=0;
	chaine_=nullptr;
	capacite_=0;
}
/*constructeur par copie
String::String(String s){
}*/

bool String::empty() {
	if (taille_==0) {
		return true ;
	}
	return false ;
}
/*
String::String(int taille, char* chaine) {
	taille_=taille;
	chaine_=chaine;
}*/

//getters 
char* String::get_chaine(){
	return chaine_;
}

int String::capacity(){
	return capacite_;
}

String operator+(String s1,String s2) {
	return s1 ;
}

bool operator==(String s1, char* c1) {
	return true ;

}
