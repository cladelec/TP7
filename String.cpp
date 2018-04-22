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
  while (ch[i] != '\0') { //calcul taille
    ++i;
    }
  taille_ = i; //attributs du string définis par rapport au char*
  capacite_ = taille_*2;
  chaine_ = new char[capacite_ +1];
  for (int j =0; j < taille_; j++){
    chaine_[j] = ch[j]; //valeurs du char* dans la chaine de string
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




//getters 
char* String::c_str(){
	return chaine_; //récupère l'attribut chaine du string considéré et le retourne
}

 //retourne la capacité
size_t String::capacity(){
	return capacite_;
}

size_t String::length(){
  return taille_; //retourne l'attribut taille
}

size_t String::max_size(){
  return MAX_SIZE; //retourne la taille maximale
  }

size_t String::size(){
  return taille_; //retourne l'attribut taille
}

//Redimensionne la chaîne à une longueur de n caractères.
void String::resize (size_t n){ //si n plus petit que la taille du string de départ
  chaine_[n] = '\0';
  taille_ =n;
}

void String::resize (size_t n, char c){//si n plus grand que la taille de départ, complète toutes les cases vides par la caractère c
    for( int i = taille_; i<=n; i++){
      reserve(n*2);
      chaine_[i] = c;
      taille_ =n;
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

//Efface le contenu de la chaîne
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

//Operateur =(string) : Affecte de nouvelles valeurs au string, en remplaçant son contenu actuel par les valeurs d'un string dont l'adresse est passée en paramètre 
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

//Operateur +(char) : Renvoie un nouveau string dont la valeur est la concaténation d'un string existant et d'un caractère donnés en paramètre
String operator+(const String& str, char c){
	String s(str); //nouveau string identique au string auquel on veut rajouter un caractère grâce au constructeur par copie
	if(s.capacite_>=s.taille_+2){ //vérification que la capacité du string créé est suffisante pour ajouter un nouveau caractère (il faut aussi rajouter \0 à la fin donc +2)
		s.taille_=s.taille_+1;
		s.chaine_[s.taille_-1]=c; //on rajoute le caractère à la fin
		s.chaine_[s.taille_]='\0'; //on rajoute le \0 à l afin du tableau
	}
	else{ //la capacité est insuffisante, il faut donc l'augmenter
		s.reserve(s.taille_+2); //augmentation de 2 pour avoir la place pour le nouveau caractère et le \0
		s.taille_=s.taille_+1;
		s.chaine_[s.taille_-1]=c;
		s.chaine_[s.taille_]='\0';
	}
	return s;
}

//Affecte une nouvelle valeur à la chaîne, en remplaçant son contenu actuel par un caractère
String& String::operator= (const char s){
	taille_=1;
	capacite_=2;
	delete[] chaine_; 
	
	chaine_=new char[capacite_] ; 
	chaine_[0]=s;
	chaine_[1]='\0';
}

//Renvoie un objet chaîne nouvellement construit dont la valeur est la concaténation d'un string et d'un char*
String operator+(const String& str, char* c) {
  String result=String(str) ; 
  size_t i = 0;
  while (c[i] != '\0') {
    ++i;
    }
	result.taille_=str.taille_+i; 
	result.reserve(result.taille_*2); 
	for (int j=0;j<i+1;j++) { 
		result.chaine_[str.taille_+j]=c[j]; 
	}
	
	return result;
}
  


