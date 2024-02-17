#include <iostream.h>
#include <conio.h>

//**************************************************************************************************
class cChess
{
	public :
   	cChess();
      void GetMemory(int);
      void Limit(int,int);
      void Show();
      void Solve();

   private:
   	int **array;
      int size;
      void Initialize();
};
//..................................................................................................
cChess :: cChess()
{
	array = NULL;
   size = 0;
}
//..................................................................................................
void cChess :: GetMemory(int rowCol)
{
	array = new int*[rowCol];
   for(int counter = 0;counter < rowCol;counter++)
   	array[counter] = new int[rowCol];

   size = rowCol;
   Initialize();
}
//..................................................................................................
void cChess :: Initialize()
{
	for(int i = 0;i < size;i ++)
		for(int j = 0;j < size;j ++)
      	array[i][j] = 0;
}
//..................................................................................................
void cChess :: Limit(int r, int c)
{
	for(int counter = 0;counter < size;counter ++)
   	array[r][counter] = -1;
	for(int counter = 0;counter < size;counter ++)
   	array[counter][c] = -1;

   int i = r, j = c;
   while(i >= 0 && j >= 0)
   {
   	array[i][j] = -1;
   	i --;j --;
   }
   i = r;j = c;
   while(i < size && j >= 0)
   {
   	array[i][j] = -1;
   	i ++;j --;
   }
   i = r;j = c;
   while(i >= 0 && j < size)
   {
   	array[i][j] = -1;
   	i --;j ++;
   }
   i = r;j = c;
   while(i < size && j < size)
   {
   	array[i][j] = -1;
   	i ++;j ++;
   }

   array[r][c] = 1;
}
//..................................................................................................
void cChess :: Show()
{
	for(int i = 0;i < size; i++)
   {
		for(int j = 0;j < size; j++)
      	cout << "\t" << array[i][j];

      cout << endl;
   }
}
//..................................................................................................
void cChess :: Solve()
{
	//for(int )
}
//..................................................................................................
//**************************************************************************************************
void main()
{
	cChess ch1;
   ch1.GetMemory(8);
   ch1.Limit(4,2);
   ch1.Show();
   getch();
}
//**************************************************************************************************
