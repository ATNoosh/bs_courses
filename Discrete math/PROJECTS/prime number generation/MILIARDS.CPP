#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include <dos.h>
#define SIZE 2

class Milliards
{
	public :
   	Milliards();
      void PowerTwo();
      void Print();

	private:
   	unsigned long int Array[SIZE][SIZE][SIZE][SIZE][SIZE];
};
//..............................................................................
Milliards :: Milliards()
{
   for(int i = 0;i < SIZE;i ++)
   	for(int j = 0;j < SIZE;j ++)
   		for(int k = 0;k < SIZE;k ++)
   			for(int l = 0;l < SIZE;l ++)
   				for(int m = 0;m < SIZE;m ++)
   					Array[i][j][k][l][m] = 0;

	Array[SIZE - 1][SIZE - 1][SIZE - 1][SIZE - 1][SIZE - 1] = 2;
}
//..............................................................................
void Milliards :: Print()
{
	FILE *fp ;
   char string[3000] , ch = 's';
   fp = fopen("e:\Largest prime.txt" , "w");
	int digitCounter = 0 , temp;
   for(int i = 0;i < SIZE;i ++)
   {
   	for(int j = 0;j < SIZE;j ++)
      {
   		for(int k = 0;k < SIZE;k ++)
         {
   			for(int l = 0;l < SIZE;l ++)
            {
   				for(int m = 0;m < SIZE;m ++)
               {
               	temp = Array[i][j][k][l][m] ;
                  if(temp == 0 && ch != 'e')
                  {
                  	ch = 'e';
                     break;
                  }
               	for(digitCounter = 0;temp != 0;digitCounter ++ )
                  {
                  	temp /= 10;
                  }
                  for(int counter = 0;counter < 10 - 1 - digitCounter ;counter ++)
                  {
   						fputs(itoa(0,string,10),fp);
                  	//cout << 0;
                  }
   					fputs(itoa(Array[i][j][k][l][m],string,10),fp);
   					//cout << Array[i][j][k][l][m] ;
               }
            }
         }
      }
   }
   //cout << Array[SIZE-1][SIZE-1][SIZE-1][SIZE-1][SIZE-1]<<
   //endl << Array[SIZE-1][SIZE-1][SIZE-1][SIZE-1][SIZE-2];
}
//..............................................................................
void Milliards :: PowerTwo()
{
	int temp = 0;

   for(int i = SIZE - 1;i >= 0;i --)
   {
   	for(int j = SIZE - 1;j >= 0;j --)
      {
   		for(int k = SIZE - 1;k >= 0;k --)
         {
   			for(int l = SIZE - 1;l >= 0;l --)
            {
   				for(int m = SIZE - 1;m >= 0;m --)
               {
   					Array[i][j][k][l][m] *= 2;
   					temp += Array[i][j][k][l][m] ;
                  Array[i][j][k][l][m] = temp % 1000000000 ;
                  temp /= 1000000000;
                  /*if(i == j == k == l == m == 0 && temp > 0)
                  {
                  	cout << "\nVery Big !" ;
                     getch();
                     exit(0);
                  } */
               }
            }
         }
      }
   }
}
//******************************************************************************
void main()
{
	Milliards m1;

   cout << "PowerTwo started .\n" ;
   for(int counter = 1;counter < 11;counter ++)
   {
		if(counter % 10000 == 0)
      	cout << counter ;

   	m1.PowerTwo();
   }
   cout << "\nPrint started .\n" ;
   m1.Print();
   cout << "The End";
   getch();
}
