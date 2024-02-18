/*Ali Tahmasebi*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

/*STRUCTURES*///................................................................
struct sPoint
{
	float x;
   float y;
   float z;
   int number;
};

struct sDistance
{
	float distance;
   int firstPoint;
   int secondPoint;
};

/*FUNCTIONS PROTOTYPES*///......................................................
sDistance Distance(const sPoint &,const sPoint &);
sDistance MinDistance(sDistance*,int );
void GetPointsFromUser();
//..............................................................................
void main()
{
	GetPointsFromUser();
   getch();
}
/*FUNCTIONS*///*****************************************************************
void GetPointsFromUser()
{
	int numberOfPoints;
   sPoint *pointArr;

	printf("Input number of points :");
   scanf("%d",&numberOfPoints);

   pointArr = new sPoint[numberOfPoints];

   for(int counter = 0;counter < numberOfPoints;counter ++)
   {
   	printf("Point %d :\nx ? " , counter);
      scanf("%f" , &pointArr[counter].x);
      printf("y ? ");
      scanf("%f" , &pointArr[counter].y);
      printf("z ? ");
      scanf("%f" , &pointArr[counter].z);
      pointArr[counter].number = counter;

   }

   sDistance *distanceArr , tempDistance;
   distanceArr = new sDistance[numberOfPoints * (numberOfPoints - 1) / 2];

   for(int outCounter = 0,distanceArrCounter = 0;outCounter < numberOfPoints;outCounter ++)
   	for(int inCounter = outCounter + 1;inCounter < numberOfPoints;inCounter ++)
      {
      	distanceArr[distanceArrCounter ++] = Distance(pointArr[outCounter] , pointArr[inCounter]);
      }

   tempDistance = MinDistance(distanceArr,numberOfPoints * (numberOfPoints - 1) / 2);

   printf("\nMinimum Distance is : %f",tempDistance.distance);
   printf("\nFrom Point %d To Point %d",tempDistance.firstPoint , tempDistance.secondPoint);

}
//******************************************************************************
//******************************************************************************
sDistance Distance(const sPoint &p1,const sPoint &p2)
{
	sDistance temp;

   temp.distance = sqrt((p1.x - p2.x)*(p1.x - p2.x)
   						+ (p1.y - p2.y)*(p1.y - p2.y)
                     + (p1.z - p2.z)*(p1.z - p2.z));
   temp.firstPoint = p1.number;
   temp.secondPoint = p2.number;

   return temp;
}
//******************************************************************************
//******************************************************************************
sDistance MinDistance(sDistance* distanceArr, int number)
{
	sDistance minDistance = distanceArr[0] ;

   for(int counter = 0;counter < number;counter ++)
   	if(distanceArr [counter].distance < minDistance.distance)
      	minDistance = distanceArr[counter];

   return minDistance;
}
//******************************************************************************
