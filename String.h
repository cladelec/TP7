class String {
	protected :
		//attributs
		int taille_;
		char* chaine_;
		int capacite_;
		static int MAX_SIZE;
		
	public :
		//constructeurs
		String();
		//String(String s);
		//String(int taille, char* chaine);

		bool empty();
		void destructor() ;
		
		//getters
		int length();
		int size();
		char* c_str();
		int capacity();
		
		//operateurs
		//String operator+(String s1,String s2) ;
		//bool operator==(String s1, char* c1) ;


} ;
