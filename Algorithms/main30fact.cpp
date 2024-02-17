#include <iostream.h>
#include <conio.h>

int answer[40];
int temp[40];
int number2[40];
int number1[2];

void Multiple();
void AddToAnswer(int);
void ZeroTemp();
void IncreaseNumber1();
void Factorial30();

void main()
{
	Factorial30();
   for(int i = 0;i < 40;i ++)
   	cout << number2[i];

      cin >> temp[0];
}

void Multiple()
{
    int tempInt = 0, mod = 0;
    int counter2 , tempCounter;

    for(int counter1 = 1;counter1 >= 0;counter1 --)
    {
        for(counter2 = 39 , tempCounter = 39;counter2 >= 0;counter2 -- , tempCounter--)
        {
            tempInt = (number1[counter1] * number2[counter2] + mod) / 10;
            temp[tempCounter] = (number1[counter1] * number2[counter2] + mod) % 10 ;
            mod = tempInt;
        }
        for(int i = 0;i < 40;i ++)
        {
        	if(temp[i + 1] > 0)
         {
         	temp[i] = mod;
            break;
         }
        }
        AddToAnswer(1 - counter1);
        ZeroTemp();
    }
}
//******************************************************************************
void IncreaseNumber1()
{
	if(number1[1] < 9)
   	number1[1] ++;
   else
   {
   	number1[1] = 0;
      number1[0] ++;
   }
}
//******************************************************************************
void Factorial30()
{
	number1[1] = 1;
	number2[39] = 1;
	for(int i = 1;i < 30;i ++)
   {
   	IncreaseNumber1();
      Multiple();
      for(int i = 0;i < 40;i ++)
      {
      	number2[i] = answer[i];
         answer[i] = 0;
      }
   }
}
//******************************************************************************
void AddToAnswer(int zeroNumber)
{
    int tempInteger = 0 , mod = 0;
    // Multiple temp to 10^zeroNumber
    if(zeroNumber > 0)
    {
        for(int i = zeroNumber ;i < 40;i ++)
        {
                temp[i - zeroNumber ] = temp[i];
        }
        for(int i = 0 ;i < zeroNumber;i ++)
                temp[39 - i] = 0;
    }
    // Add temp to answer
    for(int i = 39 ;i >= 0;i --)
    {
        tempInteger = (temp[i] + answer[i] + mod) / 10;
        answer[i] = (temp[i] + answer[i] + mod )% 10;
        mod = tempInteger;
    }
}    
//******************************************************************************
void ZeroTemp()
{
    for(int i = 0;i < 21;i ++)
        temp[i] = 0;
}
//******************************************************************************
