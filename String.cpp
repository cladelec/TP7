#include "String.h"
int String::MAX_SIZE=100;

String::String() {
	taille_=0;
	chaine_=nullptr;
	capacite_=0;
}
/*constructeur par copie
String::String(String s){
	taille_=s.length();
	chaine_=s.c_str();
	capacite_=s.capacity()
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
int String::get_taille(){
	return taille_;
}

char* String::get_chaine(){
	return chaine_;
}

int String::get_capacite(){
	return capacite_;
}
