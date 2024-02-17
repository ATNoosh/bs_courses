#include <iostream.h>
#include <conio.h>
#include <stdio.h>

//******************************************************************************
//******************************************************************************
class cChar
{
	friend class cString;

	public :
   	cChar(char = 0);
   private:
   	char ch;
      cChar *nextChar;
};
//..............................................................................
cChar :: cChar(char inited)
{
	ch = inited;
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
      void AddCharIn(char,int);   //Add char in location if(location > size)addlast

      void AddStrLast(char*);     //Add string at last
      void AddStrIn(char*,int);   //Add string in location

      void DeleteCharIn(int);     //Delete char in location

      cChar* operator[](int);		 //return s[int] if(location > size)return s[last]

      void PrintStr();

   private:
   	cChar *first;
      cChar *last ;

      cString *nextStr;
};
//..............................................................................
cString :: cString()
{
	first = last = 0;
}
//..............................................................................
void cString :: AddCharLast(char inited)
{
	cChar *temp;
   temp = new cChar(inited);	//cChar constructure called

 	if(last)
   {
		last -> nextChar = temp;
      last = temp;
      last -> nextChar = 0;
   }
   else
   {
   	first = last = temp;
      last -> nextChar = 0;
   }
}
//..............................................................................
void cString :: AddCharIn(char inited,int location)
{
	cChar *temp = first;
	cChar *newChar ;
   newChar = new cChar(inited);

   if(location < 0)
   	return;

   if(location == 0)
   {
   	newChar -> nextChar = first;
      first = newChar;
   }

   else
   {
		for(int counter = 0;counter < location - 1;counter ++)
  	 	{
      	if(temp == last)
         	break;

   		temp = temp -> nextChar;
   	}

      if(temp != last)
      {
   		newChar -> nextChar = temp -> nextChar ;
   		temp -> nextChar = newChar ;
         return;
      }
      else
      	AddCharLast(inited);
   }

}
//..............................................................................
void cString :: AddStrLast(char *initedStr)
{
	int length = strlen(initedStr);

   for(int counter = 0;counter < length;counter ++)
   {
   	AddCharLast(initedStr[counter]);
   }
}
//..............................................................................
void cString :: AddStrIn(char *initedStr,int location)
{
	int length = strlen(initedStr);

   for(int strCounter = 0,locCounter = location;strCounter < length;strCounter ++ ,locCounter ++)
   {
   	AddCharIn(initedStr[strCounter],locCounter);
   }
}
//..............................................................................
void cString :: DeleteCharIn(int location)
{
	cChar *temp1 = first , *temp2 ;

   if(location < 0)
   	return;

   if(location == 0)
   {
   	first = first -> nextChar;
      delete temp1;
      return;
   }

   else
   {
		for(int counter = 0;counter < location - 1;counter ++)
  	 	{
      	if(temp1 == last)
         	break;

   		temp1 = temp1 -> nextChar;
   	}

      if(temp1 != last)
      {
      	temp2 = temp1 -> nextChar;
         temp1 -> nextChar = temp1 -> nextChar -> nextChar;
         delete temp2;
      }
   }

}
//..............................................................................
cChar* cString :: operator[](int index)
{
	if(index == 0)
   	return first;

	cChar *temp;
   temp = first;

	for(int counter = 0;(counter < index)&&(temp != last);counter ++)
   	temp = temp -> nextChar;

   return temp;

}
//..............................................................................
void cString :: PrintStr()
{
	cChar *temp;
   temp = first;

   if(!first)
   	cout << "empty string.";
   else
   while(temp != last -> nextChar)
   {
   	cout << temp -> ch ;
   	temp = temp -> nextChar ;
   }

}
//..............................................................................
//******************************************************************************
//******************************************************************************
class cText
{
	public :
      cText();
      void AddStringLast(cString*);
      void AddStringIn(cString*,int);	//if(location > size)addlast

      cString* operator[](int);	//if(loc<0)first if(loc>size)last

      void DelStringIn(int);

      void ShowText();

   private:
   	cString *firstStr;
      cString *lastStr ;

};
//..............................................................................
cText :: cText()
{
	firstStr = lastStr = 0;
}
//..............................................................................
void cText :: AddStringLast(cString *initedStr)
{
	if(lastStr)
   {
		lastStr -> nextStr = initedStr;
   	lastStr = initedStr;
   	lastStr -> nextStr = 0;
   }
   else
   	firstStr = lastStr = initedStr;
}
//..............................................................................
void cText :: AddStringIn(cString *initedStr,int location)
{
	cString *temp = firstStr;

   if(location < 0)
   	return;

   if(location == 0)
   {
   	initedStr -> nextStr = firstStr;
      firstStr = initedStr;
   }

   else
   {
		for(int counter = 0;counter < location - 1;counter ++)
  	 	{
      	if(temp == lastStr)
         	break;

   		temp = temp -> nextStr;
   	}

      if(temp != lastStr)
      {
   		initedStr -> nextStr = temp -> nextStr ;
   		temp -> nextStr = initedStr ;
         return;
      }
      else
      	AddStringLast(initedStr);
   }

}
//..............................................................................
void cText :: DelStringIn(int location)
{
	cString *temp1 = firstStr , *temp2 ;

   if(location < 0)
   	return;

   if(location == 0)
   {
   	firstStr = firstStr -> nextStr;
      delete temp1;
      return;
   }

   else
   {
		for(int counter = 0;counter < location - 1;counter ++)
  	 	{
      	if(temp1 == lastStr)
         	break;

   		temp1 = temp1 -> nextStr;
   	}

      if(temp1 != lastStr)
      {
      	temp2 = temp1 -> nextStr;
         temp1 -> nextStr = temp1 -> nextStr -> nextStr;
         delete temp2;
      }
   }

}
//..............................................................................
cString* cText :: operator [] (int index)
{
	if(index == 0)
   	return firstStr;

	cString *temp;
   temp = firstStr;

	for(int counter = 0;(counter < index)&&(temp != lastStr);counter ++)
   	temp = temp -> nextStr;

   return temp;
}
//..............................................................................
void cText :: ShowText()
{
	cString *temp;
   temp = firstStr;

   if(!firstStr)
   	cout << "empty text.";
   else
   while(temp != lastStr -> nextStr)
   {
      temp -> PrintStr();
      cout << endl;
   	temp = temp -> nextStr ;
   }
}
//..............................................................................
//******************************************************************************
//******************************************************************************
void main()
{
	cString *s1,*s2,*s3,*s4;
   s1 = new cString;
   s2 = new cString;
   s3 = new cString;
   s4 = new cString;
   s1 -> AddCharLast('a');
   s1 -> AddCharLast('b');
   s1 -> AddCharLast('c');
   s1 -> AddCharLast('d');
   s1 -> AddCharLast('e');
   s1 -> AddCharLast('f');
   s1 -> AddCharLast('g');
   s1 -> AddCharLast('h');
   s1 -> PrintStr();
   cout << endl;
   s1 -> AddStrIn("ali tahmasebi",3);
   s1 -> PrintStr();

   cout << endl <<endl<<endl;
   s2 -> AddCharLast('A');
   s2 -> AddCharLast('B');
   s2 -> AddCharLast('C');
   s2 -> AddCharLast('D');
   s2 -> AddCharLast('E');
   s2 -> AddCharLast('F');
   s2 -> AddCharLast('G');
   s2 -> AddCharLast('H');
   s2 -> PrintStr();
   cout << endl;
   s2 -> AddStrIn("ALI TAHMASEBI",3);
   s2 -> PrintStr();

   cout << endl <<endl<<endl;
   s3 -> AddCharLast('i');
   s3 -> AddCharLast('j');
   s3 -> AddCharLast('k');
   s3 -> AddCharLast('l');
   s3 -> AddCharLast('m');
   s3 -> AddCharLast('n');
   s3 -> AddCharLast('o');
   s3 -> AddCharLast('p');
   cout << endl;
   s3 -> PrintStr();
   cout << endl <<endl<<endl;

   s4 -> AddCharLast('I');
   s4 -> AddCharLast('J');
   s4 -> AddCharLast('K');
   s4 -> AddCharLast('L');
   s4 -> AddCharLast('M');
   s4 -> AddCharLast('N');
   s4 -> AddCharLast('O');
   s4 -> AddCharLast('P');
   cout << endl;
   s4 -> PrintStr();

   cout << endl <<endl<<endl;
   cText t1;
   t1.AddStringLast(s1);
   t1.AddStringLast(s2);
   t1.AddStringLast(s3);
   t1.AddStringIn(s4,1);
   t1.ShowText();
   t1.DelStringIn(2);
   cout << endl << endl << endl;
   t1.ShowText();

   cout << endl << endl << endl;
   t1[0] -> PrintStr();
   getch();
}
//******************************************************************************
//******************************************************************************