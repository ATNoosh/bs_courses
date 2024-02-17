#include <iostream.h>
#include <conio.h>
#include <stdio.h>

//******************************************************************************
class cString
{
	public :
   	cString();
      void Failure();
      void GetString();
      void ShowFail();
      int FastFind(cString);

   private:
   	char str[200];
      int *fail;
      int size ;
};
//..............................................................................
cString :: cString()
{
   size = 0;
}
//..............................................................................
void cString :: Failure()
{
	fail = new int[size];

   fail[0] = -1;

   for(int j = 1 ; j < size ; j++)
   {
   	int i = fail[j - 1];

      while( ( str[j] != str[i + 1] ) && ( i >= 0 ) )
      	i = fail[i];

      if(str[j] == str[i + 1])
      	fail[j] = i + 1;
      else
      	fail[j] = -1;
   }
}
//..............................................................................
int cString :: FastFind(cString pat)
{
	int posPat = 0 , posStr = 0;

   while((posPat < pat.size) && (posStr < size))
   {
   	if(pat.str[posPat] == str[posStr])
      {
      	posStr ++;
         posPat ++;
      }
      else
      {
      	if(posPat == 0)
         	posStr ++;
         else
         	posPat = pat.fail[posPat - 1] + 1;
      }
   }

   if(posPat < pat.size)
   	return -1;
   else
   	return posStr - pat.size;
}
//..............................................................................
void cString :: ShowFail()
{
	for(int counter = 0;counter < size;counter ++)
   {
   	cout << str[counter] << "\t" << fail[counter] << endl;
   }
}
//..............................................................................
void cString :: GetString()
{
	gets(str);
   size = strlen(str);
}
//..............................................................................
//******************************************************************************
void main()
{
	cString s1 , p1;

   for(;;)
   {
   	s1.GetString();
      p1.GetString();
   	p1.Failure();
   	//s1.Failure();
   	cout << endl << s1.FastFind(p1);

   	if(getch() == 27)break;

      clrscr();
   }
}
