#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

//**************************************************************************************************
class cMaxHeap
{
	public :
   	cMaxHeap(int = 100);
      bool IsFull();
      bool IsEmpty();
      void Insert(int);
      int Delete();
      void ShowHeap();

   private:
   	int *heap;
      int n;
      int maxSize;
};
//..................................................................................................
cMaxHeap :: cMaxHeap(int sz)
{
	maxSize = sz;
   n = 0;
   heap = new int[sz + 1];
   heap[0] = -1;
}
//..................................................................................................
void cMaxHeap :: ShowHeap()
{
	for(int i = 0;i < n;i ++)
   	cout << endl << i << " : " << heap[i];
}
//..................................................................................................
bool cMaxHeap :: IsFull()
{
	return n == maxSize;
}
//..................................................................................................
bool cMaxHeap :: IsEmpty()
{
	return n == 0;
}
//..................................................................................................
void cMaxHeap :: Insert(int newElement)
{
	if(IsFull())
   	return;

   int counter;
   n ++;
   for(counter = n;1;)
   {
   	if(counter == 1)
      	break;

      if(newElement <= heap[counter / 2])
      	break;

      heap[counter] = heap[counter / 2];
      counter /= 2;
   }

   heap[counter] = newElement;
}
//..................................................................................................
int cMaxHeap :: Delete()
{
	if(IsEmpty())
   	return -1;

	int i , j;
   int x = heap[1] , k = heap[n];
	n --;

   for(i = 1,j = 2;j <= n;)
   {
   	if(j < n)
      	if(heap[j] < heap[j + 1])
         	j ++;

   	if(k >= heap[j])
      	break;

      heap[i] = heap[j];
		i = j;
      j *= 2;
   }

   heap [i] = k;
   return x;
}
//..................................................................................................
//**************************************************************************************************
void main()
{
	cMaxHeap mh;
   randomize();
   for(int counter = 0;counter < 15;counter ++)
   {
      int x = rand() % 100;
   	mh.Insert(x);
   }
   mh.ShowHeap();
   getch();
}
//**************************************************************************************************
