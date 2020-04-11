#include <iostream>
#include <fstream>
#include <deque>
#include "Product.h"
#include <string>
#include <array>
#include <cstdlib>
#include <filesystem>
#include <filesystem>

using namespace std;

Products::Products()
{
	IsetCATEGORY("\0");
	IsetNAME("\0");
	IsetLOW_COST(0);
	IsetHIGT_COST(0);
}

Products::Products(string category, string name, int low_cost, int higt_cost)
{
	IsetCATEGORY(category);
	IsetNAME(name);
	IsetLOW_COST(low_cost);
	IsetHIGT_COST(higt_cost);
}



void Products::IsetNAME(string name)
{
	_name = name;
}

void Products::IsetCATEGORY(string category)
{
	_category = category;
}

void Products::IsetLOW_COST(int low_cost)
{
	if (low_cost > 0)
		_low_cost = low_cost;
}

void Products::IsetHIGT_COST(int higt_cost)
{
	if (higt_cost > _low_cost)
		_higt_cost = higt_cost;
}

void Products::IsetINT_CATEG(int int_categ)
{
	if ((int_categ < 0) || (int_categ > 9))
		_int_categ = 0;
	else
		_int_categ = int_categ;
}

void Products::IsetNUMBER(int number)
{
	if (number > 0)
		_number = number;
}

string Products::IgetNAME()
{
	return _name;
}

string Products::IgetCATEGORY()
{
	return _category;
}

int Products::IgetLOW_COST()
{
	return _low_cost;
}

int Products::IgetHIGT_COST()
{
	return _higt_cost;
}

int Products::IgetINT_CATEG()
{
	return _int_categ;
}

int Products::IgetNUMBER()
{
	return _number;
}

deque<Products> Products::GetListProd()
{
	return GetListProd(0);
}


void Products::AddItemToFile(int cat, string name, int low_cost, int higt_cost)
{
	AddItemToFile(0, cat, name, low_cost, higt_cost);
}


deque<Products> Products::GetListProd(int loc)
{
	string path = "mak.dat";
	switch (loc)
	{
	case 1 : {path = "mak_default.dat"; break; }
	default: {path = "mak.dat";			break; }
	}
	string line;
	deque<Products> Prod;
	Products p;
	ifstream in(path);	// окрываем файл для чтения
	int number = 1;
	int temp_cat = 0;
	int temp_cat1 = 0;
	if (in.is_open())
	{
		while (getline(in, line))
		{
			p = Purse(line);
			p.IsetNUMBER(number);
			number++;
			if (p.IgetINT_CATEG() != temp_cat)
			{
				temp_cat = p.IgetINT_CATEG();
				number = 1;
			}
			Prod.push_back(p);
		}
	}
	else
	{
		system("cls");
		cout << "Error: Файл не открыт. Файл - "<< path;
	}
		
	in.close();     // закрываем файл
	
	return Prod;
}


int TranslateCharToInt(char val)
{
	switch (val)
	{
	case ('0'):
	{
		return 0;
		break;
	}
	case ('1'):
	{
		return 1;
		break;
	}
	case ('2'):
	{
		return 2;
		break;
	}
	case ('3'):
	{
		return 3;
		break;
	}
	case ('4'):
	{
		return 4;
		break;
	}
	case ('5'):
	{
		return 5;
		break;
	}
	case ('6'):
	{
		return 6;
		break;
	}
	case ('7'):
	{
		return 7;
		break;
	}
	case ('8'):
	{
		return 8;
		break;
	}
	case ('9'):
	{
		return 9;
		break;

	}
	}
}


int TranslateStrToInt(string text)
{
	switch (text.length())
	{
	case 1:
	{
		return TranslateCharToInt(text[0]);
		break;
	}
	case 2:
	{
		return TranslateCharToInt(text[0]) * 10 + TranslateCharToInt(text[1]);
		break;
	}
	case 3:
	{
		return TranslateCharToInt(text[0]) * 100 + TranslateCharToInt(text[1]) * 10 + TranslateCharToInt(text[2]);
		break;
	}
	case 4:
	{
		return TranslateCharToInt(text[0]) * 1000 + TranslateCharToInt(text[1]) * 100 + TranslateCharToInt(text[2]) * 10 + TranslateCharToInt(text[3]);
		break;
	}
	}
}


void Products::AddItemToFile(int loc,int cat, string name, int low_cost, int higt_cost)
{
	string path = "mak.dat";
	switch (loc)
	{
	case 1:  { path = "mak_default.dat"; break; }
	default: { path = "mak.dat";		 break; }
	}
	if ((cat < 0) || (cat > 8))
		cat = 0;
	ofstream fout(path, ios_base::app); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	fout << cat << "|" << name << "|" << low_cost << "|" << higt_cost << "|\n"; // запись строки в файл
	fout.close();

}
void Products::AddItemToFile(int cat, string name, int low_cost)
{
	if ((cat < 0) || (cat > 8))
		cat = 0;
	ofstream fout("mak.dat", ios_base::app); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	fout << cat << "|" << name << "|" << low_cost << "|0|\n"; // запись строки в файл

	fout.close();
}

void Products::ClearToFile()
{
	ofstream fout("mak.dat"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	fout << ""; // запись строки в файл
	fout.close(); // закрываем файл
}

void Products::RestoreFile()
{
	deque<Products> Prod = {};
	Prod = GetListProd(1);
	ClearToFile();
	for (Products p : Prod)
	{
		AddItemToFile(p.IgetINT_CATEG(), p.IgetNAME(), p.IgetLOW_COST(), p.IgetHIGT_COST());
	}

}

deque<Products> Products::FindCategory(int cat)
{
	deque <Products> Prod = {};
	deque <Products> P = {};
	P = GetListProd();
	for (Products p1 : P)
	{
		if (p1.IgetINT_CATEG() == cat)
		{
			Prod.push_back(p1);
		}
	}

	return Prod;
}

Products Products::Purse(string line)
{
	int i = 0;
	unsigned int number_of_delimiters = 0;
	Products p;
	string cat;
	string name;
	string low_cost;
	string higt_cost;

	for (char val : line)
	{
		switch (i)
		{
			case 0:
			{
				if (val != '|') {
					cat=val;
				}
				i++;
				break;
			}
			case 1:
			{
				if (val == '|')
					number_of_delimiters++;
				if (val != '|') {
					name.push_back(val);
				}
				if (number_of_delimiters == 2)
				{
					number_of_delimiters = 0;
					i++;
				}
				break;
			}
			case 2:
			{
				if (val == '|')
					number_of_delimiters++;
				if (val != '|') {
					low_cost.push_back(val);
				}
				if (number_of_delimiters == 1)
				{
					number_of_delimiters = 0;
					i++;
				}
				break;
			}
			case 3:
			{
				if (val == '|')
					number_of_delimiters++;
				if (val != '|') {
					higt_cost.push_back(val);
				}
				if (number_of_delimiters == 2)
				{
					number_of_delimiters = 0;
					i++;
				}
				break;
			}
		}
	}
	array<string, 9> categ
	{
		"Сандвичи",             //0
		"Картофель и стартеры", //1
		"Салаты и роллы",       //2
		"Десерты и выпечка",    //3
		"Напитки и коктейли",   //4
		"Кофе, чай",            //5
		"Соусы",                //6
		"МакЗавтрак",           //7
		"Другие продукты"		//8
	};
	i = TranslateStrToInt(cat);
	p.IsetCATEGORY(categ.at(((i>8)||(i < 0)) ? 0 : i));
	p.IsetNAME(name);
	p.IsetLOW_COST(TranslateStrToInt(low_cost));
	p.IsetHIGT_COST(TranslateStrToInt(higt_cost));
	p.IsetINT_CATEG(TranslateStrToInt(cat));
	return p;
}
