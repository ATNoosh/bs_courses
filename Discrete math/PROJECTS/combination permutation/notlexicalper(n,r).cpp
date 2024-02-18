#include <stdio.h>
#include <conio.h>

void Swap(int &,int &);
void Print(const int , const int );
void Permute(int *, const int , const int ,const int);

void main()
{
	int s[] = {'A','B','C','D','E','F'};
   Permute(s, 0, sizeof(s)/sizeof(int),3);
	/*int s2[] = {1, 2, 4};
   permute(s2, 0, sizeof(s)/sizeof(int));
	int s3[] = {1, 3, 4};
   permute(s3, 0, sizeof(s)/sizeof(int));
	int s4[] = {2, 3 ,4};
   permute(s4, 0, sizeof(s)/sizeof(int));*/
   getch();
}
//******************************************************************************
void Print(const int *s, const int size)
{
	if (s != 0)
   {
   	for (int i = 0; i < size; i++)
   	{
      	printf("%c ", s[i] );
      }
   	printf("\n");
   }
}
//******************************************************************************
void Permute(int *s, const int start, const int n,const int r)
{
	if (start == r)
   {
   	Print(s, r);
   }
   else
   {
   	for (int i = start; i < n; i++)
      {
         Swap(s[i] , s[start]);
         Permute(s, start + 1, n , r);
         Swap(s[i] , s[start]);
      }
   }
}
//******************************************************************************
void Swap(int &a,int &b)
{
	int temp = a;
   a = b;
   b = temp;
}