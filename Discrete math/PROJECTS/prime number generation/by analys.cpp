#include <stdio.h>
#include <conio.h>
#include <math.h>
#define SIZE 10000

bool IsPrime(int );
int* ReturnPruductArray(int);
void Print(int ,int );

void main()
{
	int start , end;

   printf("Start : ");
   scanf("%d",&start);
   printf("End   : ");
   scanf("%d",&end);
   Print(start,end);

   getch();
}
//******************************************************************************
int *ReturnPruductArray(int initedNumber)
{
   int answerArray[SIZE] ,arrCounter = 0 , tempHold = initedNumber ;

	for(int primeCounter = 2 ; primeCounter <= initedNumber;primeCounter ++)
   {
   	if(tempHold % primeCounter == 0 && IsPrime(primeCounter) == true)
      {
         while(tempHold % primeCounter == 0)
         {
      		answerArray[arrCounter] = primeCounter ;
      		arrCounter ++ ;
         	tempHold /= primeCounter ;
         }
      }
   }

   answerArray [arrCounter] = -1 ;

   if(initedNumber == 1)
   {
   	answerArray[0] = 1;
   	answerArray[1] = -1;
   }

   return answerArray ;
}                                              
//******************************************************************************
bool IsPrime(int initedNumber)
{
	if(initedNumber == 1)
   	return false ;

   for(int counter = 2 ;counter <= sqrt(initedNumber);counter ++)
   {
   	if(initedNumber % counter == 0)
      	return false ;
   }
   return true;
}
//******************************************************************************
void Print(int start,int end)
{
	if(start == 2)
   {
   	printf("2\t");
      start ++;
   }

   if(start % 2 == 0)
   	start --;

   for(int counter = start ;counter <= end ;counter ++)
   {
   	if(ReturnPruductArray(counter)[0] == counter )
      	printf("%d\t",counter);
   }
}
//******************************************************************************
