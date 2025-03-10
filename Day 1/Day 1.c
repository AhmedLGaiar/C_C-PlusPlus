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

int main()
{
   
	/*printf("Press any key: ");
    char ch = getchar();

    printf("Your ASCII: %d\n", ch);*/

    //***************************
    
    /*for (int i = 0; i < 256; i++)
    {
		printf("ASCII: %d = %c\n", i, i);
    }*/

    //***************************

    /*int num1, num2;
    float avg;
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
            SetColorAndBackground(15, 0);

			system("cls");
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
            
            printf("\nPress any key to continue...");
            _getch();
            system("cls");
            break;
        case 27:
            isRunning = false;
            break;
        }
    } while (isRunning);*/

    //***************************

    /*int arrNums[5];
	int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("Enter Num %i=", i + 1);
        scanf_s("%i", &arrNums[i]);
    }
	int max = arrNums[0];
	for (i = 1; i < 5; i++)
	{
		if (arrNums[i] > max)
		{
			max = arrNums[i];
		}
	}
	printf("Max Num: %i", max);*/

    //***************************
    
   /*int arr[3][4];
	for (int i = 0; i < 3; i++)
	{
      	printf("Enter For Student Num %i\n", i + 1);
		for (int j = 0; j < 4; j++)
		{
			printf("Enter For Subject Num %i = ", j + 1);
			scanf_s("%i", &arr[i][j]);
		}
        printf("************************************\n");
	}
    for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 4; j++)
		{
			sum += arr[i][j];
		}
        printf("Total Grades For Student Num %i = %i\n", i + 1,sum);
        printf("Average Grades For Student Num %i= %1f\n", i + 1,(sum/4.0));

        printf("************************************\n");
	}*/

    //***************************
     
    /*char name[30]; 

    printf("Enter your name: ");
    fgets(name,sizeof(name), stdin);

    printf("Hello, %s\n", name);*/ 

	//***************************

    /*int SIZE;
    
    do {
        printf("Enter Odd Number: ");
        scanf_s("%d", &SIZE);
    } while (SIZE % 2 == 0);
    
    int** magicSquare = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; i++) {
        magicSquare[i] = (int*)calloc(SIZE, sizeof(int));
    }
    
    int i = 0, j = SIZE / 2;
    for (int num = 1; num <= SIZE * SIZE; num++) {
        magicSquare[i][j] = num;
        int newi = (i - 1 + SIZE) % SIZE;
        int newj = (j + 1) % SIZE;
        if (magicSquare[newi][newj]) {
            i = (i + 1) % SIZE;
        }
        else {
            i = newi;
            j = newj;
        }
    }
    
    printf("Magic Square of order %d:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            gotoxy1(5 + j * 5, 5 + i * 2); 
            printf("%3d", magicSquare[i][j]);
        }
    }
    printf("\n");*/
	

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