#include <stdio.h>
#include <conio.h>

void Print(int *,int);
void Combination(int ,int );
int C(int ,int);

void main()
{
   int n,r;
   printf("Enter n:");
   scanf("%d",&n);
   printf("Enter r:");
   scanf("%d",&r);
	Combination(n,r);
   getch();
}
//******************************************************************************
void Combination(int n,int r)
{
	int *s;
   s = new int[n];

	for(int counter = 0;counter < r;counter ++)
   	s[counter] = counter;

   Print(s,r);
   for(int counter = 1;counter < C(n,r);counter ++)
	{
   	int m = r-1;
      int max_val = n-1;

      while(s[m] == max_val)
      {
      	m --;
         max_val --;
      }

      s[m] = s[m] + 1;
      for(int j = m + 1;j < r;j ++)
      	s[j] = s[j - 1] + 1;

      Print(s,r);
   }

}
//******************************************************************************
void Print(int *arr,int size)
{
	for(int counter = 0;counter < size;counter ++)
   	printf("%d",arr[counter]);

   printf("\n");
}
//******************************************************************************
int C(int n,int r)
{
	if(n < r)
   	return 0;
   if(r == 1)
   	return n;
   else
   	return C(n - 1,r - 1) + C(n - 1,r);
}
//******************************************************************************
