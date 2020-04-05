#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "GUI.h"
#include <windows.h>
#include <conio.h>
#include <clocale>

#pragma warning(disable : 4996)


using namespace std;

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
    Esc         = 27,
    ArrowUp     = 72,
    ArrowLeft   = 75,
    ArrowRight  = 77,
    ArrowDown   = 80,
    Key_W       = 87,
    Key_S       = 83,
    Key_A       = 65,
    Key_D       = 68,
    Key_w       = 119,
    Key_s       = 115,
    Key_a       = 97,
    Key_d       = 100

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
void UP(void)
{

}
void DOWN(void)
{

}
void LEFT(void)
{

}
void RIGTH(void)
{

}


void GUI::Manager_key(void)
{
    while (int key= 0 != 27)
    {
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

        }
    }
};


void GUI::Give_Money() 
{


};


void GUI::Print_Menu(int lvl)
{
    switch (lvl)
    {
        case load:
            {
                Start_Logo();
                Give_Money();
                GUI::Print_Menu(1);

            }
        case users_selection_menu:
            {

                break;
            }
        case user_selection_category_menu:
            {
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
};


bool GUI::Start_App()
{
    Print_Menu(0);

    return 0;
};


void GUI::Start_Logo()
{
    Logo();
;
};


void GUI::Logo()
{
  cout << "\n┌──────────────────────────────────────────────────────────────────────────────┐\n"
         << "│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│\n"
         << "│░░▓▓▓▓▓▓░░▓▓▓▓▓▓░░Никто не может сделать это так,░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│\n"
         << "│░▓▓░░░░░▓▓░░░░░▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░как это делает McDonald's░░░░│\n"
         << "│░▓▓░░░░░▓▓░░░░░▓▓░░░░░░░▓▓▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░1979г.░│\n"
         << "│░▓▓░░░░░▓▓░░░░░▓▓░░▓▓▓░░▓▓░░▓░░▓▓▓▓░░▓▓▓▓░░░░▓▓▓▓░▓▓░░░░▓▓▓▓▓░▓▓░░▓▓▓▓▓░░░░░░░│\n"
         << "│░▓▓░░░░░▓▓░░░░░▓▓░▓▓░░░░▓▓░░▓░▓▓░░▓▓░▓▓░▓▓░▓▓░░▓▓░▓▓░░░░▓▓░░▓░░▓░▓▓░░░▓▓░░░░░░│\n"
         << "│░▓▓░░░░░▓▓░░░░░▓▓░▓▓░░░░▓▓░░▓░▓▓░░▓▓░▓▓░▓▓░▓▓░░▓▓░▓▓░░░░▓▓░░▓░░░░░░▓▓░░░░░░░░░│\n"
         << "│░▓▓░░░░░▓▓░░░░░▓▓░▓▓░░░░▓▓░░▓░▓▓░░▓▓░▓▓░▓▓░▓▓▓▓▓▓░▓▓░░░░▓▓░░▓░░░▓▓░░░▓▓░░░░░░░│\n"
         << "│░▓▓░░░░░▓▓░░░░░▓▓░░▓▓▓░░▓▓▓▓░░░▓▓▓▓░░▓▓░▓▓░▓▓░░▓▓░▓▓▓▓▓░▓▓▓▓▓░░░░░▓▓▓▓▓░░░░░░░│\n"
         << "│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│\n"
         << "└──────────────────────────────────────────────────────────────────────────────┘\n";
};


void config_Console() 
{
    const LPCTSTR Title = "Laboratory work 1 Skrebnev Leonid FITU POVT 1-5";

    SetConsoleTitle(Title);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");// Задаём русскую локализацию

};





