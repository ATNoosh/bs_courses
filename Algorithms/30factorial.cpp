#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int number1[11];
int number2[11];
int temp[22];
int answer[22];

void Initialize();
void ZeroTemp();
void Multiple();
void AddToAnswer(int);
void PrintAnswer();

int main()
{
    double num1 ,num2;
    num1 = num2 = 0;
    Initialize();
    printf("Enter first number : ");
    scanf("%lf",&num1);
    printf("Enter second number : ");
    scanf("%lf",&num2);

    for(int i = 10;i >= 0; i-- )
    {
        number1[i] = (num1 / 10.0 - floor(num1 / 10.0)) * 10;
        num1 = floor(num1 / 10.0);
    }
    for(int i = 10;i >= 0; i--)
    {
        number2[i] = (num2 / 10.0 - floor(num2 / 10.0)) * 10;
        num2 = floor(num2 / 10.0);
    }
    Multiple();
    PrintAnswer();
                     
    getch();
}
//******************************************************************************
void Multiple()
{
    int tempInt = 0, mod = 0;
    int counter2 , tempCounter;

    for(int counter1 = 10;counter1 >= 0;counter1 --)
    {
        for(counter2 = 10 , tempCounter = 21;counter2 >= 0;counter2 -- , tempCounter--)
        {
            tempInt = (number1[counter1] * number2[counter2] + mod) / 10;
            temp[tempCounter] = (number1[counter1] * number2[counter2] + mod) % 10 ;
            mod = tempInt;
        }
        temp[11] = mod;
        AddToAnswer(10 - counter1);
        ZeroTemp();
    }
}
//******************************************************************************
void AddToAnswer(int zeroNumber)
{
    int tempInteger = 0 , mod = 0;
    // Multiple temp to 10^zeroNumber
    if(zeroNumber > 0)
    {
        for(int i = zeroNumber ;i < 22;i ++)
        {
                temp[i - zeroNumber ] = temp[i];
        }
        for(int i = 0 ;i < zeroNumber;i ++)
                temp[21 - i] = 0;
    }
    // Add temp to answer
    for(int i = 21 ;i >= 0;i --)
    {
        tempInteger = (temp[i] + answer[i] + mod) / 10;
        answer[i] = (temp[i] + answer[i] + mod )% 10;
        mod = tempInteger;
    }
}
//******************************************************************************
void Initialize()
{
    for(int i = 0;i < 22;i ++)
        number1[i/2] = number2[i/2] = answer[i] = 0;
}
//******************************************************************************
void PrintAnswer()
{
    for(int i = 0;i < 22;i ++)
        printf("%d",answer[i]);
}
//******************************************************************************
void ZeroTemp()
{
    for(int i = 0;i < 21;i ++)
        temp[i] = 0;
}
//******************************************************************************
