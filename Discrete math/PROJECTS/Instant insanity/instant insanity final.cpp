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
      bool MakeFrontBack();
      bool MakeLeftRight();
      void Switch(char);
      bool Solve();
      void ShowAnswer();
      void ShowFrontBack();
      void ShowLeftRight();

   private:
   	sEdge edges[4][3];
      int frontBack[4];
      int leftRight[4];
      int blueCounter;
      int redCounter ;
   	int whiteCounter;
      int greenCounter ;
      int c0Counter;
      int c1Counter;
      int c2Counter;
      int c3Counter;

};
//..............................................................................
cGraph :: cGraph()
{
	(**edges).face1 = 0;
	(**edges).face2 = 0;
   c0Counter = c1Counter = c2Counter = c3Counter = 0;
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
bool cGraph :: Solve()
{
	if(MakeFrontBack() == false)
   	return false;

   if(MakeLeftRight() == false)
   	Solve();

  	return true;
}
//..............................................................................
bool cGraph :: MakeFrontBack()
{
   int cube0Counter ,cube1Counter ,cube2Counter ,cube3Counter ;

	for(cube0Counter = c0Counter ;cube0Counter < 3;cube0Counter ++)
   {
		for(cube1Counter = c1Counter ;cube1Counter < 3;cube1Counter ++)
   	{
			for(cube2Counter = c2Counter ;cube2Counter < 3;cube2Counter ++)
   		{
				for(cube3Counter = c3Counter ;cube3Counter < 3;cube3Counter ++)
   			{
            	blueCounter = redCounter = whiteCounter = greenCounter = 0;
               Switch(edges[0][cube0Counter].face1);
   				Switch(edges[0][cube0Counter].face2);
   				Switch(edges[1][cube1Counter].face1);
   				Switch(edges[1][cube1Counter].face2);
   				Switch(edges[2][cube2Counter].face1);
   				Switch(edges[2][cube2Counter].face2);
   				Switch(edges[3][cube3Counter].face1);
   				Switch(edges[3][cube3Counter].face2);

               if(redCounter == 2&&blueCounter == 2&&whiteCounter == 2&&greenCounter == 2)
            	{
               	edges[0][cube0Counter].use = 1;
               	edges[1][cube1Counter].use = 1;
               	edges[2][cube2Counter].use = 1;
               	edges[3][cube3Counter].use = 1;
               	frontBack[0] = cube0Counter;
               	frontBack[1] = cube1Counter;
               	frontBack[2] = cube2Counter;
               	frontBack[3] = cube3Counter;
               	if(c3Counter < 3)
                  {
                  	c3Counter = cube3Counter + 1;
                     return true;
                  }
                  if(c2Counter < 3)
                  {
                  	c2Counter = cube2Counter + 1;
                     return true;
                  }
                  if(c1Counter < 3)
                  {
                  	c1Counter = cube1Counter + 1;
                     return true;
                  }
                  if(c0Counter < 3)
                  {
                  	c0Counter = cube0Counter + 1;
                     return true;
                  }
               }
   			}
   		}
   	}
   }

   return false;
}
//..............................................................................
bool cGraph :: MakeLeftRight()
{
  	for(int cube0Counter = 0;cube0Counter < 3;cube0Counter ++)
   {
		for(int cube1Counter = 0;cube1Counter < 3;cube1Counter ++)
   	{
			for(int cube2Counter = 0;cube2Counter < 3;cube2Counter ++)
   		{
				for(int cube3Counter = 0;cube3Counter < 3;cube3Counter ++)
   			{
            	blueCounter = redCounter = whiteCounter = greenCounter = 0;

               if(edges[0][cube0Counter].use == 1 || edges[1][cube1Counter].use == 1)
               	continue;
               if(edges[2][cube2Counter].use == 1 || edges[3][cube3Counter].use == 1)
               	continue;
            	Switch(edges[0][cube0Counter].face1);
   				Switch(edges[0][cube0Counter].face2);
   				Switch(edges[1][cube1Counter].face1);
   				Switch(edges[1][cube1Counter].face2);
   				Switch(edges[2][cube2Counter].face1);
   				Switch(edges[2][cube2Counter].face2);
   				Switch(edges[3][cube3Counter].face1);
   				Switch(edges[3][cube3Counter].face2);

               if(redCounter == 2&&blueCounter == 2&&whiteCounter == 2&&greenCounter == 2)
            	{
               	leftRight[0] = cube0Counter;
               	leftRight[1] = cube1Counter;
               	leftRight[2] = cube2Counter;
               	leftRight[3] = cube3Counter;
                  return true;
               }
   			}
   		}
   	}
   }

   return false;

}
//..............................................................................
void cGraph :: Switch(char ch)
{
	switch(ch)
   {
   	case 'r':
      	redCounter ++;
         break;
   	case 'b':
      	blueCounter ++;
         break;
   	case 'w':
      	whiteCounter ++;
         break;
   	case 'g':
      	greenCounter ++;
         break;
   }
}
//..............................................................................
void cGraph :: ShowAnswer()
{
	ShowFrontBack();
   ShowLeftRight();
}
//..............................................................................
void cGraph :: ShowFrontBack()
{
	cout << "\n >> Front_Back : ";
	for(int counter = 0;counter < 4;counter ++)
   {
   	char tempChar;
      for(int inCounter = counter ;inCounter >= 0;inCounter --)
      	if(edges[counter][frontBack[counter]].face1 == edges[inCounter][frontBack[inCounter]].face1)
         {
         	tempChar = edges[counter][frontBack[counter]].face1;
            edges[counter][frontBack[counter]].face1 = edges[counter][frontBack[counter]].face2;
            edges[counter][frontBack[counter]].face2 = tempChar;
         }
   	cout << endl << "cube " << counter <<": "<< edges[counter][frontBack[counter]].face1;
   	cout << '\t' << edges[counter][frontBack[counter]].face2;
   }
}
//..............................................................................
void cGraph :: ShowLeftRight()
{
	cout << "\n >> Left_Right : ";
	for(int counter = 0;counter < 4;counter ++)
   {
   	char tempChar;
      for(int inCounter = counter ;inCounter >= 0;inCounter --)
      	if(edges[counter][frontBack[counter]].face1 == edges[inCounter][frontBack[inCounter]].face1)
         {
         	tempChar = edges[counter][frontBack[counter]].face1;
            edges[counter][frontBack[counter]].face1 = edges[counter][frontBack[counter]].face2;
            edges[counter][frontBack[counter]].face2 = tempChar;
         }
   	cout << endl << "cube " << counter <<": "<< edges[counter][frontBack[counter]].face1;
   	cout << '\t' << edges[counter][frontBack[counter]].face2;
   }
}
//..............................................................................
//******************************************************************************
void main()
{
	for(;;)
   {
   	cGraph g1;
   	clrscr();
   	g1.GetCubes();
   	if(g1.Solve() == true)
   		g1.ShowAnswer();
   	else
   		cout << endl << "***** For this problem isn't any answer! *****";
   	getch();
   }
}
//******************************************************************************