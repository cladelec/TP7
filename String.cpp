#include "String.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

size_t String::MAX_SIZE=100;

String::String() {
	taille_=0;
	chaine_=nullptr;
	capacite_=0;
}

//constructeur par copie
String::String(const String &s){
	taille_=s.taille_;
	capacite_=s.capacite_;
	int i;
	char* tab =new char[capacite_];
  for (i=0;i<taille_;++i){
  	tab[i] = s.chaine_[i];
	}
  tab[taille_] = '\0';
}

//destructeur : pas de pre-conditions ni de post-conditions
String::~String() {
	taille_=0;
	capacite_=0;
	delete chaine_;
}

//getters 
char* String::c_str(){
	return chaine_;
}
 //retourne la capacité
size_t String::capacity(){
	return capacite_;
}

size_t String::size(){
  return taille_;
}


size_t String::length(){
  return taille_;
}



String& String::operator=(const char* c1) {
	int i=0;
	while(c1[i]!='\0') {
		++i;
	}
	taille_=i-1;
	capacite_=i*2;
	delete[] chaine_;
	
	chaine_=new char[capacite_] ;
	
	for(int i=0;i<taille_;i++) {	
		chaine_[i]=c1[i] ;
	}
}

//Regarde si le string est vide, retourne true si c'est le cas.
//pas de paramètres : la méthode s'applique directement au string à tester
bool String::empty() {
	if (taille_==0) {
		return true ;
	}
	return false ;
}

//Realloue de la mémoire pour un tableau de char de la taille passée en paramètre
//paramètres : un size_t de la taille à allouer
//pas de retour. Le string auquel on applique la méthode est directement modifié
void String::reserve(size_t taille) {
	capacite_=taille;
	char* nchaine=new char[taille];
	char current=chaine_[0] ;
	int i=0 ;
	while (current!='\0') {
		nchaine[i]=chaine_[i] ;
		i=i+1;
		current=chaine_[i] ;
	}
	nchaine[i]='\0';
	delete chaine_ ;
	chaine_=nchaine;	
	
} 



//OPERATEURS

//additionne les deux string passés en paramètre. Retourne un nouveau string des deux concaténés.
String operator+(const String& s1,const String& s2) {
	String result=String(s1) ; //on copie le premier string dans un nouveau qui sera retourné
	result.taille_=s1.taille_+s2.taille_; 
	result.reserve(s1.capacite_+s2.capacite_); //change la taille et la memoire allouée pour accueillir la concaténation des deux
	
	for (int i=s1.taille_+1;i<result.taille_;i++) { //on ajoute la chaine du deuxieme string à la suite du premier
		result.chaine_[i]=s2.chaine_[i]; //
	}
	
	return result;
}

//change le string à qui on applique la méthode, change la chaine par le tableau de char pris en paramètre
String& String::operator=(const char* c1) {
	int i=0;
	while(c1[i]!='\0') { //on regarde la taille du tableau de char
		++i;
	}
	taille_=i-1;
	capacite_=i*2;
	delete[] chaine_; //supprime l'ancienne chaine
	
	chaine_=new char[capacite_] ; //réalloue la mémoire
	
	for(int i=0;i<taille_;i++) { //copie le tableau dans la nouvelle chaine 
		chaine_[i]=c1[i] ;
	}
}


void String::operator=(String s){
	delete chaine_;
	taille_=s.size();
	chaine_=s.c_str();
	capacite_=s.capacity();
}

/*void String::operator+(char c){
	taille_=taille_+1;
	chaine_=;
	capacite_=0;
}*/



















