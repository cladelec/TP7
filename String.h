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
		//String(int taille, char* chaine);

		bool empty();
		
		//getters
		int length();
		char* get_chaine();
		int get_capacite();
		int max_size();

} ;
