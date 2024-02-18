#include <stdio.h>
#include <conio.h>
#include <math.h>
struct sPoint
{
	float x;
   float y;
   int number;
};
struct sDistance
{
	int p1;
   int p2;
   float distance;
};
//******************************************************************************
sDistance ClosestPair(sPoint *,int);
sDistance RecClosestPair(sPoint *,int,int);
sDistance Distance(sPoint,sPoint);
int StripSize(sPoint*,int,float,float);
void Merge(sPoint*,int,int,int,char,sPoint*);
void MergeSort(sPoint*,int,int,char,sPoint*);
void ShowPoints(sPoint*,int );
int Minimum(int,int);
//******************************************************************************
//******************************************************************************
void main()
{
	int size ;
   sPoint *array,*ansarray;
//get array.....................................................................
   printf("Enter number of Points : ");
   scanf("%d",&size);

   array = new sPoint[size];

   for(int counter = 0;counter < size ;counter ++)
   {
   	printf("\nPoint %d -> x : ",counter + 1);
      scanf("%f",&array[counter].x);
      printf("Point %d -> y : ",counter + 1);
      scanf("%f",&array[counter].y);

      array[counter].number = counter + 1;
   }
//..............................................................................

	sDistance forPrint = ClosestPair(array,size);

   printf("\nfrom point %d to point %d : %f",forPrint.p1
   													  ,forPrint.p2
                                            ,forPrint.distance);

   getch();

}
//******************************************************************************
//******************************************************************************
sDistance ClosestPair(sPoint *array,int size)
{
	sPoint *ansarray;
   ansarray = new sPoint[size];

	MergeSort(array,0,size,'x',ansarray);

   return RecClosestPair(array,0,size);
}
//******************************************************************************
//******************************************************************************
sDistance RecClosestPair(sPoint *array,int start,int end)
{
	sDistance minDistance;

	if(end - start == 3)
   {
   	sPoint *ansarray;
      ansarray = new sPoint[3];

   	MergeSort(array,start,end,'y',ansarray);

   	sDistance *distances;
      distances = new sDistance[3];

      distances[0] = Distance(array[start],array[end - 1]);
      distances[1] = Distance(array[start + 1],array[end - 1]);
      distances[2] = Distance(array[start],array[start + 1]);

      minDistance = distances[0];
      if(distances[1].distance < minDistance.distance)
      	minDistance = distances[1];
      if(distances[2].distance < minDistance.distance)
      	minDistance = distances[2];

      return minDistance;
   }

   if(end - start == 2)
   {
   	sPoint *ansarray;
      ansarray = new sPoint[2];

   	MergeSort(array,start,end,'y',ansarray);
		return Distance(array[start],array[end-1]);
   }
   if(end - start == 1)
   {
   	minDistance.distance = 100000;
   	minDistance.p1 = 0;
   	minDistance.p2 = 0;
      return minDistance;
   }

   int mid;
   float midLine;
   sDistance leftDistance,rightDistance;

   mid = (start + end) / 2;
   midLine = array[mid].x;

   leftDistance = RecClosestPair(array,start,mid);
   rightDistance = RecClosestPair(array,mid + 1,end);

   minDistance = leftDistance;
   if(rightDistance.distance < minDistance.distance)
   	minDistance = rightDistance;

   sPoint *ansarray;
   ansarray = new sPoint[end - start];

   MergeSort(array,start,end,'y',ansarray);

   sPoint *stripArr;
   //stripArr = new sPoint[StripSize(array,end - start,midLine,minDistance.distance)+1];
   stripArr = new sPoint[end - start];

   int stripCounter = 0;
   for(int counter = start;counter < end;counter ++)
   {
   	if((array[counter].x > midLine - minDistance.distance) && (array[counter].x < midLine + minDistance.distance))
      {
      	stripArr[stripCounter] = array[counter];
         stripCounter ++;
      }
   }

   /*for(int outCounter = 0;outCounter < stripCounter;outCounter ++)
   {
   	for(int inCounter = outCounter + 1;inCounter < Minimum(stripCounter - 1, outCounter + 7);inCounter ++)
      {
      	if((Distance(stripArr[inCounter],stripArr[outCounter])).distance < minDistance.distance)
      		minDistance = Distance(stripArr[inCounter],stripArr[outCounter]);
      }
   }*/

	for(int outCounter = 0;outCounter < stripCounter;outCounter ++)
   {
   	for(int inCounter = outCounter + 1;(inCounter < stripCounter ) || (inCounter < outCounter + 7);inCounter ++)
      {
      	if((Distance(stripArr[inCounter],stripArr[outCounter])).distance < minDistance.distance)
      		minDistance = Distance(stripArr[inCounter],stripArr[outCounter]);
      }
   }

   return minDistance;

}
//******************************************************************************
//******************************************************************************
int Minimum(int a,int b)
{
	if(a < b)
   	return a;

   return b;
}
//******************************************************************************
//******************************************************************************
int StripSize(sPoint* array,int size,float midLine,float minDis)
{
	int numOfPoints = 0;

	for(int counter = 0;counter < size;counter ++)
   {
   	if((array[counter].x > midLine - minDis) && (array[counter].x < midLine + minDis))
      	numOfPoints ++;
   }

   return numOfPoints;
}
//******************************************************************************
//******************************************************************************
sDistance Distance(sPoint point1,sPoint point2)
{
	sDistance forReturn;
	forReturn.distance = sqrt((point1.x - point2.x)*(point1.x - point2.x) + (point1.y - point2.y)*(point1.y - point2.y));
   forReturn.p1 = point1.number;
	forReturn.p2 = point2.number;

   return forReturn;
}
//******************************************************************************
//******************************************************************************
void ShowPoints(sPoint*array,int size)
{
	for(int counter = 0;counter < size ;counter ++)
   {
   	printf("\n%d . point %d : (%f , %f)",counter+1,array[counter].number,array[counter].x,array[counter].y);
   }
}
//******************************************************************************
//******************************************************************************
void Merge(sPoint *array,int start,int mid,int end,char coordinate,sPoint *ansArr)
{
   int firstHalfCounter = start ;
   int secondHalfCounter = mid ;
   int allCounter = start ;
//..............................................................................
   if(coordinate == 'x')
   {
   	while(firstHalfCounter < mid && secondHalfCounter < end)
   	{
   		if(array[firstHalfCounter].x < array[secondHalfCounter].x)
      	{
      		ansArr[allCounter] = array[firstHalfCounter];
         	firstHalfCounter ++;
      	}
      	else
      	{
      		ansArr[allCounter] = array[secondHalfCounter];
         	secondHalfCounter ++;
      	}

      	allCounter ++;
   	}

   	while(firstHalfCounter < mid)
   	{
   		ansArr[allCounter] = array[firstHalfCounter];
      	firstHalfCounter ++;
      	allCounter ++;
   	}
   	while(secondHalfCounter < end)
   	{
   		ansArr[allCounter] = array[secondHalfCounter];
      	secondHalfCounter ++;
      	allCounter ++;
   	}
   }
//..............................................................................

	if(coordinate == 'y')
   {
   	while(firstHalfCounter < mid && secondHalfCounter < end)
   	{
   		if(array[firstHalfCounter].y < array[secondHalfCounter].y)
      	{
      		ansArr[allCounter] = array[firstHalfCounter];
         	firstHalfCounter ++;
      	}
      	else
      	{
      		ansArr[allCounter] = array[secondHalfCounter];
         	secondHalfCounter ++;
      	}

      	allCounter ++;
   	}

   	while(firstHalfCounter < mid)
   	{
   		ansArr[allCounter] = array[firstHalfCounter];
      	firstHalfCounter ++;
      	allCounter ++;
   	}
   	while(secondHalfCounter < end)
   	{
   		ansArr[allCounter] = array[secondHalfCounter];
      	secondHalfCounter ++;
      	allCounter ++;
   	}
   }
//..............................................................................
}
//******************************************************************************
//******************************************************************************
void MergeSort(sPoint *array,int start,int end,char coordinate,sPoint *ansarray)
{
	if(start == end - 1)
   	return;

   int mid = (start + end) / 2 ;
   MergeSort(array,start,mid,coordinate,ansarray);
   MergeSort(array,mid,end,coordinate,ansarray);
   Merge(array,start,mid,end,coordinate,ansarray);

   for(int counter = start;counter < end;counter ++)
   	array[counter] = ansarray[counter];
}
//******************************************************************************
//******************************************************************************
