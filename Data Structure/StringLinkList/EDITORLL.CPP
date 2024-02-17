#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define UPARROW 72
#define DOWNARROW 80
#define RIGHTARROW 77
#define LEFTARROW 75

//******************************************************************************
class cChar
{
	friend class cString;

	public :
   	cChar(char = 0,int = 0,int = 0,bool = 0);
      void SetLocAndSel(int,int,bool);
      //void ppp(){cout <<endl<<ch<<' '<< row<<' '<<col;}
      void PrintChar();

   private:
   	char ch;
      int row;
      int col;
      bool select;

      cChar *next;
      cChar *pre;
};
//..............................................................................
cChar :: cChar(char character,int x,int y,bool isSel)
{
	ch = character;
   SetLocAndSel(x,y,isSel);
}
//..............................................................................
void cChar :: SetLocAndSel(int x,int y,bool isSel)
{
   row = x;
   col = y;
   select = isSel;
}
//..............................................................................
void cChar :: PrintChar()
{
	gotoxy(col,row);
   cout << ch;
}
//..............................................................................
//******************************************************************************
class cString
{
	public :
      cString();
      void PrintStr();
      void PrintLine(cChar *);
      cChar* AddChar(char,int,int);
      void DeleteNode(cChar*);
      void BackSpace(int,int);
      void SetLocations();
      void GetString();
      void ExtendedCode(int,int,int);
      void PrintCharInLoc(int,int);

   private:
   	cChar *first;
      cChar *last;
};
//..............................................................................
cString :: cString()
{
	first = last = NULL;
}
//..............................................................................
void cString :: PrintStr()
{
	if(!first)
   	return;
   //clrscr();
   cChar *temp = first ;

   while(temp != last -> next)
   {
   	//temp -> ppp();
   	temp -> PrintChar();
      temp = temp -> next;
   }
}
//..............................................................................
void cString :: PrintLine(cChar *charPtr)
{
	cChar *temp = charPtr;

   if(temp -> pre)
   {
   	while(temp && temp -> ch != '\n')
      	temp = temp -> pre;
   }

   while(temp != last -> next)
   {
   	gotoxy(temp -> col,temp -> row);
      cout << temp -> ch;
      temp = temp -> next;
   }
}
//..............................................................................
void cString :: PrintCharInLoc(int x,int y)
{
	if(!first)
   	return;

   cChar *temp = first;

   while(temp != last -> next)
   {
   	if(temp -> row == x && temp -> col == y)
      	break;
   	temp = temp -> next;
   }

   if(temp)
   {
   	//gotoxy(x , y);
   	cout << temp -> ch ;
	}
}
//..............................................................................
cChar* cString :: AddChar(char ch,int x,int y)
{
   cChar *newChar = new cChar(ch , x , y , false);
   cChar *temp;

	if(!first)
   {
   	first = last = newChar ;
      newChar -> SetLocAndSel(1,1,false);
      newChar -> next = NULL;
      newChar -> pre = NULL;
      return newChar;
   }

   if(y == 1 && x != 1)
   {
   	y = 80;
      x --;
   }
   else
   {
   	if(y == 1 && x == 1)
      {
      	newChar -> next = first;
         newChar -> pre = NULL;
         first -> pre = newChar;
         first = newChar;
         newChar -> SetLocAndSel(1,1,false);
         SetLocations();
         return newChar;
      }
      else
   		y --;
   }

   temp = first;

   while(temp)
   {
   	if(( temp -> row ) == x && ( temp -> col ) == y)
      	break;
   	temp = temp -> next;
   }

   if((temp != last) && (temp))
   {
   	newChar -> next = temp -> next;
      newChar -> pre = temp;
      (temp -> next) -> pre = newChar;
      temp -> next = newChar;
      SetLocations();
      return newChar;
   }
   else
   {
   	newChar -> next = NULL;
      newChar -> pre = last;
      last -> next = newChar;
      last = newChar;
      SetLocations();
      return newChar;
   }
}
//..............................................................................
void cString :: DeleteNode(cChar *delNode)
{
	if(!first)
   	return;

   if(first == delNode)
   {
   	cChar *temp = delNode;
      first = first -> next;
      first -> pre = NULL;
      delete temp;
      return;
   }

   if(last == delNode)
   {
   	cChar *temp = delNode;
      last = last -> pre;
      last -> next = NULL;
      delete temp;
      return;
   }

   cChar *temp = delNode;
   (delNode -> pre) -> next = delNode -> next;
   (delNode -> next) -> pre = delNode -> pre ;
   delete temp;

}
//..............................................................................
void cString :: BackSpace(int y,int x)
{
	cChar *temp;

   if(!first)
   	return;

   if(!(first -> next))
   {
   	delete first;
   	first = NULL;
      return;
   }

   if(y == 1 && x == 1 )
   	return;

   if((first -> row == x) && (first -> col == y))
   {
   	temp = first;
      first = first -> next;
      first -> pre = 0;
      delete temp;
      SetLocations();
      return;
   }

   temp = first -> next;

   if(temp == last)
   {
   	last = first;
      first -> next = NULL;
      first -> pre = NULL;
      delete temp;
      SetLocations();
      return;
   }

   while(temp != last -> pre )
   {
      if(!temp)
      {
      	return;
      }

   	if((temp -> row == x) && (temp -> col == y))
      	break;

      temp = temp -> next;
   }

	DeleteNode(temp -> next);
   SetLocations();

}
//..............................................................................
void cString :: ExtendedCode(int ch,int y,int x)
{
	switch(ch)
   {
   	case UPARROW:
      	if(y > 1)
         {
         	gotoxy(x,y-1);
            PrintCharInLoc(x,y - 1);
         }
      	break;
      case DOWNARROW:
      	break;
      case LEFTARROW:
      	break;
      case RIGHTARROW:
      	break;
   }
}
//..............................................................................
void cString :: SetLocations()
{
   if(!first)
   	return;

   first -> SetLocAndSel(1,1,0);

	cChar *temp = first -> next;

   if(!temp)
   	return;

   while(temp != last -> next)
   {
   	int x = temp -> pre -> row;
   	int y = temp -> pre -> col;
      char preCh = temp -> pre -> ch;
      if(y > 80 || preCh == '\n')
      	temp -> SetLocAndSel(x + 1, 1, 0);
      else
      	temp -> SetLocAndSel(x , y + 1,0);
   	temp = temp -> next;
   }
}
//..............................................................................
//..............................................................................
void cString :: GetString()
{
	int x , y , ch ;
   cChar *temp;

	for(;;)
   {
   	for(;;)
   	{
      	x = wherex();
      	y = wherey();
   		ch = getche();

      	if(ch == 13)
      	{
      		temp = AddChar('\n',y,x);
      		break;
      	}

         if(ch == 8)  //back space
         {
         	BackSpace(x , y);
            break;
            //continue;
         }

         if(ch == 0)//extended code
         {
         	ch = getch();
         	ExtendedCode(ch , y , x);
            continue;
         }

      	temp = AddChar(ch,y,x);
   	}
      //clrscr();
	   //PrintStr();
      PrintLine(temp);
   }
}
//..............................................................................
//******************************************************************************
//******************************************************************************
int main()
{
	cString s1;
   s1.GetString();
	getch();
	return 0;
}
