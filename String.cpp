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

//destructeur : pas de pre-conditions ni de post-conditions
String::~String() {
	taille_=0;
	capacite_=0;
	delete chaine_;
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

 //retourne la capacité
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


void String::clear(){
	taille_=0;
	chaine_[0]='\0';
}


//méthode de test
void String::affichage() {
	for (int i=0; i<taille_; ++i) {
		printf("%c", chaine_[i]);
	}
	printf("\n") ;
}



//OPERATEURS

//additionne les deux string passés en paramètre. Retourne un nouveau string contenant les deux autresconcaténés.
String operator+(const String& s1,const String& s2) {
	String result=String(s1) ; //on copie le premier string dans un nouveau qui sera retourné
	result.taille_=s1.taille_+s2.taille_; 
	result.reserve(s1.capacite_+s2.capacite_); //change la taille et la memoire allouée pour accueillir la concaténation des deux
	
	/*size_t i=s1.taille_;
	while(i<result.taille_) {
		result.chaine_[i]=s2.chaine_[i]; 
		++i ;
	}*/
	for (int i=0;i<s2.taille_+1;i++) { //on ajoute la chaine du deuxieme string à la suite du premier
		result.chaine_[s1.taille_+i]=s2.chaine_[i]; 
	}
	
	return result;
}

//change le string à qui on applique la méthode, change la chaine par le tableau de char pris en paramètre
String& String::operator=(const char* c1) {
	int i=0;
	while(c1[i]!='\0') { //on regarde la taille du tableau de char
		++i;
	}
	taille_=i;
	capacite_=i*2;
	delete[] chaine_; //supprime l'ancienne chaine
	
	chaine_=new char[capacite_] ; //réalloue la mémoire
	
	for(int i=0;i<taille_+1;i++) { //copie le tableau dans la nouvelle chaine 
		chaine_[i]=c1[i] ;
	}
}


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

// Operateur +(char) : Renvoie un nouveau string dont la valeur est la concaténation d'un string existant et d'un caractère donnés en paramètre

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


