class GUI
{
	public:
		GUI();									 //	Конструктор класса
		void Start_Logo(void);					 //	
		bool Start_App();						 //	Прорисовка меню
		void Logo(void);						 //	Прорисовка лого
		void Give_Money(void);					 //	Получене денег
		int  Iget_money(void);					 //	Инерфейс для работы(получения) с переменной _money
		void Iset_money(int cost);				 //	Инерфейс для работы(установления) с переменной _money
		void Manager_key(void);					 //	Метод управления клавиатурой
		void Print_Menu(int lvl);				 //	Прорисовка меню
		void Print_selection_users(int location);//	Прорисовка выбора пользователя
		
	private:

		int _money;			//	Кол-во денег в начале

		
};

void config_Console();