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
	//
	taille_=s.taille_;
	capacite_=s.capacite_;
	int i;
	char* chain =new char[capacite_];
  for (i=0;i<taille_;++i){
  	chain[i] = s.chaine_[i];
	}
  chain[taille_+1] = '\0';
	chaine_=chain;
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

/*String String::operator+(const String s1,const String s2) {
	String result=String(s1) ;
	
	for (int i=0;i<s1.size();i++) {
		s[i]=*(s1.c_str())[i];
	} 
	for (int i=s1->size+1;i<s1.size()+this.size();i++) {
		s[i]=*(this.chaine_)[i];
	}
	String ch=new String ;
	ch String(&s)
	return ch;
}
*/

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

String& String::operator= (const String& str){
	// on supprime la chaine qui a été créée pour ne pas avoir de fuite mémoire
	delete chaine_;
	// on donne les mêmes valeurs des attributs 
	taille_=str.taille_;
	capacite_=str.capacite_;
	char* newstr = new char [capacite_];
	int i;
	for (i=0;i<taille_;++i){
  	newstr[i] = str.chaine_[i];
	}
	newstr[taille_+1] = '\0';
	chaine_=newstr;
	return *this;
}

String operator+(const String& str, char c){
	String s(str);
	if(str.capacite_>=str.taille_+2){
		s.taille_=s.taille_+1;
		s.chaine_[s.taille_]=c;
		s.chaine_[s.taille_+1]='\0';
	}
	else{
		s.reserve(s.taille_+2);
		s.taille_=s.taille_+1;
		s.chaine_[s.taille_]=c;
		s.chaine_[s.taille_+1]='\0';
	}
	return s;
}

void String::clear(){
	taille_=0;
	chaine_[0]='\0';
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
