class GUI
{
	public:
		GUI();									 //	����������� ������
		void Start_Logo(void);					 //	
		bool Start_App();						 //	���������� ����
		void Logo(void);						 //	���������� ����
		void Give_Money(void);					 //	�������� �����
		int  Iget_money(void);					 //	�������� ��� ������(���������) � ���������� _money
		void Iset_money(int cost);				 //	�������� ��� ������(������������) � ���������� _money
		void Manager_key(void);					 //	����� ���������� �����������
		void Print_Menu(int lvl);				 //	���������� ����
		void Print_selection_users(int location);//	���������� ������ ������������
		
	private:

		int _money;			//	���-�� ����� � ������

		
};

void config_Console();