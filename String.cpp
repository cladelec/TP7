#include "String.h"

#include <cstring>

int String::MAX_SIZE=100;


String::String() {
	taille_=0;
	chaine_=nullptr;
	capacite_=0;
}
//constructeur à partir d'une cstring
String::String(char* ch){
  
  size_t i = 0;
  while (ch[i] != '\0') {
    ++i;
    }
  taille_ = i;
  capacite_ = taille_*2;
  chaine_ = new char[capacite_ +1];
  for (int j =0; j < taille_; j++){
    chaine_[j] = ch[j];
    } 
}
  
//constructeur par copie
/*String::String(String s){
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
char* String::get_chaine(){
	return chaine_;
}

int String::capacity(){
	return capacite_;
}

int String::length(){
  return taille_;
}

int String::max_size(){
  return MAX_SIZE;
  }
int String::size(){
  return taille_;
}
