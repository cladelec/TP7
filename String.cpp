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

size_t String::length(){
  return taille_;
}

size_t String::max_size(){
  return MAX_SIZE;
  }
size_t String::size(){
  return taille_;
}

void String::resize (size_t n, char c){
  if (n<taille_){
    chaine_[n] = '\0';
    taille_ =n;
    }
  else if (n>taille_){
    for( int i = taille_; i<=n; i++){
      reserve(n*2);
      chaine_[i] = c;
      taille_ =n;
      }
  }
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
