#include "String.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

int String::MAX_SIZE=100;

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

bool String::empty() {
	if (taille_==0) {
		return true ;
	}
	return false ;
}

String::~String() {
	taille_=0;
	capacite_=0;
	delete chaine_;
}

//getters 
char* String::c_str(){
	return chaine_;
}

size_t String::capacity(){
	return capacite_;
}

String operator+(const String& s1,const String& s2) {
	String result=String(s1) ;
	result.taille_=s1.taille_+s2.taille_;
	result.capacite_=s1.capacite_+s2.capacite_;
	
	for (int i=s1.taille_+1;i<result.taille_;i++) {
		result.chaine_[i]=s2.chaine_[i];
	}
	
	return result;
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


size_t String::size(){
  return taille_;
}


size_t String::length(){
  return taille_;
}

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






















