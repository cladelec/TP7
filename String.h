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
		String(char* ch);
		//String(int taille, char* chaine);

		bool empty();
		
		//getters
		int length();
		char* get_chaine();
		int size();
		char* c_str();
		int capacity();
		int max_size();
} ;
