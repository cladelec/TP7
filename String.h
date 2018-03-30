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
		
		//getters
		int get_taille();
		char* get_chaine();
		int get_capacite();

} ;
