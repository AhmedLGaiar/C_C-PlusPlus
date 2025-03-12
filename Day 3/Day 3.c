#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

struct Employee
{
    int Id;
    char Name[50];
    int Age;
    float Salary;
    float Deduction;
};

// To Move Cursor to X and Y
void gotoxy1(int x, int y);
void gotoxy(int x, int y);

// To Change Color
void SetColorAndBackground(int ForgC, int BackC);

void textattr(unsigned short int newattr);

void DrawFrame(int Width, int Height);

//*****************************************
void swab2num(int* num1, int* num2);

int StringSize(char* str);

char* CopyString(char* str);

#pragma region Menu

int displayMenu();

void newOption(struct Employee employees[], int size);

void displayOption(struct Employee employees[], int size);

void searchEmployee(struct Employee employees[], int id, int size);

void exitOption();

#pragma endregion

int main(void)
{
    #pragma region Swap
        /*int num1 = 0, num2 = 0;
        printf("Enter First Number: ");
        scanf_s("%i", &num1);
        printf("Enter Second Number: ");
        scanf_s("%i", &num2);
        swab2num(&num1, &num2);
    
        printf("First Number: %i\n", num1);
        printf("Second Number: %i\n", num2);
        printf("\nPress any Key to Cont....");
        _getch();
        system("cls");*/
    #pragma endregion
    
        /*****************************************/
    
    #pragma region StringLen
      /*char name[30];
      printf("Please Enter The String To Get Len: ");
      fgets(name, sizeof(name), stdin);
      printf("\nSize of String= %i", StringSize(name));
      printf("\nPress any Key to Cont....");
      _getch();
      system("cls");*/
    
    #pragma endregion
    
      /*****************************************/
    #pragma region CopyString
    
     /*char name[30];
     printf("Please Enter The String To Copy: ");
     fgets(name, sizeof(name), stdin);
     printf("\nNew String= %s", CopyString(name));
     printf("\nPress any Key to Cont....");
     _getch();
     system("cls");*/
    
    #pragma endregion
    
     /*****************************************/

    #pragma region ClassnStudent

      	/*int numClasses, numStudents;
      	float totalMarks, classAverage;
      
      	printf("Enter the number of classrooms: ");
      	scanf_s("%d", &numClasses);
      
      	for (int i = 0; i < numClasses; i++) {
      		printf("\nEnter the number of students in classroom %d: ", i + 1);
      		scanf_s("%d", &numStudents);
      
      		float* marks = (float*)malloc(numStudents * sizeof(float)); 
      		if (marks == NULL) {
      			printf("Memory allocation failed!\n");
      			return 1;
      		}
      
      		totalMarks = 0;
      		for (int j = 0; j < numStudents; j++) {
      			printf("Enter marks for student %d: ", j + 1);
      			scanf_s("%f", &marks[j]);
      			totalMarks += marks[j];
      		}
      
      		classAverage = totalMarks / numStudents;
      		printf("Classroom %d Average: %.2f\n", i + 1, classAverage);
      
      		free(marks); 
      	}*/
      
    #pragma endregion

    /*****************************************/

    #pragma region PrintLinewithInsert

        char text[256] = "";
        int pos = 0;
        char ch;
        int insertMode = 1;  // 1 for insert, 0 for overwrite

        printf("Enter text. Use arrows to navigate, backspace to delete, Insert to toggle mode, Enter to finish.\n");
        gotoxy(0, 1);

        while (1) {
            if (_kbhit()) {
                ch = _getch();

                // Enter key
                if (ch == 13) {
                    printf("\nFinal string: %s\n", text);
                    break;
                }

                switch (ch) {
                case 75: // Left arrow
                    if (pos > 0) {
                        pos--;
                        gotoxy(pos, 1);
                    }
                    break;

                case 77: // Right arrow
                    if (pos < strlen(text)) {
                        pos++;
                        gotoxy(pos, 1);
                    }
                    break;
                     
                case 8: // Backspace
                    if (pos > 0 && strlen(text) > 0) {
                        for (int i = pos - 1; i < strlen(text); i++) {
                            text[i] = text[i + 1];
                        }
                        pos--;
                        printf("\r%s ", text); 
                        gotoxy(pos, 1);
                    }
                    break;

                case 82: // Insert key
                    insertMode = !insertMode;
                    break;

                default:
                    if ( (ch >= 32 && ch <= 126)) {
                        if (insertMode) { // Insert Mode
                            for (int i = strlen(text); i > pos; i--) {
                                text[i] = text[i - 1];
                            }
                        }
                        text[pos] = ch;
                        if (pos < strlen(text)) pos++;
                        printf("\r%s", text);
                        gotoxy(pos, 1);
                    }
                    break;
                }
            }
        }

    #pragma endregion

    /*int choice, id, employees_count;

    printf("Enter the number of employees: ");
    scanf_s("%d", &employees_count);

    struct Employee* employees = (struct Employee*)malloc(employees_count * sizeof(struct Employee));
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    while (1)
    {
        system("cls");
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
            system("cls");
            printf("Enter Employee ID to Search: ");
            scanf_s("%d", &id);
            DrawFrame(100, 3);
            searchEmployee(employees, id, employees_count);
            break;
        case 3:
            SetColorAndBackground(15, 0);
            exitOption();
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            _getch();
        }
    }*/

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

// To Change Color
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

void DrawFrame(int Width, int Height)
{
    int i, j;
    for (i = 0; i < Width; i++)
    {
        for (j = 0; j < Height; j++)
        {
            if (i == 0 || i == Width - 1 || j == 0 || j == Height - 1)
            {
                gotoxy1(i, j);
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
            gotoxy1(55, (i + 1) * 5);
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
    system("cls");
    SetColorAndBackground(14, 0);

    for (int i = 0; i < size; i++)
    {
        printf("Enter Employee %d Details:\n", i + 1);

        printf("ID: ");
        scanf_s("%d", &employees[i].Id);

        printf("Name: ");
        scanf_s("%s", employees[i].Name, sizeof(employees[i].Name));
        while (getchar() != '\n');  

        printf("Age: ");
        scanf_s("%d", &employees[i].Age);

        printf("Salary: ");
        scanf_s("%f", &employees[i].Salary);

        printf("Deduction: ");
        scanf_s("%f", &employees[i].Deduction);

        printf("\n"); 
    }

    printf("\nPress any key to continue...");
    _getch();
}

void displayOption(struct Employee employees[], int size)
{
    system("cls");

    SetColorAndBackground(13, 0);  // Light Cyan text
    printf("\n*************************************************************\n");

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
    printf("*************************************************************\n");

    SetColorAndBackground(10, 0);  // Green text for message
    printf("\nPress any key to return to the menu...");
    _getch();

    SetColorAndBackground(7, 0);  // Reset color to default
}

void searchEmployee(struct Employee* employees, int id, int size)
{
    struct Employee* ptr = employees;
    for (int i = 0; i < size; i++, ptr++)
    {
        if (ptr->Id == id)
        {
            printf("\nEmployee Found!\n");
            printf("| ID | Name | Age | Salary | Deduction |\n");
            printf("| %d | %s | %d | %.2f | %.2f |\n",
                ptr->Id, ptr->Name, ptr->Age, ptr->Salary, ptr->Deduction);
            _getch();
            return;
        }
    }
    printf("\nEmployee Not Found!\n");
    _getch();
}

void exitOption()
{
    system("cls");
    gotoxy1(50, 10);
    system("color");
    SetColorAndBackground(15,0);
    printf("Exiting program Goodbye...");
    Sleep(1000);
    exit(0);
}

void swab2num(int* num1, int* num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int StringSize(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char* CopyString(char* str)
{
    int i = StringSize(str);

    char* str2 = (char*)malloc((i + 1) * sizeof(char));
    if (str2 == NULL)
        return NULL;

    for (int j = 0; j <= i; j++)
        str2[j] = str[j];

    return str2;
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}
