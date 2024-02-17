using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace BankSimulationWindowsApp
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
    public class Customer
    {
        public Customer(Int64 eT)
        {
            enterTime = eT;
            done = false;
            randomInt = new Random();
            durationTime = randomInt.Next()%9 + 1;

        }

        private Random randomInt;
        private Int64 enterTime;
        private Int64 durationTime;
        private bool done;

        public Int64 EnterTime
        {
            get
            {
                return enterTime;
            }
            set
            {
                enterTime = value;
            }
        }
        public Int64 DurationTime
        {
            get
            {
                return durationTime;
            }
            set
            {
                durationTime = value;
            }
        }

        public bool Done
        {
            get
            {
                return done;
            }
            set
            {
                done = value;
            }
        }

   };
    public class Teller
    {
        public Teller()
        {
            endTime = numberOfCustomers = 0;
            customerQueue = null;
        }
        public bool IsFree(Int64 thisTime)
        {
            return endTime <= thisTime;
        }

        private Int64 endTime;
        private Int64 numberOfCustomers;
        private Queue<Customer> customerQueue;

        public Int64 EndTime
        {
            get
            {
                return endTime;
            }
            set
            {
                endTime = value;
            }
        }
        public Int64 NumberOfCustomers
        {
            get
            {
                return numberOfCustomers;
            }
            set
            {
                numberOfCustomers = value;
            }
        }
    }
}