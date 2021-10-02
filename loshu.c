#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

void getRandomNumber();
void addNumbersToArray(int);
bool isMagicSquare();
void createGrid();
void showSquare(int array[][3]);

const int SIZE = 3;
int number[][SIZE] = {{0, 0, 0}, {0,0,0}, {0,0,0}};

int main()
{
    int magicsquare[3][3] = {{2,7,6},{9,5,1},{4,3,8}};
    int nonmagicsquare[3][3] = {{5,4,6},{7,3,1},{2,9,8}};
    int counter = 0;
    isMagicSquare(magicsquare);
    showSquare(magicsquare);
    isMagicSquare(nonmagicsquare);
    showSquare(nonmagicsquare);

    do
    {
        counter++;
        printf(counter, "\n");
        getRandomNumber();
    }while(!isMagicSquare());
    createGrid();
    printf("It took %d tries.\n", counter);
}

void createGrid()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            printf(number[i][j], " ");
        }
        printf("\n");
    }
}

void showSquare(int arr[][3]) 
{
    printf("\n[%d %d %d]", arr[0][0], arr[0][1], arr[0][2]);
    printf("\n[%d %d %d]", arr[1][0], arr[1][1], arr[1][2]);
    printf("\n[%d %d %d]\n", arr[2][0], arr[2][1], arr[2][2]);
}

bool isMagicSquare()
{
    int sum = number[0][0] + number[0][1] + number[0][2];

    for(int i = 0; i < SIZE; i++)
    {
        if(number[i][0] + number[i][1] + number[i][2] != sum)
        {
            return false;
        }
    }

    for(int i = 0; i < SIZE; i++)
    {
        if(number[0][i] + number[1][i] + number[2][i] != sum)
        {
            return false;
        }
    }

    if(number[0][0] + number[1][1] + number[2][2] != sum)
    {
        return false;
    }
    
    return true;
}

void getRandomNumber()
{
    int number = 0;
    int numberused[] = {0,0,0,0,0,0,0,0,0};
    srand(time(NULL));
    bool NumberAlreadyUsed = true;

    for(int i = 0; i < 9; i++)
    {
        do
        {
            NumberAlreadyUsed = true;

            number = rand() % 9 + 1;
            if(numberused[number - 1] == 0)
            {
                numberused[number - 1] = number;
                NumberAlreadyUsed = false;
            }
        }while(NumberAlreadyUsed);
    }
    addNumbersToArray(number);
}

void addNumbersToArray(int number)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(number[i][j] == 0)
            {
                number[i][j] = number;
                return;
            }
        }
    }
}
