#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

struct Employee {
	int Id;
	char Name[50];
	int Age;
	float Salary;
	float Deduction;
};

struct Complex {
	double real;
	double img;
};

void AddingComplex(struct Complex c1, struct Complex c2);
void SubtractingComplex(struct Complex c1, struct Complex c2);


void gotoxy(int x, int y);
void SetColorAndBackground(int ForgC, int BackC);
void clear_screen();
void DrawFrame(int Width, int Height);

#pragma region Menu

int displayMenu();

void newOption(struct Employee employees[], int size);

void displayOption(struct Employee employees[], int size);

void searchEmployee(struct Employee employees[], int id, int size);

void exitOption();

#pragma endregion

int main(void)
{
	#pragma region Complex

	struct Complex c1, c2;
	printf("Enter the real part of the first complex number: ");
	scanf_s("%lf", &c1.real);
	printf("Enter the imaginary part of the first complex number: ");
	scanf_s("%lf", &c1.img);
	printf("Enter the real part of the second complex number: ");
	scanf_s("%lf", &c2.real);
	printf("Enter the imaginary part of the second complex number: ");
	scanf_s("%lf", &c2.img);
	AddingComplex(c1, c2);
	SubtractingComplex(c1, c2);
	printf("\nPress any Key to Cont....");
	_getch();
	clear_screen();

	#pragma endregion

	int choice, id;
	int employees_count = 2;
	struct Employee employees[] = { 0 };
	while (1) {
		clear_screen();
		choice = displayMenu();

		switch (choice)
		{
		    case 0:
		    	newOption(employees, employees_count);
		    	break;
		    case 1:
		    	displayOption(employees, employees_count);
		    	break;
		    case 2:
		    	clear_screen();
		    	printf("Enter Employee ID to Search: ");
		    	scanf_s("%d", &id);
		    	DrawFrame(100, 3);
		    	searchEmployee(employees, id, employees_count);
		    	break;
		    case 3:
		    	exitOption();
		    	break;
		}
	}

	return 0;

}

void AddingComplex(struct Complex c1, struct Complex c2)
{
	struct Complex c3;
	c3.real = c1.real + c2.real;
	c3.img = c1.img + c2.img;
	printf("The sum of the two complex numbers is %lf + %lfi", c3.real, c3.img);
};

void SubtractingComplex(struct Complex c1, struct Complex c2)
{
	struct Complex c3;
	c3.real = c1.real - c2.real;
	c3.img = c1.img - c2.img;
	printf("The difference of the two complex numbers is %lf + %lfi", c3.real, c3.img);
};

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clear_screen()

{
	DWORD n;           /* Number of characters written */
	DWORD size;        /* number of visible characters */
	COORD coord = { 0 }; /* Top left screen position */
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	/* Get a handle to the console */
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);
	/* Find the number of characters to overwrite */
	size = csbi.dwSize.X * csbi.dwSize.Y;
	/* Overwrite the screen buffer with whitespace */ FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n); /* Reset the cursor to the top left position */
	SetConsoleCursorPosition(h, coord);
}

void SetColorAndBackground(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void DrawFrame(int Width, int Height)
{
	int i, j;
	for (i = 0; i < Width; i++)
	{
		for (j = 0; j < Height; j++)
		{
			if (i == 0 || i == Width - 1 || j == 0 || j == Height - 1)
			{
				gotoxy(i, j);
				printf("+");
			}
		}
	}
}

int displayMenu() 
{
	char menu[4][15] = { "New", "Display", "Search", "Exit" };
	int i, highlighted = 0;
	char key;

	while (1) {
		for (i = 0; i < 4; i++) {
			gotoxy(55, (i + 1) * 5);
			if (highlighted == i) {
				SetColorAndBackground(15, 1);
			}
			else {
				SetColorAndBackground(15, 0);
			}
			printf("%s", menu[i]);
		}

		key = _getch();
		if (key == -32) {
			key = _getch();
			if (key == 72) {  // UP arrow key
				highlighted = (highlighted - 1 + 4) % 4;
			}
			else if (key == 80) {  // DOWN arrow key
				highlighted = (highlighted + 1) % 4;
			}
		}
		else if (key == 13) {  // ENTER key
			return highlighted;
		}

		SetColorAndBackground(7, 0);
	}
}

void newOption(struct Employee employees[], int size)
{
	clear_screen();
	SetColorAndBackground(14, 0);

	for (int i = 0; i < size; i++)
	{
		printf("Enter Employee %d Details:\n", i + 1);

		printf("ID: ");
		scanf_s("%d", &employees[i].Id);

		printf("Name: ");
		scanf_s("%s", employees[i].Name, sizeof(employees[i].Name));
		while (getchar() != '\n');  // Clear input buffer to avoid issues with Age input

		printf("Age: ");
		scanf_s("%d", &employees[i].Age);

		printf("Salary: ");
		scanf_s("%f", &employees[i].Salary);

		printf("Deduction: ");
		scanf_s("%f", &employees[i].Deduction);

		printf("\n"); // Add space for better readability
	}

	printf("\nPress any key to continue...");
	_getch();
}

void displayOption(struct Employee employees[], int size) {
	clear_screen();

	SetColorAndBackground(13, 0);  // Light Cyan text
	printf("\n=============================================================\n");

	SetColorAndBackground(11, 0);  // Yellow text for headers
	printf("| %-5s | %-20s | %-3s | %-10s | %-10s |\n", "ID", "Name", "Age", "Salary", "Deduction");

	SetColorAndBackground(11, 0);  // Light Cyan text
	printf("-------------------------------------------------------------\n");

	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			SetColorAndBackground(7, 0);  // White text for even rows
		}
		else {
			SetColorAndBackground(8, 0);  // Gray text for odd rows
		}
		printf("| %-5d | %-20s | %-3d | %-10.2f | %-10.2f |\n",
			employees[i].Id, employees[i].Name, employees[i].Age, employees[i].Salary, employees[i].Deduction);
	}

	SetColorAndBackground(11, 0);  // Light Cyan text
	printf("=============================================================\n");

	SetColorAndBackground(10, 0);  // Green text for message
	printf("\nPress any key to return to the menu...");
	_getch();

	SetColorAndBackground(7, 0);  // Reset color to default
}

void searchEmployee(struct Employee employees[], int id, int size) {
	for (int i = 0; i < size; i++) {
		if (employees[i].Id == id) {
			printf("\nEmployee Found!\n");
			printf("| ID | Name | Age | Salary | Deduction |\n");
			printf("| %d | %s | %d | %.2f | %.2f |\n",
				employees[i].Id, employees[i].Name, employees[i].Age, employees[i].Salary, employees[i].Deduction);
		}
	}
	_getch();
}

void exitOption() {
	clear_screen();
	gotoxy(50, 10);
	SetColorAndBackground(13, 0);
	printf("Exiting program Goodbye...");
	Sleep(1000);
	exit(0);
}