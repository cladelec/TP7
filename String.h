#ifndef STRING_H_
#define STRING_H_

#include <cstdio>
#include <cstdlib>

class String {
	protected :
		//attributs
		size_t taille_;
		char* chaine_;
		size_t capacite_;
		static int MAX_SIZE;
		
	public :
		//constructeurs
		String();
		//String(String s);
		//String(int taille, char* chaine);

		bool empty();
		~String() ; //destructeur
		
		//getters
		size_t length();
		size_t size();
		char* c_str();
		size_t capacity();
		
		void reserve(size_t taille) ;
		
		//operateurs
		//String operator+(const String s1) ;
		String& operator=(const char* c1) ;


} ;

#endif
