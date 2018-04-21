#include "String.h"
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

int String::capacity(){
	return capacite_;
}

/*String operator+(String s1,String s2) {
	char* s=new char[s1.size_+s2.size_]; 
	for (int i=0;i<s1.taille_;i++) {
		s[i]=*(s1.chaine_)[i];
	} 
	for (int i=s1.size+1;i<s1.size+s2.size;i++) {
		s[i]=*(s2.chaine_)[i];
	}
	String ch=new String ;
	ch String(&s)
	return ch;
}

bool operator==(String s1, char* c1) {
	ret=true;
	for (i=0;i<s1.size();++i){
	
	}

}
*/

int String::size(){
  return taille_;
}


int String::length(){
  return taille_;
}

void String::reserve(int taille) {
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






















