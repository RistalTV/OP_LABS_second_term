using namespace std;

class Products
{
	public:
		Products();
		Products(string category, string name, int low_cost, int higt_cost);
		void	 IsetNAME(string name);
		void	 IsetCATEGORY(string category);
		void	 IsetLOW_COST(int low_cost);
		void	 IsetHIGT_COST(int higt_cost);
		void	 IsetINT_CATEG(int int_categ);
		string	 IgetNAME();
		string	 IgetCATEGORY();
		int		 IgetLOW_COST();
		int		 IgetHIGT_COST();
		int		 IgetINT_CATEG();
		deque<Products> GetListProd();
		void AddItemToFile(int cat, string name, int low_cost, int higt_cost);
		void AddItemToFile(int cat, string name, int low_cost);
		void ClearToFile();
		void RestoreFile();
	private:
		Products Purse(string line);
		deque<Products> GetListProd(int loc);
		void AddItemToFile(int loc, int cat, string name, int low_cost, int higt_cost);
		string _category;
		string _name;
		int _low_cost;
		int _higt_cost;
		int _int_categ;
};