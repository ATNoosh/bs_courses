#include <iostream.h>
#include <conio.h>
#include <stdio.h>

#define ENTER 13

//******************************************************************************
//******************************************************************************
class cChar
{
	friend class cString;

	public :
   	cChar(char = 0,int = 0,int = 0);
      void SetLocation(int,int);
      void PrintChar();

   private:
   	char ch;
      int x;
      int y;
      cChar *nextChar;
      cChar *preChar;
};
//..............................................................................
cChar :: cChar(char inited,int row,int col)
{
	ch = inited;
	SetLocation(row,col);
}
//..............................................................................
void cChar :: SetLocation(int row,int col)
{
	x = row;
   y = col;
}
//..............................................................................
void cChar :: PrintChar()
{
	gotoxy(x,y);
   cout << ch;
}
//..............................................................................
//******************************************************************************
//******************************************************************************
class cString
{
   friend class cText;

	public :
   	cString();

      void AddCharLast(char);     //Add char in last of linked list
      void AddCharIn(char,int,int);   //Add char in location if(location > size)addlast
      void SetAfterAdd(cChar*);

      void AddStrLast(char*);     //Add string at last
      void AddStrIn(char*,int);   //Add string in location

      void DeleteCharIn(int);     //Delete char in location

      cChar* operator[](int);		 //return s[int] if(location > size)return s[last]

      void PrintStr();

   private:
   	cChar *first;
      cChar *last ;
};
//..............................................................................
cString :: cString()
{
	first = last = 0;
}
//..............................................................................
void cString :: AddCharLast(char inited)
{
	cChar *newChar;

   if(last)
   {
 		if(( last -> ch != '\n' ) && (last -> x == 79))
			newChar = new cChar(inited,(last -> x) + 1,(last -> y));
   	else
   		newChar = new cChar(inited,0,(last -> y) + 1);

  		newChar -> preChar = last;
   	last -> nextChar = newChar;
   	newChar -> nextChar = 0;
   	last = newChar;
   }
   else
   {
   	newChar = new cChar(inited,0,0);
   	first = last = newChar;
      newChar -> nextChar = 0;
      newChar -> preChar = 0;
   }
}
//..............................................................................
void cString :: AddCharIn(char inited,int row,int col)
{
   cChar *newChar = new cChar(inited,row,col);

   if(col > 0)
   	col --;
   else
   {
   	col = 79;
      row --;
   }

	if(!last)
   {
   	AddCharLast(inited);
      return;
   }

   if((row == -1) && (col == 79))
   {
   	newChar -> nextChar = first ;
		newChar -> preChar = 0 ;
		first = newChar;
      SetAfterAdd(newChar -> nextChar);
      return;
   }

   cChar *temp = first;

   while(temp)
   {
		if((temp -> x == row) && (temp -> y == col))
      	break;
      temp = temp -> nextChar;
   }

   newChar -> nextChar = temp -> nextChar;
	newChar -> preChar = temp ;
   (temp -> nextChar) -> preChar = newChar;
   temp -> nextChar = newChar;

   SetAfterAdd(newChar -> nextChar);

}
//..............................................................................
void cString :: SetAfterAdd(cChar *inited)
{
	cChar *temp = inited;

   while((temp -> ch )!= '\n')
   {
   	(temp -> x) ++ ;
   }
}
//..............................................................................
void cString :: AddStrLast(char *initedStr)
{
}
//..............................................................................
void cString :: AddStrIn(char *initedStr,int location)
{
}
//..............................................................................
void cString :: DeleteCharIn(int location)
{
}
//..............................................................................
cChar* cString :: operator[](int index)
{
}
//..............................................................................
void cString :: PrintStr()
{
	cChar *temp = first;

   if(!first)
   {
   	cout << "EMPTY STRING.";
      return;
   }

   while(temp)
   {
   	temp -> PrintChar();
      temp = temp -> nextChar;
   }

}
//..............................................................................
//******************************************************************************
//******************************************************************************
void main()
{
	cString s1;
   for(int counter = 0;counter < 50;counter ++)
   	s1.AddCharLast('A');
      s1.AddCharLast('\n');
   for(int counter = 0;counter < 50;counter ++)
   	s1.AddCharLast('A');

   s1.AddCharIn('G',1,0);
   s1.PrintStr();
   getch();
}
//******************************************************************************
//******************************************************************************
