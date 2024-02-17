#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

#define MAXSIZE 5

//******************************************************************************
class cArrayQ
{
	public :
   	cArrayQ();
      bool AddQ(int);
      bool DelQ();
      bool IsFull();
      bool IsEmpty();
      void Menu();
      void ShowQ();

   private:
   	int array[MAXSIZE];	//queue
      int front;				//front of queue
      int rear;				//bottom of queue
};
//..............................................................................
cArrayQ :: cArrayQ()
{
	for(int counter = 0;counter < MAXSIZE;counter ++)
   	array[counter] = 0;

   front = 0;
   rear = -1;
}
//..............................................................................
bool cArrayQ :: AddQ(int element)
{
	if(this -> IsFull() == true)
   	return false;

   rear = (rear + 1) % MAXSIZE;
   array[rear] = element;

   return true;
}
//..............................................................................
bool cArrayQ :: DelQ()
{
	if(this -> IsEmpty() == true)
   	return false;

   array[front] = 0;
   front = (front + 1)% MAXSIZE;

   return true;
}
//..............................................................................
bool cArrayQ :: IsFull()
{
	if(rear == -1)
   	return false;
	return (front == (rear + 1 ) % MAXSIZE) ? true : false;
}
//..............................................................................
bool cArrayQ :: IsEmpty()
{
	return (front == rear) ? true : false;
}
//..............................................................................
void cArrayQ :: ShowQ()
{
	for(int counter = 0;counter < MAXSIZE;counter ++)
   	cout << endl << counter << '\t' << array[counter] ;

   cout << endl << "front : " << front;
   cout << endl << "rear : " << rear << endl << endl;

   /*for(int counter = 0 , i = 0;counter < MAXSIZE;counter ++)
   {
   	if(array[counter] != 0)
      {
	   	cout << endl << i << '\t' << array[counter];
         i ++;
      }
   } */
}
//..............................................................................
void cArrayQ :: Menu()
{
	for(;;)
   {
		clrscr();
		cout << "\n\n\n\n\n\n\t\t\t\tA ) AddQ."
   	<< endl << "\t\t\t\tD ) DelQ."
   	<< endl << "\t\t\t\tS ) ShowQ."
   	<< endl << "\t\t\t\tF ) Is full."
   	<< endl << "\t\t\t\tE ) Is empty."
   	<< endl << "\t\t\t\tQ ) Quit.\n" ;

   	char select;

   	cin >> select ;

   	switch(select)
   	{
   		case 'a':
   		case 'A':
         	if(this -> IsFull() == false)
            {
      			int ele;
      			cout << "Enter element : ";
         		cin >> ele;
               this -> AddQ(ele);
            }
            else
            {
					cout << "\nThe queue is full.";
            	getch();
            }
      		break;
   		case 'd':
   		case 'D':
				if(this -> DelQ() == false)
            {
         		cout << "\nThe queue is empty.";
            	getch();
            }
      		break;
   		case 's':
   		case 'S':
      		this -> ShowQ();
            getch();
      		break;
   		case 'f':
   		case 'F':
      		if(IsFull() == true)
            	cout << "\nThe queue is full.";
            else
               cout << "\nThe queue is not full." ;
            getch();
      		break;
   		case 'e':
   		case 'E':
      		if(IsEmpty() == false)
            	cout << "\nThe queue is not empty.";
            else
               cout << "\nThe queue is empty." ;
      		getch();
      		break;
   		case 'q':
   		case 'Q':
         	exit(0);
      		break;
   	}
   }
}
//..............................................................................
//******************************************************************************
void main()
{
	cArrayQ q1;
   q1.Menu();
}
//******************************************************************************