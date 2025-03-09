#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

//To Movse Cursor to X and Y
void gotoxy1(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//To Change Color
void SetColorAndBackground(int ForgC, int BackC = 0)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void clear_screen()
{
    DWORD n; /* Number of characters written */
    DWORD size; /* number of visible characters */
    COORD coord = { 0 }; /* Top left screen position */
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    /* Get a handle to the console */
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h, &csbi);
    /* Find the number of characters to overwrite */
    size = csbi.dwSize.X * csbi.dwSize.Y;
    /* Overwrite the screen buffer with whitespace */
    FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
    GetConsoleScreenBufferInfo(h, &csbi);
    FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
    /* Reset the cursor to the top left position */
    SetConsoleCursorPosition(h, coord);
}

#pragma region Colors
/*BLACK        0
BLUE           1
GREEN          2
CYAN           3
RED            4
MAGENTA        5
BROWN          6
LIGHTGRAY      7
DARKGRAY       8
LIGHTBLUE      9
LIGHTGREEN     10
LIGHTCYAN      11
LIGHTRED       12
LIGHTMAGENTA   13
YELLOW         14
WHITE          15*/
#pragma endregion

int main()
{
   
	/*printf("Press any key: ");
    char ch = getchar();

    printf("Your ASCII: %d\n", ch);*/

    //***************************

    int num1, num2;
    double avg;
    const char* menu[] = { "Average", "Sum", "Max" };
    bool isRunning = true;
    int selected = 0;

    do {

        for (int i = 0; i < 3; i++) {
            gotoxy1(60, 6 * (i + 1));
            if (i == selected) {
                SetColorAndBackground(15, 1);
            }
            else {
                SetColorAndBackground(15, 0);
            }
            printf("%s\n", menu[i]);
        }

        char key = _getch();
        switch (key) {
        case 72: 
            --selected;
            if (selected < 0) selected = 2;
            break;
        case 80: 
            ++selected;
            if (selected > 2) selected = 0;
            break;
        case 13: 
			clear_screen();
            printf("Press First Num: ");
            scanf_s("%d", &num1);
            printf("\nPress Second Num: ");
            scanf_s("%d", &num2);

            switch (selected) {
            case 0:
                avg = (num1 + num2) / 2.0;
                printf("\nThe AVG is: %f", avg);
                break;
            case 1:
                printf("\nThe Sum is: %i", num1 + num2);
                break;
            case 2:
                printf("\nMax Num: %i", num1 > num2 ? num1 : num2);
                break;
            }

            SetColorAndBackground(15, 0);
            printf("\nPress any key to continue...");
            _getch();
            clear_screen();
            break;
        case 27:
            isRunning = false;
            break;
        }
    } while (isRunning);

    
    //***************************


    return 0;
}
