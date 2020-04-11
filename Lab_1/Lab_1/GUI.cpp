#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
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
int pos_x =    0;
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
    money_load = -1,
    load,
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
    loader,
    users,
    us_category,
    us_products,
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

void UP(int param)
{

    if (pos_y > 1)
        pos_y--;
}
void DOWN(int param)
{
    if (param == user_selection_product_menu)
    {
        if (pos_y < 100)
            pos_y++;

    }
    else
        if (pos_y < 20)
            pos_y++;
}
void LEFT(int param)
{
    if(param != user_selection_product_menu)
        if (pos_x == 1)
            pos_x--;
}
void RIGTH(int param)
{
    if (param != user_selection_product_menu)

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
        case money_load: {Print_selection_users(give_money); break; }
        case load: {Print_selection_users(loader); break; }
        case users_selection_menu: {Print_selection_users(users); break; }
        case user_selection_category_menu: {Print_selection_users(us_category); break; }
        case user_selection_product_menu: {Print_selection_users(us_products); break; }
        }
        
        key = getch();
        switch (key)
        {
            case ArrowUp:
            {
                UP(param);
                break;
            }
            case ArrowDown:
            {
                DOWN(param);
                break;
            }
            case ArrowLeft:
            {
                LEFT(param);
                break;
            }
            case ArrowRight:
            {
                RIGTH(param);
                break;
            }
            case Key_W:
            {
                UP(param);
                break;
            }
            case Key_w:
            {
                UP(param);
                break;
            }
            case Key_S:
            {
                DOWN(param);
                break;
            }
            case Key_s:
            {
                DOWN(param);
                break;
            }
            case Key_D:
            {
                RIGTH(param);
                break;
            }
            case Key_d:
            {
                RIGTH(param);
                break;
            }
            case Key_A:
            {
                LEFT(param);
                break;
            }
            case Key_a:
            {
                LEFT(param);
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
                if (param == user_selection_product_menu)
                {
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
                if (param == user_selection_product_menu)
                {
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
                if (param == user_selection_product_menu)
                {
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
                if (param == user_selection_product_menu)
                {
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
                if (param == user_selection_product_menu)
                {
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
                if (param == user_selection_product_menu)
                {
                    pos_y = 6;
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
                if (param == user_selection_product_menu)
                {
                    pos_y = 7;
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
                if (param == user_selection_product_menu)
                {
                    pos_y = 8;
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
                if (param == user_selection_product_menu)
                {
                    pos_y = 9;
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
        case load://0
            {
                bool exit = 0;
                do { exit = Manager_key(load); } while (!exit);//0
                
                Print_Menu(users_selection_menu);//1
                break;
            }
        case users_selection_menu: //1
            {
                bool exit = 0;
                do { exit=Manager_key(users_selection_menu); } while (!exit);//1
                if (pos_x == 0)
                    Print_Menu(user_selection_category_menu);//2
                else
                    Print_Menu(admin_selection_category_menu);//
                break;
            }
        case user_selection_category_menu://2
            {
                bool exit = 0;

                do { exit = Manager_key(user_selection_category_menu); } while (!exit);//2
                Print_Menu(user_selection_product_menu);//3
                break;
            }
        case user_selection_product_menu://3
            {
            bool exit = 0;

            do { exit = Manager_key(user_selection_product_menu); } while (!exit);//3
//            Print_Menu(user_selection_product_menu); //3

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
    case loader:
        {
            Start_Logo();
            break;
        }
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
                for (int i = 0; i < 5; i++)
                {
                    cout << "    " << C[i].txt << "    "; if (C[i].flag == true) { cout << "[@] "; }
                    else { cout << "[ ]"; cout << "    "; }
                    cout << "             " << C[i+5].txt << "    "; if (C[i+5].flag == true) { cout << "[@] "; }
                    else { cout << "[ ] "; cout << "\n"; }

                }
            }
            cout << "\n\n=======================================================================================================================";
        }
        break;
    case us_products:
    {
        int cat = findCat();
        Products P;
        deque <Products> Prods = {};
        Prods = P.FindCategory(cat);
        cout 
            << "\n\n\n                                             Выбрана <<"<<Prods.front().IgetCATEGORY()<<">> категория\n"
            << "\n======================================================================================================================="
            << "\n======================================================================================================================="
            << "\n=   == №   == Название продукта                                                        == Цена == Маленькая == Большая =="
            << "\n=======================================================================================================================";
        for (Products P : Prods)
        {
            char Name[70];
            
            string str = P.IgetNAME();
            for (int i = 0; i < str.length(); i++)
            {
                Name[i] = str[i];
            }
            for (int i = str.length(); i < 70; i++)
            {
                Name[i] = '\0';
            }
            if (pos_y == P.IgetNUMBER())
            {
                if (P.IgetHIGT_COST() == 0)
                    printf("\n=[X]== %-3d == %-83s == %-4d руб. ==", P.IgetNUMBER(), Name, P.IgetLOW_COST());
                else
                    printf("\n=[X]== %-3d == %-70s == %-4d руб. == %-4d руб. ==", P.IgetNUMBER(), Name, P.IgetLOW_COST(), P.IgetHIGT_COST());

            }
            else
            {
                if (P.IgetHIGT_COST() == 0)
                    printf("\n=[ ]== %-3d == %-83s == %-4d руб. ==", P.IgetNUMBER(), Name, P.IgetLOW_COST());
                else
                    printf("\n=[ ]== %-3d == %-70s == %-4d руб. == %-4d руб. ==", P.IgetNUMBER(), Name, P.IgetLOW_COST(), P.IgetHIGT_COST());

            }
        }
    
        
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
    //int i = findCat();
    //Products p;
    //p.RestoreFile();
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

int findCat()
{
    switch (pos_x)
    {   case 0:
        {
            switch (pos_y)
            {
                case 1:
                {
                    return 1;
                    break;
                }
                case 2:
                {
                    return 2;
                    break;
                }
                case 3:
                {
                    return 3;
                    break;
                }
                case 4:
                {
                    return 4;
                    break;
                }
                case 5:
                {
                    return 5;
                    break;
                }
                default: return 0; break;
            }
            break;
        }
        case 1:
        {
            switch (pos_y)
            {
                case 1:
                {
                    return 6;
                    break;
                }
                case 2:
                {
                    return 7;
                    break;
                }
                case 3:
                {
                    return 8;
                    break;
                }
                case 4:
                {
                    return 9;
                    break;
                }
                default: return 0; break;
            }
            break;
        }
        default: return 0; break;
    }
}



