class GUI
{
	public:
		GUI();									 //	����������� ������
		void Start_Logo(void);					 //	
		bool Start_App();						 //	���������� ����
		void Logo(void);						 //	���������� ����
		int  Iget_money(void);					 //	�������� ��� ������(���������) � ���������� _money
		void Iset_money(int cost);				 //	�������� ��� ������(������������) � ���������� _money
		bool Manager_key(int param);					 //	����� ���������� �����������
		void Print_Menu(int lvl);				 //	���������� ����
		void Print_selection_users(int location);//	���������� ������ ������������
		
	private:

		int _money;			//	���-�� ����� � ������

		
};

int findCat(void);
void config_Console(void);