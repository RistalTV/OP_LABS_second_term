#include "GUI.h"

using namespace std;
 
int main()
{
	config_Console();
	GUI I;
	bool exit = 0;
	do {
		exit = I.Start_App();
	} while (exit);
	return 0;
}
