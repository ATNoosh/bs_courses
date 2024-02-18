#include <stdio.h>
#include <conio.h>
#include <math.h>

#define SIZE 10000

bool IsPrime(unsigned long int );
unsigned long int *ReturnPruductArray(unsigned long int );
void PrintPruductArray(unsigned long int *);

void main()
{
	unsigned long int userNumber ;

   printf("Input Number :");
   scanf("%d" , &userNumber);
   printf("%d = " , userNumber );
   PrintPruductArray(ReturnPruductArray(userNumber)) ;

   getch();
}
//******************************************************************************
bool IsPrime(unsigned long int initedNumber)
{
	if(initedNumber == 1)
   	return false ;

   for(unsigned long int counter = 2 ;counter <= sqrt(initedNumber);counter ++)
   {
   	if(initedNumber % counter == 0)
      	return false ;
   }
   return true;
}
//******************************************************************************
unsigned long int *ReturnPruductArray(unsigned long int initedNumber)
{
   unsigned long int answerArray[SIZE] ,arrCounter = 0 , tempHold = initedNumber ;

	for(unsigned long int primeCounter = 2 ; primeCounter <= initedNumber;primeCounter ++)
   {
   	if(tempHold % primeCounter == 0 && IsPrime(primeCounter) == true)
      {
      	answerArray[arrCounter] = primeCounter ;

         for(unsigned long int powerCounter = 1;tempHold % primeCounter == 0;powerCounter ++)
         {
            answerArray[arrCounter + 1] = powerCounter ;
         	tempHold /= primeCounter ;
         }

         arrCounter += 2 ;
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
void PrintPruductArray(unsigned long int *initedArray)
{
	for(unsigned long int counter = 0;initedArray[counter ] != -1;counter += 2)
   {
   	if(initedArray[counter + 2] == -1 )
      {
   		printf("( %d ^ %d )" , initedArray[counter] , initedArray[counter + 1]);
      }
      else
   		printf("( %d ^ %d ) * " , initedArray[counter] , initedArray[counter + 1]);
   }

   printf("\n '^' is power operand. \n") ;
}
//******************************************************************************