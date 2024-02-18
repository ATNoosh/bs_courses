#include <stdio.h>
#include <conio.h>
#include <math.h>

#define SIZE 10000

bool IsPrime(int );
int *ReturnPruductArray(int );
void PrintPruductArray(int *);

void main()
{
	int userNumber ;

   printf("Input Number :");
   scanf("%d" , &userNumber);
   printf("%d = " , userNumber );
   PrintPruductArray(ReturnPruductArray(userNumber)) ;
   getch();
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
void PrintPruductArray(int *initedArray)
{
	for(int counter = 0;initedArray[counter ] != -1;counter ++)
   {
   	if(initedArray[counter + 1] == -1 )
   		printf(" %d " , initedArray[counter]);
      else
   		printf(" %d *" , initedArray[counter]);
   }
}
//******************************************************************************
