#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

//******************************************************************************
struct sEdge
{
	char face1;
   char face2;
   int use;
};
//******************************************************************************
//..............................................................................
class cGraph
{
	public :
   	cGraph();
		void GetCubes();
      bool CheckValidity(char);
      void VerticsMaker();
      void VerticsCounter();
      void SetUses();
      void ShowDegs();
      bool MakeFrontBack();
      void MakeLeftRight();

   private:
   	sEdge edges[4][3];
      int frontBack[4];
      int leftRight[4];
      int *blueVertics;
      int blueDeg;
      int *redVertics;
      int redDeg;
      int *whiteVertics;
      int whiteDeg;
      int *greenVertics;
      int greenDeg;
};
//..............................................................................
cGraph :: cGraph()
{
	(**edges).face1 = 0;
	(**edges).face2 = 0;
   SetUses();
   blueVertics = 0;
   blueDeg = 0;
   redVertics = 0;
   redDeg = 0;
   whiteVertics = 0;
   whiteDeg = 0;
   greenVertics = 0;
   greenDeg = 0;
}
//..............................................................................
void cGraph :: GetCubes()
{
	for(int cubeCounter = 0;cubeCounter < 4;cubeCounter ++)
   {
		for(int faceCounter = 0;faceCounter < 3;faceCounter ++)
      {
      	cout << "Enter face number "<<faceCounter<<" of cube number"<<cubeCounter <<": ";
         cin >> edges[cubeCounter][faceCounter].face1;
         if(CheckValidity(edges[cubeCounter][faceCounter].face1)== false)
         {
         	faceCounter -= 2;
            continue;
         }
      	cout << "Enter back of this face in cube "<<cubeCounter<<"  : ";
         cin >> edges[cubeCounter][faceCounter].face2;
         if(CheckValidity(edges[cubeCounter][faceCounter].face2)== false)
         {
         	faceCounter -= 2;
            continue;
         }
      }
      cout << endl;
   }
}
//..............................................................................
bool cGraph :: CheckValidity(char ch)
{
	if(ch == 'r' || ch == 'w' || ch == 'b'|| ch == 'g')
   	return true ;

   return false;
}
//..............................................................................
void cGraph :: VerticsCounter()
{
	for(int cubeCounter = 0;cubeCounter < 4;cubeCounter ++)
   {
   	for(int faceCounter = 0;faceCounter < 3;faceCounter ++)
      {
      	switch(edges[cubeCounter][faceCounter].face1)
         {
         	case 'r':
           		++ redDeg  ;
              	break;
           	case 'b':
           		++ blueDeg ;
              	break;
           	case 'w':
           		++ whiteDeg;
              	break;
           	case 'g':
           		++ greenDeg;
              	break;
         }
      }
   }
}
//..............................................................................
void cGraph :: VerticsMaker()
{
	int redCounter ,blueCounter ,whiteCounter ,greenCounter;
   redCounter = blueCounter = whiteCounter = greenCounter = 0;

	this -> VerticsCounter();

   redVertics   = new int[redDeg ] ;
   blueVertics  = new int[blueDeg] ;
   whiteVertics = new int[whiteDeg];
   greenVertics = new int[greenDeg];

   for(int cubeCounter = 0;cubeCounter < 4;cubeCounter ++)
   {
   	for(int faceCounter = 0;faceCounter < 3;faceCounter ++)
      {
      	switch(edges[cubeCounter][faceCounter].face1)
         {
         	case 'r':
            	redVertics[redCounter++] = cubeCounter;
              	break;
           	case 'b':
           		blueVertics[blueCounter ++] = cubeCounter;
              	break;
           	case 'w':
           		whiteVertics[whiteCounter ++] = cubeCounter;
              	break;
           	case 'g':
           		greenVertics[greenCounter ++] = cubeCounter;
              	break;
         }
   	}
   }
}
//..............................................................................
void cGraph :: SetUses()
{
	for(int cubeCounter = 0;cubeCounter < 4;cubeCounter ++)
   	for(int faceCounter = 0;faceCounter < 3;faceCounter ++)
      	edges[cubeCounter][faceCounter].use = 0;
}
//..............................................................................
void cGraph :: ShowDegs()
{
	cout << "Deg(R) = " << redDeg << endl;
   for(int counter = 0;counter < redDeg;counter ++)
   	cout << endl << redVertics[counter];
   cout << endl;
	cout << "Deg(B) = " << blueDeg << endl;
   for(int counter = 0;counter < blueDeg;counter ++)
   	cout << endl << blueVertics[counter];
   cout << endl;
	cout << "Deg(W) = " << whiteDeg << endl;
   for(int counter = 0;counter < whiteDeg;counter ++)
   	cout << endl << whiteVertics[counter];
   cout << endl;
	cout << "Deg(G) = " << greenDeg << endl;
   for(int counter = 0;counter < greenDeg;counter ++)
   	cout << endl << greenVertics[counter];
}
//..............................................................................
//******************************************************************************
void main()
{
   for(;;){
	cGraph g1;
   clrscr();
   g1.GetCubes();
   g1.VerticsMaker();
   g1.ShowDegs();
   getch();
   }
}
//******************************************************************************
