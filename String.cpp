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
	Le nouveau string aura le même
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
	delete chaine_;
	taille_=str.taille_;
	chaine_=str.chaine_;
	capacite_=str.capacite_;
}

String operator+(const String& str, char c){
	if(str.capacite_>=str.taille_+1){
		String s(str);
		s.taille_=s.taille_+1;
		s.chaine_[s.taille_-1]=c;
		s.chaine_[s.taille_]='\0';
	}
	else{
		String s(str);
		s.capacite_=s.capacite_+1;
		s.taille_=s.taille_+1;
		s.chaine_[s.taille_-1]=c;
		s.chaine_[s.taille_]='\0';
	}
}

void String::clear(){
	taille_=0;
	chaine_=nullptr;
	capacite_=1;
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
