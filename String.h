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
		static size_t MAX_SIZE;
		
	public :
		//constructeurs
		String();
		String(const String &s);
		String(char* ch);

		bool empty();
		~String() ; //destructeur
		void clear();

		//getters
		size_t length();
		size_t size();
		char* c_str();
		size_t capacity();
		size_t max_size() ;
		
		void reserve(size_t taille) ;
		void resize (size_t n, char c) ;
		
		//operateurs
		String& operator= (const String& str);
		friend String operator+(const String& str, char c);
		friend String operator+(const String& str, char* c);
		String operator+(const String s1);
		String& operator=(const char* c1);
		String& operator=(const char s);


} ;
String operator+(const String& str, char c);
String operator+(const String& str, char* c);

#endif
