#include <cstdio>
#include <windows.h>
#include <conio.h>
#include <Winuser.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int getKey()
{
	int buttonpressed = 0;
	while (!buttonpressed){
		for (int i = 0; i < 255; i++){
			if (GetKeyState(i) < 0){buttonpressed = i;}
		}
	}
	while (GetKeyState(buttonpressed) < 0){;}
	return buttonpressed;
}

char ch;
long a[256] = {0};
long b[10] = {0};
int temp;
string layoutSettings="qwerty";
short escExit = 3;

void printDVORAK()
{
    system("cls");
        printf("\n  esc\t1\t2\t3\t4\t5\t6\t7\t8\t9\t0\t[\t]\t<x Backspace\n");
        printf("  %d", a[27]);
        for(int re = 49; re <= 57; re++)
        {
            printf("\t%d", a[re]);
        }
        printf("\t%d", a[48]);
        printf("\t%d\t%d\t%d\n", a[219], a[221], a[8]);
        printf("\n  Tab\t'\t,\t.\tP\tY\tF\tG\tC\tR\tL\t/\t=\t\\\n");
        printf("  %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[9], a[222], a[188], a[190], a[80], a[89], a[70], a[71], a[67], a[82], a[76], a[191], a[187], a[220]);
        printf("\n  Caps\t\tA\t0\tE\tU\tI\tD\tH\tT\tN\tS\t-\tEnter\n");
        printf("  %d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[20], a[65], a[79], a[69], a[85], a[73], a[68], a[72], a[84], a[78], a[83], a[189], a[13]);
        printf("\n  Shift\t\t;\tQ\tJ\tK\tX\tB\tM\tW\tV\tZ\n");
        printf("  %d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[16], a[186], a[81], a[74], a[75], a[88], a[66], a[77], a[87], a[86], a[90], a[38], a[37], a[40], a[39]);
        printf("\n  Ctrl \t Supr\t Alt\t\t\t\t\t\t\tHome\tEnd\n");
        printf("  %d\t %d\t %d\t\t\t%d\t\t\t\t%d\t%d\n", a[17], b[0], a[18], a[32], a[36], a[35]);
        printf("\n\t¡ô\t¡ö\t¡õ\t¡÷\n");
        printf("\t%d\t%d\t%d\t%d\n", a[38], a[37], a[40], a[39]);
}

void printQWERTY()
{
    system("cls");
        printf("\n  esc\t1\t2\t3\t4\t5\t6\t7\t8\t9\t0\t-\t=\t<x Backspace\n");
        printf("  %d", a[27]);
        for(int re = 49; re <= 57; re++)
        {
            printf("\t%d", a[re]);
        }
        printf("\t%d", a[48]);
        printf("\t%d\t%d\t%d\n", a[189], a[187], a[8]);
        printf("\n  Tab\tQ\tW\tE\tR\tT\tY\tU\tI\tO\tP\t[\t]\t\\\n");
        printf("  %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[9], a['Q'], a['W'], a['E'], a['R'], a['T'], a['Y'], a['U'], a['I'], a['O'], a['P'], a[219], a[221], a[220]);
        printf("\n  Caps\t\tA\tS\tD\tF\tG\tH\tJ\tK\tL\t;\t'\tEnter\n");
        printf("  %d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[20], a['A'], a['S'], a['D'], a['F'], a['G'], a['H'], a['J'], a['K'], a['L'], a[186], a[222], a[13]);
        printf("\n  Shift\t\tZ\tX\tC\tV\tB\tN\tM\t,\t.\t/\n");
        printf("  %d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[16], a['Z'], a['X'], a['C'], a['V'], a['B'], a['N'], a['M'], a[188], a[190], a[191], a[38], a[37], a[40], a[39]);
        printf("\n  Ctrl \t Supr\t Alt\t\t\t\t\t\t\tHome\tEnd\n");
        printf("  %d\t %d\t %d\t\t\t%d\t\t\t\t%d\t%d\n", a[17], b[0], a[18], a[32], a[36], a[35]);
        printf("\n\t¡ô\t¡ö\t¡õ\t¡÷\n");
        printf("\t%d\t%d\t%d\t%d\n", a[38], a[37], a[40], a[39]);
}

int main()
{
    short esc = 0;
    string escExitstr;
    ifstream file_layout("Program_settings.txt");
    getline(file_layout, layoutSettings);
    getline(file_layout, escExitstr);
    escExit = stoi(escExitstr) - 1;
    printf("\n\tClick your mouse or press any key on your keyboard to use.\n\tType esc key %d times in a row to exit program.", escExit+1);

    while (1)
    {
        //if(GetAsyncKeyState(VK_SHIFT) & 0x8000){ a[16]++; }
        //if(GetKeyState(VK_CONTROL)){ a[17]++; printf("%d", GetKeyState(VK_CONTROL)); }
        //if(GetKeyState(VK_MENU)){ a[18]++; } //Alt
        //if(GetKeyState(VK_LWIN)){ b[0]++; }
        //https://stackoverflow.com/questions/41600981/how-do-i-check-if-a-key-is-pressed-on-c
        if (temp = getKey())
        {
            ch = temp;
            a[temp]++;

            if(layoutSettings == "dvorak")
            {
                printDVORAK();
            }
            else if(layoutSettings == "qwerty")
            {
                printQWERTY();
            }
            else
            {
                printQWERTY();
                printf("!!!!!! Please check Program_settings.txt. !!!!!!\n        If you don't know how to fix, please check \"How to change keyboard layout.txt\".\n");
            }

            if (ch == 27){ esc++; if (esc >= escExit){ break; } } //27=esc
            else { esc = 0; }
        }
    }
    system("pause");
    return 0;
}

/* Special thanks:
   https://www.twblogs.net/a/5d24d21abd9eee1e5c841228
   http://www.cplusplus.com/forum/windows/334/
   https://en.wikipedia.org/wiki/File:KB_United_States_Dvorak.svg        */