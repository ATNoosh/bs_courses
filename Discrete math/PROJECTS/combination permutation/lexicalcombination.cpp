#include <stdio.h>
#include <conio.h>
#include <math.h>

void Put01(int *,int ,int );
void Put012(int **,int ,int );
void Print(int **,int ,int ,int);

void main()
{
	int **arr2 , size ,r;

   printf("Enter N : ");
   scanf("%d" , &size);
   printf("Enter R : ");
   scanf("%d" , &r);

   arr2 = new int*[size];
   for(int counter = 0;counter < size;counter ++)
   	arr2[counter] = new int[pow(2,size)];

   Put012(arr2,pow(2,size),size);
   Print(arr2,size,pow(2,size),r);

   getch();
}
//******************************************************************************
void Put01(int *arr,int size,int repeat)
{
	int zeroOne = 1;

	for(int i = 0;i < size;i++)
   {
   	arr[i] = zeroOne;
   	if((i + 1) % repeat == 0)
      	zeroOne = 1 - zeroOne;//if(zeroOne == 1 zeroOne = 0 else zeroOne 1)
   }
}
//******************************************************************************
void Put012(int **arr2,int column,int row)
{
	for(int i = 0, j = pow(2 , row) / 2;i < row;i ++, j /= 2)
   {
   	Put01(arr2[i] , column , j);
   }
}
//******************************************************************************
void Print(int **arr2, int column,int row,int r)
{
	int sum = 0;

   char *set , letter;//set ={A,B,C,D,....}

   set = new char[row];
   for(int counter = 0,letter = 'A';counter < row;counter ++,letter ++)
   	set[counter] = letter;

	for(int i = 0;i < row; i++)
   {
      sum = 0;

		for(int j = 0;j < column; j++)      //this for count number of ONE's
      {
      	sum += arr2[j][i];
      }

      if(sum == r)
      {
			for(int j = 0;j < column; j++)
      	{
         	if(arr2[j][i] == 1)
      			printf("%c", set[j]);
      	}
      	printf("\n");
      }

   }
}
//******************************************************************************
