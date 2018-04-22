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
	// les attributs du nouveau string ont les mêmes valeurs que le string dont l'adresse est passée en paramètre
	taille_=s.taille_; //taille
	capacite_=s.capacite_; //capacité
	char* newchaine =new char[capacite_];
	int i;
  for (i=0;i<taille_;++i){ //valeurs du tableau
  	newchaine[i] = s.chaine_[i];
	}
  newchaine[taille_+1] = '\0'; //rajout du \0 au tableau du nouveau string
	chaine_=newchaine; //chaîne
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


//getters 
char* String::c_str(){
	return chaine_; //récupère l'attribut chaîne du string considéré et le retourne
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

.
String& String::operator=(const String& str){
	// on supprime la chaine qui a été créée pour ne pas avoir de fuite mémoire
	delete chaine_;
	// on donne les mêmes valeurs des attributs du string dont l'adresse est passée en paramètre
	taille_=str.taille_; //taille
	capacite_=str.capacite_; //capacité
	char* newstr = new char [capacite_];
	int i;
	for (i=0;i<taille_;++i){ //valeurs du tableau	
  	newstr[i] = str.chaine_[i];
	}
	newstr[taille_+1] = '\0'; //rajout du \0 au tableau du nouveau string
	chaine_=newstr; //chaîne
	return *this;
}

// Renvoie un nouveau string dont la valeur est la concaténation d'un string existant et d'un caractère

String operator+(const String& str, char c){
	String s(str);
	if(str.capacite_>=str.taille_+2){
		s.taille_=s.taille_+1;
		s.chaine_[s.taille_-1]=c;
		s.chaine_[s.taille_]='\0';
	}
	else{
		s.reserve(s.taille_+2);
		s.taille_=s.taille_+1;
		s.chaine_[s.taille_-1]=c;
		s.chaine_[s.taille_]='\0';
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
