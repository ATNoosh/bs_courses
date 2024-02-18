#include <stdio.h>
#include <conio.h>
#include <math.h>

bool IsPrime(unsigned long int);
void PrintPrimes(unsigned long int ,unsigned long int);

void main()
{

	unsigned long int startNumber , endNumber;
	printf("Start :");
   scanf("%ld" , &startNumber);
	printf("End :");
   scanf("%ld" , &endNumber);
   PrintPrimes(startNumber , endNumber);

   getch();
}

//******************************************************************************
bool IsPrime(unsigned long int initedNumber)
{
   if(initedNumber < 2 )
   	return false;

   if(initedNumber == 2)
   	return true;

   for(int counter = 3;counter <= sqrt(initedNumber);counter += 2)
   {
   	if(IsPrime(counter) == true && initedNumber % counter == 0)
      	return false;
   }

   return true;
}
//******************************************************************************
void PrintPrimes(unsigned long int start,unsigned long int end)
{
   if(start <= 2)
   	printf("2\t");
   if(start % 2 == 0)
   	start --;

	for(unsigned long int counter = start;counter <= end;counter += 2)
   {
   	if(IsPrime(counter) == true)
      	printf("%ld \t" , counter);
   }
}
//******************************************************************************
