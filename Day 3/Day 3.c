#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

//To Mov e Cursor to X and Y
void gotoxy1(int x, int y);

//To Change Color
void SetColorAndBackground(int ForgC, int BackC);

void textattr(unsigned short int newattr);

int main(void)
{

   

    return 0;
}

#pragma region Method

void gotoxy1(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//To Change Color
void SetColorAndBackground(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void textattr(unsigned short int newattr)
{ // requires windows.h
    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE)
    {
        printf(printf("Error: GetStdHandle failed with %d \n", GetLastError()));
        exit(1);
    }
    SetConsoleTextAttribute(hStdout, newattr);
}

#pragma endregion