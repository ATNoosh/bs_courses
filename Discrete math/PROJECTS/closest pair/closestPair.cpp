#include <stdio.h>
#include <conio.h>
#include <math.h>
struct sPoint
{
	float x;
   float y;
   float number;
};
//Prototypes....................................................................
void MergeSort(sPoint *,int ,int ,char,sPoint *);//complete
void Merge(sPoint *,int ,int ,int ,char ,sPoint *);//complete
void GetArray(sPoint*,int);
float Distance(sPoint,sPoint);
sPoint ClosestPair(sPoint*,int);
sPoint recClosestPair(sPoint*,int,int);
//..............................................................................
void main()
{
	int size ;
   sPoint *array,*ansarray;
	printf("\nEnter size : ");
   scanf("%d",&size);

   array = new sPoint[size];
   ansarray = new sPoint[size];

   GetArray(array,size);

   printf("\nform Point %d to Point %d : %f",ClosestPair(array,size-1).x
   													  ,ClosestPair(array,size-1).y
                                            ,ClosestPair(array,size-1).number);

   getch();

}
//******************************************************************************
void GetArray(sPoint*array,int size)
{
   for(int counter = 0;counter < size;counter ++)
   {
   	printf("Enter array [%d].x : ",counter);
   	scanf("%f",&array[counter].x);
   	printf("Enter array [%d].y : ",counter);
   	scanf("%f",&array[counter].y);
      array[counter].number = counter;
   }
}
//******************************************************************************
sPoint ClosestPair(sPoint *array,int size)
{
	sPoint *ansarray;
   ansarray = new sPoint[size];

	MergeSort(array,0,size,'x',ansarray);

   return recClosestPair(array,0,size);
}
//******************************************************************************
sPoint recClosestPair(sPoint *array,int start,int end)
{
	sPoint minDistance;

   sPoint * ansarray;
   ansarray = new sPoint[end - start];

	if( (end - start) == 2)
   {
      /*MergeSort(array,start,end,'y',ansarray);

   	sPoint *distances ;		//distances{x->number of first point
      distances = new sPoint[end - start]; //y->number of second point
                                           //numberr -> distance
   	for(int iCounter = start;iCounter < (end - start) ;iCounter ++)
      {
			for(int jCounter = iCounter;jCounter < (end - start) ;jCounter ++)
         {
         	distances[iCounter].number = Distance(array[iCounter],array[jCounter]);
				distances[iCounter].x = array[iCounter].number;
				distances[iCounter].y = array[jCounter].number;
         }
      }

      //minimum finding:
      minDistance = distances[0];
      for(int counter = 1;counter < (end - start)*(end - start - 1) / 2;counter ++)
      {
      	if(distances[counter].number < minDistance.number )
         	minDistance = distances[counter];
      }*/

      sPoint *distances;
      distances = new sPoint[3];

      distances[0].number = Distance(array[start],array[end]);
      distances[0].x = start;
      distances[0].y = end;
      distances[1].number = Distance(array[start + 1],array[end]);
      distances[1].x = start + 1;
      distances[1].y = end;
      distances[2].number = Distance(array[start],array[start + 1]);
      distances[2].x = start;
      distances[2].y = start + 1;

      minDistance = distances[0];
      if(distances[1].number < minDistance.number)
      	minDistance = distances[1];
      if(distances[2].number < minDistance.number)
      	minDistance = distances[2];

      return minDistance;
   }

  	MergeSort(array,start,end,'x',ansarray);
   sPoint leftDis,rightDis;
   int mid = (start + end) / 2 ;
   float line ;

   line = array[mid].x ;
   leftDis = recClosestPair(array,start,mid);
   rightDis = recClosestPair(array,mid,end - 1);

   minDistance = leftDis;

   if(rightDis.number < minDistance.number)
   	minDistance = rightDis;

   Merge(array,start,mid,end,'y',ansarray);

   int stripCounter = 1;
   for(int counter = start;counter < end;counter ++)
   {
   	if(array[counter].x > (line - minDistance.number) && array[counter].x < (line + minDistance.number))
      	stripCounter ++;
	}

   sPoint *stripArr;
   stripArr = new sPoint[stripCounter];
   stripCounter = 0;

   for(int counter = start;counter < end;counter ++)
   {
   	if(array[counter].x > (line - minDistance.number) && array[counter].x < (line + minDistance.number))
      {
      	stripArr[stripCounter] = array[counter];
      	stripCounter ++;
      }
   }

   for(int iCounter = 0;iCounter <= stripCounter;iCounter ++)
   {
   	int min = stripCounter;
      if((iCounter + 7)< min)
      	min = iCounter + 7;

   	for(int jCounter = iCounter + 1;jCounter <= min;jCounter ++)
      {
      	float minimum = Distance(stripArr[iCounter],stripArr[jCounter]) ;
      	if(minDistance.number < minimum)
         	minimum = minDistance.number ;
      }
   }

   return minDistance;

}
//******************************************************************************
float Distance(sPoint p1,sPoint p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
//******************************************************************************
void MergeSort(sPoint *array,int start,int end,char xOry,sPoint *ansarray)
{
	if(start == end - 1)
   	return;

   int mid = (start + end) / 2 ;
   MergeSort(array,start,mid,xOry,ansarray);
   MergeSort(array,mid,end,xOry,ansarray);
   Merge(array,start,mid,end,xOry,ansarray);

   if(xOry == 'x')
   {
   	for(int counter = start;counter < end;counter ++)
   		array[counter].x = ansarray[counter].x;
   }

   else
   {
   	for(int counter = start;counter < end;counter ++)
   		array[counter].y = ansarray[counter].y;
   }
}
//******************************************************************************
void Merge(sPoint *array,int start,int mid,int end,char xOry,sPoint *ansArr)
{
   int firstHalfCounter = start ;
   int secondHalfCounter = mid ;
   int allCounter = start ;

   if(xOry == 'x')
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

   else
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
}
//******************************************************************************
