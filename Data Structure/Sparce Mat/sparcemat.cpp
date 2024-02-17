#include <iostream.h>
#include <conio.h>

#define MAX_SIZE 100

class cMatrixTerm
{
	friend class cSparceMatrix;

   private:
   	int row;
      int col;
      int value;
};
//******************************************************************************
class cSparceMatrix
{
	public :
   	cSparceMatrix();
      ~cSparceMatrix(){}
      cSparceMatrix Transpose();
      cSparceMatrix FastTranspose();
      void ShowSM();

   private:
      int rows;
      int cols;
      int terms;
      cMatrixTerm termArray[MAX_SIZE];
};
//..............................................................................
cSparceMatrix :: cSparceMatrix()
{
	rows = 5;
   cols = 4;
   terms = 3;
   termArray[0].row = 1;
   termArray[0].col = 3;
   termArray[0].value = 21;
   termArray[1].row = 2;
   termArray[1].col = 2;
   termArray[1].value = 15;
   termArray[2].row = 2;
   termArray[2].col = 3;
   termArray[2].value = 71;
}
//..............................................................................
void cSparceMatrix :: ShowSM()
{
	for(int termCounter = 0;termCounter < terms;termCounter ++)
   {
   	cout << endl << "term[" << termCounter << "] : ";
      cout << endl << "row : " << termArray[termCounter].row;
      cout << endl << "col : " << termArray[termCounter].col;
      cout << endl << "value : " << termArray[termCounter].value;
   }
}
//..............................................................................
cSparceMatrix cSparceMatrix :: Transpose()
{
	cSparceMatrix forReturn;

   forReturn.rows = cols;
   forReturn.cols = rows;
   forReturn.terms = terms;

   if(terms > 0)
   {
   	int counter = 0;

   	for(int colCounter = 0;colCounter < cols;colCounter ++)
      {
      	for(int termCounter = 0;termCounter < terms;termCounter ++)
         {
         	if(termArray[termCounter].col == colCounter)
            {
            	forReturn.termArray[counter].row = colCounter;
            	forReturn.termArray[counter].col = termArray[termCounter].row;
					forReturn.termArray[counter].value = termArray[termCounter].value;

            	counter ++;
            }
         }
      }

   }

   return forReturn;
}
//..............................................................................
//..............................................................................
cSparceMatrix cSparceMatrix :: FastTranspose()
{
   int *rowSize = new int [cols];
	int *rowStart = new int [cols];
	cSparceMatrix forReturn;

   forReturn.rows = cols;
   forReturn.cols = rows;
   forReturn.terms = terms;

   if(terms > 0)
   {
   	for(int counter = 0;counter < cols;counter ++)
      	rowSize[counter] = 0;

      for(int counter = 0;counter < terms;counter ++)
      	rowSize[termArray[counter].col] ++;

      rowStart[0] = 0;

      for(int counter = 0;counter < cols;counter ++)
      	rowStart[counter] = rowStart[counter - 1] + rowSize[counter - 1];

      for(int counter = 0;counter < terms;counter ++)
      {
      	int tempIndex = rowStart[termArray[counter].col];

         forReturn.termArray[tempIndex].row = termArray[counter].col;
         forReturn.termArray[tempIndex].col = termArray[counter].row;
         forReturn.termArray[tempIndex].value = termArray[counter].value;

         rowStart[termArray[counter].col] ++;
      }
   }

   delete [] rowSize;
   delete [] rowStart;
   return forReturn;
}
//..............................................................................
//******************************************************************************
void main()
{
	cSparceMatrix sm1,sm2;
   sm1.ShowSM();

   cout << "\n\n";

   sm2 = sm1.FastTranspose();
   sm2.ShowSM();

   getch();
}
