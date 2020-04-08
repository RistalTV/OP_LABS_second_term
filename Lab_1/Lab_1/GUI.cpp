#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "GUI.h"
#include <windows.h>
#include <conio.h>
#include <deque>
#include <clocale>
#include "Product.h"

#pragma warning(disable : 4996)


using namespace std;

/// Глобальные переменные
int pos_x   =    0;
int pos_y   =    0;


/// Структуры
struct cat
{
    string txt = "\0";
    bool flag  = false;
    int posX   = 0;
    int posY   = 0;
};

/// Перечисления
enum levels
{
    load = 0,
    users_selection_menu,
    user_selection_category_menu,
    user_selection_product_menu,
    admin_selection_category_menu,
    admin_selection_categor_menu
};
enum Keys
{
    Esc = 27,
    Enter = 13,
    ArrowUp = 72,
    ArrowLeft = 75,
    ArrowRight = 77,
    ArrowDown = 80,
    Key_W = 87,
    Key_S = 83,
    Key_A = 65,
    Key_D = 68,
    Key_w = 119,
    Key_s = 115,
    Key_a = 97,
    Key_d = 100,
    Key_1 = 49,
    Key_2 = 50,
    Key_3 = 51,
    Key_4 = 52,
    Key_5 = 53,
    Key_6 = 54,
    Key_7 = 55,
    Key_8 = 56,
    Key_9 = 57

};
enum locations
{
    give_money=-1,
    users=0,
    us_category,
    us_product,
    adm_cats
};
enum Colors
{
    Black=0,    Blue,           Green, 
    Cyan,       Red,            Magenta, 
    Brown,      LightGray,      DarkGray, 
    LightBlue,  LightGreen,     LightCyan, 
    LightRed,   LightMagenta,   Yellow, 
    White
};

/// Конструктор начальный
GUI::GUI()
{
    Iset_money(1000);


};

/// Интерфейсы
int GUI::Iget_money()
{
    return _money;
};
void GUI::Iset_money(int cost)
{
    if (cost > 1)
        _money = cost;
}

/// Простые перемещения по меню

void UP(void)
{
    if (pos_y > 1)
        pos_y--;
}
void DOWN(void)
{
    if (pos_y < 20)
        pos_y++;
}
void LEFT(void)
{
    if (pos_x == 1)
        pos_x--;
}
void RIGTH(void)
{
    if (pos_x == 0)
        pos_x++;
}


bool GUI::Manager_key(int param)
{
    int key = 0;
    while (key != Esc)
    {
        system("cls");
        Logo();
        switch (param)
        {
        case 0: {Print_selection_users(-1); break; }
        case 1: {Print_selection_users(0); break; }
        case 2: {Print_selection_users(1); break; }
        case 3: {Print_selection_users(2); break; }
        }
        
        key = getch();
        switch (key)
        {
            case ArrowUp:
            {
                UP();
                break;
            }
            case ArrowDown:
            {
                DOWN();
                break;
            }
            case ArrowLeft:
            {
                LEFT();
                break;
            }
            case ArrowRight:
            {
                RIGTH();
                break;
            }
            case Key_W:
            {
                UP();
                break;
            }
            case Key_w:
            {
                UP();
                break;
            }
            case Key_S:
            {
                DOWN();
                break;
            }
            case Key_s:
            {
                DOWN();
                break;
            }
            case Key_D:
            {
                RIGTH();
                break;
            }
            case Key_d:
            {
                RIGTH();
                break;
            }
            case Key_A:
            {
                LEFT();
                break;
            }
            case Key_a:
            {
                LEFT();
                break;
            }
            case Enter:
            {
                return 1;
            }
            case Key_1:
            {
                if (param == 0)
                {
                    Iset_money(Iget_money() + 10);
                }
                if (param == 2)
                {
                    pos_x = 0;
                    pos_y = 1;
                }
                break;
            }
            case Key_2:
            {
                if (param == 0)
                {
                    Iset_money(Iget_money() + 100);
                }
                if (param == 2)
                {
                    pos_x = 0;
                    pos_y = 2;
                }
                break;
            }
            case Key_3:
            {
                if (param == 0)
                {
                    Iset_money(Iget_money() + 1000);
                }
                if (param == 2)
                {
                    pos_x = 0;
                    pos_y = 3;
                }
                break;
            }
            case Key_4:
            {
                if (param == 0)
                {
                    Iset_money(Iget_money() - 10);
                }
                if (param == 2)
                {
                    pos_x = 0;
                    pos_y = 4;
                }
                break;
            }
            case Key_5:
            {
                if (param == 0)
                {
                    Iset_money(Iget_money() - 100);
                }
                if (param == 2)
                {
                    pos_x = 0;
                    pos_y = 5;
                }
                break;
            }
            case Key_6:
            {
                if (param == 0)
                {
                    Iset_money(Iget_money() - 1000);
                }
                if (param == 2)
                {
                    pos_x = 1;
                    pos_y = 1;
                }
                break;
            }
            case Key_7:
            {
                if (param == 2)
                {
                    pos_x = 1;
                    pos_y = 2;
                }
                break;
            }
            case Key_8:
            {
                if (param == 2)
                {
                    pos_x = 1;
                    pos_y = 3;
                }
                break;
            }
            case Key_9:
            {
                if (param == 2)
                {
                    pos_x = 1;
                    pos_y = 4;
                }
                break;
            }
        }
    }
};


void GUI::Print_Menu(int lvl)
{
    switch (lvl)
    {
        case load:
            {
                Start_Logo();
                bool exit = 0;
                do { exit = Manager_key(0); } while (!exit);
                
                Print_Menu(1);
                break;
            }
        case users_selection_menu:
            {
                bool exit = 0;
                do { exit=Manager_key(1); } while (!exit);
                if (pos_x == 0)
                    Print_Menu(user_selection_category_menu);
                else
                    Print_Menu(admin_selection_category_menu);
                break;
            }
        case user_selection_category_menu:
            {
                bool exit = 0;

                do { exit = Manager_key(2); } while (!exit);
                break;
    }
        case user_selection_product_menu:
            {
        break;
    }
        case admin_selection_category_menu:
            {
        break;
    }

    }
}
void GUI::Print_selection_users(int location)
{   
    bool first_run = true;
    switch (location)
    {
    case give_money:
        {
            int money = 1;
            cout << "\n\n======================================================================================================================"
                << "\n\n\n\t\t\tУстановите начальную сумму:\n\n\t\t\t\t"<< Iget_money();
                
            pos_y = 2;
            if (pos_y > 2)
            {
                pos_y = 2;
                Iset_money(Iget_money() + 10);
            } 
            else
            {
                pos_y = 2;
                Iset_money(Iget_money() - 10);
            }

            
            cout << "\n\n======================================================================================================================\n"
                << "====               1)Увеличить на 10 руб.  ==  2)Увеличить на 100 руб.  ==  3)Увеличить на 1000 руб.               ===\n"
                << "======================================================================================================================\n"
                << "====               4)Уменьшить на 10 руб.  ==  5)Уменьшить на 100 руб.  ==  6)Уменьшить на 1000 руб.               ===\n"
                << "======================================================================================================================\n";
        }
        break;
    case users:
        {
        cout << "\n\n======================================================================================================================="
            << "\n\n\n                                                  Выберите пользователя:\n\n"
            << "                                                                                 ######\n"
            << "                                   #####                                         ######\n"
            << "                                 #########                                  ############\n"
            << "                                ###^###^###                                   ###^###^###\n"
            << "                                #####\"#####                                 #####\"#####\n"
            << "                                 ###---###                                     ###---###\n"
            << "                             \\     #####     /                             \\     #####     /\n"
            << "                              \\  #########  /                               \\  #########  /\n"
            << "                               \\###########/                                 \\###########/ \n"
            << "                               #############                                 ### ### #####   \n"
            << "                              ###############                               ## ### ### ####  \n"
            << "                              ###############                               ## ### ### ####  \n"
            << "                              ###############                               ###############  \n\n"
            << "                                 Покупатель                                  Администратор\n";

        if (pos_x == 0)
            for (int i = 0; i < 30; i++)
                cout << " ";
        else
            for (int i = 0; i < 76; i++)
                cout << " ";
        cout << "^^^^^^^^^^^^^^^";
        cout << "\n\n=======================================================================================================================";
    }
        break;
    case us_category:
        {
            cout << "\n\n======================================================================================================================="
                << "\n\n\n                                                  Выберите нужную категорию\n";
            cat C[9];
            C[0] = { "1) Сандвичи            ", false, 0, 1 };
            C[1] = { "2) Картофель и стартеры", false, 0, 2 };
            C[2] = { "3) Салаты и роллы      ", false, 0, 3 };
            C[3] = { "4) Десерты и выпечка   ", false, 0, 4 };
            C[4] = { "5) Напитки и коктейли  ", false, 0, 5 };
            C[5] = { "6) Кофе, чай           ", false, 1, 1 };
            C[6] = { "7) Соусы               ", false, 1, 2 };
            C[7] = { "8) МакЗавтрак          ", false, 1, 3 };
            C[8] = { "9) Другие продукты     ", false, 1, 4 };
            {
                for (int i=0;i<9;i++)
                    if ((C[i].posX == pos_x) && (C[i].posY == pos_y))
                    {
                        for (int j = 0; j < 9; j++)
                            C[j].flag = false;
                        C[i].flag = true;
                    }
                if (pos_y > 4)
                    pos_y = 4;
                ///if (first_run == true) { C[0].flag = true; first_run = false; }
            }
            /// вывод на экран список категорий
            {
                cout << "    " << C[0].txt << "    "; if (C[0].flag == true) { cout << "[@] "; }
                else { cout << "[ ]"; cout << "    "; }
                cout << "             " << C[5].txt << "    "; if (C[5].flag == true) { cout << "[@] "; }
                else { cout << "[ ] "; cout << "\n"; }
                cout << "    " << C[1].txt << "    "; if (C[1].flag == true) { cout << "[@] "; }
                else { cout << "[ ] "; cout << "    "; }
                cout << "                " << C[6].txt << "    "; if (C[6].flag == true) { cout << "[@] "; }
                else { cout << "[ ] "; cout << "\n"; }
                cout << "    " << C[2].txt << "    "; if (C[2].flag == true) { cout << "[@] "; }
                else { cout << "[ ] "; cout << "    "; }
                cout << "            " << C[7].txt << "    "; if (C[7].flag == true) { cout << "[@] "; }
                else { cout << "[ ] "; cout << "\n"; }
                cout << "    " << C[3].txt << "    "; if (C[3].flag == true) { cout << "[@] "; }
                else { cout << "[ ] "; cout << "    "; }
                cout << "            " << C[8].txt << "    "; if (C[8].flag == true) { cout << "[@] "; }
                else { cout << "[ ] "; cout << "\n"; }
                cout << "    " << C[4].txt << "    "; if (C[4].flag == true) { cout << "[@] "; }
                else { cout << "[ ] "; cout << "    "; }

            }
            cout << "\n\n=======================================================================================================================";
        }
        break;
    case us_product:
        {
            
        }
        break;
    case adm_cats:
        {
    
        }
        break;
    }


}
;



bool GUI::Start_App()
{
    Products p;
    p.RestoreFile();
//    Print_Menu(0);
    return 0;
};


void GUI::Start_Logo()
{
    Logo();
;
};


void GUI::Logo()
{            
  cout << "\n           ===============================================================================================\n"
       << "           =                                                                                             =\n"
       << "           =       ######    ######  Никто не может сделать это так,                                     =\n"
       << "           =      ########  ########                                                                     =\n"
       << "           =      ###     ###     ###                                как это делает McDonald's           =\n"
       << "           =      ###     ###     ###       ####                                                1979г.   =\n"
       << "           =      ###     ###     ###  ###  ##  #  ####  ####    #### ##    ##### ##  #####              =\n"
       << "           =      ###     ###     ### ##    ##  # ##  ## ## ## ##  ## ##    ##  #  # ##   ##             =\n"
       << "           =      ###     ###     ### ##    ##  # ##  ## ## ## ##  ## ##    ##  #      ##                =\n"
       << "           =      ###     ###     ### ##    ##  # ##  ## ## ## ###### ##    ##  #   ##   ##              =\n"
       << "           =      ##3     ###     ###  ###  ####   ####  ## ## ##  ## ##### #####     #####              =\n"
       << "           =                                                                                             =\n"
       << "           ===============================================================================================\n";
};


void config_Console() 
{
    const LPCTSTR Title = "Laboratory work 1 Skrebnev Leonid FITU POVT 1-5";

    SetConsoleTitle(Title);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");// Задаём русскую локализацию

};





