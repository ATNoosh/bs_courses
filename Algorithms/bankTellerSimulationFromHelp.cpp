#include <vector.h>
#include <queue.h>
#include <iostream.h>
#include <conio.h>

using namespace std;

unsigned int randomInteger (unsigned int n)

// return random integer greater than
	// or equal to 0 and less than n
{
	return rand() % n;

}

class Customer
{
	public:
		Customer (int at = 0) : arrival_Time(at),
		processTime(2 + randomInteger(6)) {}

		int arrival_Time;
      int processTime;

		bool done()	// are we done with our transaction?
		{ return --processTime < 0; }

		operator < (const Customer & c)	// order by arrival time
		{ return arrival_Time < c.arrival_Time; }

		operator == (const Customer & c)	// no two customers are alike
		{ return false; }
};
class Teller
{
	public:
		Teller()
      { free = true; }
		bool isFree()	// are we free to service new customer?
		{
      	if (free) return true;
		  	if (customer.done())
		  		free = true;
		  	return free;
      }

		void addCustomer(Customer c)	// start serving new customer
		{
      	customer = c;
			free = false;
		}
	private:
		bool free;
		Customer customer;
};

void main() {

	int numberOfTellers = 5;
	int numberOfMinutes = 600000;
	double totalWait = 0;
	int numberOfCustomers = 0;
   for(;;){
	vector<Teller> teller(numberOfTellers);
	queue< Customer, deque<Customer> > line;

	for (int time = 0; time < numberOfMinutes; time++)
   {
		if (randomInteger(10) < 9)
			line.push(Customer(time));
		for (int i = 0; i < numberOfTellers; i++)
      {
			if (teller[i].isFree() & ! line.empty())
         {
				Customer & frontCustomer = line.front();
				numberOfCustomers++;
				totalWait += (time - frontCustomer.arrival_Time);
				teller[i].addCustomer(frontCustomer);
				line.pop();
         }
      }
   }
	cout << "average wait:  " <<
			 (totalWait / numberOfCustomers) << endl;

   getch();
          }


}
