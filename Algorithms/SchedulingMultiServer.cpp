#include <iostream.h>
#include <conio.h>

//******************************************************************************
class cWork
{
    public :
        cWork();
        
        int enterTime;
        int duration;
        
        cWork *next;
        
    private:
};
//..............................................................................
cWork :: cWork()
{
    enterTime = duration = 0;
}
//..............................................................................
//******************************************************************************
class cWorkList
{
    public :
        cWorkList();
        
        void AddWork(cWork*);
        void RemoveWork();
        void ShowWorks();
        cWorkList *next;
        int endTime;
        
    private:
        cWork *firstWork;
        cWork *lastWork;
};
//..............................................................................
cWorkList :: cWorkList()
{
    endTime = 0;
    firstWork = lastWork = 0;
}
//..............................................................................
void cWorkList :: AddWork(cWork *newWork)
{
    if(!firstWork)
    {
        firstWork = lastWork = newWork;
        endTime += newWork -> duration;
        return;
    }
    lastWork -> next = newWork;
    lastWork = lastWork -> next;
    endTime += newWork -> duration;
}
//..............................................................................
void cWorkList :: RemoveWork()
{
    if(!firstWork)return;
    cWork *temp = firstWork;
    firstWork = firstWork -> next;
    delete temp;
}
//..............................................................................
void cWorkList :: ShowWorks()
{
    cout << "End Time : " << endTime << endl;
    if(!firstWork)return;
    cWork *temp = firstWork;
    while(1)
    {
        if(temp == lastWork -> next)break;
        cout << "\tEnter Time : " << temp -> enterTime << endl
             << "\tDuration Time : " << temp -> duration;
        temp = temp -> next;
    }
}    
//******************************************************************************
class cQueueList
{
    public :
        cQueueList();
        
        void ShowQueues();
        void AddQueue(cWorkList*);
        void AddWork(cWork*);
        
    private:
        cWorkList *firstQueue;
        cWorkList *lastQueue;
        cWorkList *minEndTime;
};
//..............................................................................
cQueueList :: cQueueList()
{
    firstQueue = lastQueue = 0;
}
//..............................................................................
void cQueueList :: AddQueue(cWorkList *newQueue)
{
    if(!firstQueue)
    {
        firstQueue = lastQueue = minEndTime = newQueue;
        return;
    }
    if((minEndTime -> endTime) < (newQueue -> endTime))
        minEndTime = newQueue;
    lastQueue -> next = newQueue;
    lastQueue = lastQueue -> next;
}
//..............................................................................
void cQueueList :: ShowQueues()
{
    if(!firstQueue)
        return;
    cWorkList *temp = firstQueue;
    while(1)
    {
        if(temp == lastQueue -> next)break;
        temp -> ShowWorks();
        temp = temp -> next;
    }
}
//..............................................................................
void cQueueList :: AddWork(cWork *newWork)
{
    minEndTime -> AddWork(newWork);
}
//..............................................................................
//******************************************************************************
int main()
{
    cQueueList *manager = new cQueueList();
    
    cWorkList *wl1 = new cWorkList();
    cWork *w1 = new cWork();
    w1 -> enterTime = 20;
    w1 -> duration = 30;
    
    wl1 -> AddWork(w1);
    manager -> AddQueue(wl1);
    
    manager -> ShowQueues();
    getch();
}
