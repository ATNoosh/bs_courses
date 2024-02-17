#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <time.h>

//Definitions :
struct sClient
{
    long startTime;
    long duration;
};

sClient clients[100];
long tellersEndTime[30];
long tellersNumber = 0;
long clientNumber = 0;
long currentTime = 0;
long totalClientDelay = 0;

void PrintTotalQueue();
void AddClientToTotalQueue(int,int);
void AddTeller(long);
void PrintTellersEndTime();
void PrintIdleTellers();
void AddClientToTeller(long,long);
//**************************************************************************************************
int main()
{
    struct time t ;
    long temp;
    gettime(&t);
    currentTime = t.ti_hour*3600 + t.ti_min*60 + t.ti_sec;

    AddTeller(currentTime);
    AddTeller(currentTime);
    AddTeller(currentTime);

    for(int i = 0;i < 10;i ++)
    {
    	cin >> temp;
    	gettime(&t);
    	currentTime = t.ti_hour*3600 + t.ti_min*60 + t.ti_sec;
      AddClientToTotalQueue(currentTime,temp);
      PrintIdleTellers();

    }
    PrintTotalQueue();
    getch();
}
//**************************************************************************************************
void AddClientToTotalQueue(int enterTime,int duration)
{
	clients[clientNumber].startTime = enterTime;
	clients[clientNumber].duration = duration;
   clientNumber ++;
}
//**************************************************************************************************
void AddTeller(long newEndTime)
{
    tellersEndTime[tellersNumber] = newEndTime;
    tellersNumber ++;
}
//**************************************************************************************************
void PrintIdleTellers()
{
	for(long i = 0;i < tellersNumber;i ++)
   {
   	if(currentTime >= tellersEndTime[i])
      	cout << "Teller < " << i << " > is idle.";
   }
}
//**************************************************************************************************
void PrintTellersEndTime()
{
    for(long i = 0;i < tellersNumber;i ++)
        cout << endl << "Teller <" << i << "> : " << tellersEndTime[i];
}
//**************************************************************************************************
void AddClientToTeller(long tellerNumber,long clientNumber)
{
	tellersEndTime[tellerNumber] += clients[clientNumber].duration;
   totalClientDelay += tellersEndTime[tellerNumber] - clients[clientNumber].startTime ;
}
//**************************************************************************************************
void PrintTotalQueue()
{
	for(int counter = 0;counter < 100;counter ++)
   	cout << endl << clients[counter].startTime << "  " << clients[counter].duration;
}
//**************************************************************************************************
