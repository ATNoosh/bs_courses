using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Collections;

namespace BankSimulationWindowsApp
{
    public partial class Form1 : Form
    {
        public List<Customer> customers;
        public List<Customer> customers2;
        public List<Teller> tellers;
        public List<Teller> tellers2;

        public Int64 numberOfTellers;
        public Int64 numberOfCustomers;
        public Int64 remindedCustomers;
        public Int64 remindedCustomers2;
        public Int64 numberOfTimes ;
        public Int64 totalWait ;
        public Int64 totalWait2;
        public Random randInt;

        public Form1()
        {
            InitializeComponent();
        }
        public double Poisson(double x,double lambda)
        {
            return Math.Pow(Math.E, -lambda) * Math.Pow(lambda, x) / Factorial(x);
        }
        private double Factorial(double x)
        {
            double result = 1;
            if (x == 0) return 1;
            for (Int64 i = 1; i < x; i++)
            {
                result *= i;
            }
            return result;
        }
        public Int64 SelectCustomer(Int64 thisTime)
        {
            int maxDetainIndex = 0;
            for (int i = 0; i < customers.Count; i++)
            {
                if ((!customers[i].Done) && (double)((thisTime - customers[i].EnterTime) / customers[i].DurationTime)
                    > (double)((thisTime - customers[maxDetainIndex].EnterTime) / customers[maxDetainIndex].DurationTime))
                    maxDetainIndex = i;
            }
            return maxDetainIndex;
        }
        public Int64 SelectCustomer2(Int64 thisTime)
        {
            int minDurationIndex = 0;
            for (int i = 0; i < customers2.Count; i++)
            {
                if (customers2[minDurationIndex].DurationTime > customers2[i].DurationTime)
                    minDurationIndex = i;
            }
                return minDurationIndex;
        }
        public void ShowCessation()
        {
            progressBar1.Value = 0;
            remindedCustomers = customers.Count;
            remindedCustomers2 = customers2.Count;
            remindedCustomersCessationTB.Text = Convert.ToString(remindedCustomers);
            rem2TB.Text = Convert.ToString(remindedCustomers2);
            answeredCustomersCessationTB.Text = Convert.ToString(numberOfCustomers - remindedCustomers);
            ansCus2TB.Text = Convert.ToString(numberOfCustomers - remindedCustomers2);
            averageTB.Text = Convert.ToString((double)(totalWait / (double)(numberOfCustomers - remindedCustomers)));
            averageWait2TB.Text = Convert.ToString((double)totalWait2/(double)(numberOfCustomers - remindedCustomers2));
            totalWaitTB.Text = Convert.ToString(totalWait);
            totalWait2TB.Text = Convert.ToString(totalWait2);

            Int64 tempTotalWait = totalWait;
            Int64 tempTot2 = totalWait2;
            for (int i = 0; i < remindedCustomers; i++)
            {
                if (!customers[i].Done)
                    tempTotalWait += numberOfTimes - customers[i].EnterTime;
            }
            for (int i = 0; i < remindedCustomers2; i++)
            {
                if (!customers2[i].Done)
                    tempTot2 += numberOfTimes - customers2[i].EnterTime;
            }

            totWaitAllTB.Text = Convert.ToString(tempTotalWait);
            totWait2TB.Text = Convert.ToString(tempTot2);
            totAverageTB.Text = Convert.ToString((double)tempTotalWait / (double)numberOfCustomers);
            totAverage2TB.Text = Convert.ToString((double)tempTot2/(double)numberOfCustomers);
        }
        public void AddAndAnswerCustomers()
        {
            Int64 time;
            numberOfCustomers = 0;
            progressBar1.Value = 0;
            for (time = 0; time < numberOfTimes; time++)
            {
                if (time % ((double)(numberOfTimes / progressBar1.Maximum)) == 0)
                    progressBar1.Increment(1);
                double temp = (double)randInt.Next() % 100;
                if (Poisson(temp, 10) > 0.5)
                {
                    for (Int64 j = 0; j < temp; j++)
                    {
                        Customer tempCus = new Customer(time);
                        Customer tempCus2 = new Customer(time);
                        tempCus2.DurationTime = tempCus.DurationTime;
                        customers.Add(tempCus);
                        customers2.Add(tempCus2);
                        numberOfCustomers++;
                    }
                }
                for (int i = 0; i < tellers.Count; i++)
                {
                    if (tellers[i].IsFree(time) && customers.Count != 0)
                    {
                        int selectCustomer = (int)SelectCustomer(time);
                        customers[selectCustomer].Done = true;
                        tellers[i].EndTime += customers[selectCustomer].DurationTime;
                        tellers[i].NumberOfCustomers++;
                        totalWait += customers[selectCustomer].DurationTime
                            + time - customers[selectCustomer].EnterTime;
                        customers.RemoveAt(selectCustomer);
                    }
                }
                for (int i = 0; i < tellers2.Count; i++)
                {
                    if (tellers2[i].IsFree(time) && customers2.Count != 0)
                    {
                        int selectCustomer = (int)SelectCustomer2(time);
                        customers2[selectCustomer].Done = true;
                        tellers2[i].EndTime += customers2[selectCustomer].DurationTime;
                        tellers2[i].NumberOfCustomers++;
                        totalWait2 += customers2[selectCustomer].DurationTime
                            + time - customers2[selectCustomer].EnterTime;
                        customers2.RemoveAt(selectCustomer);
                    }
                }
            }
        }
        public void AnswerRemainedCustomers()
        {
            for (Int64 exteraTime = numberOfTimes; ; exteraTime++)
            {
                if (customers.Count == 0)
                    break;
                if (exteraTime % ((double)(remindedCustomers / progressBar1.Maximum)) == 0)
                    progressBar1.Increment(1);
                for (int i = 0; i < tellers.Count; i++)
                {
                    if (customers.Count == 0)
                        break;
                    if (tellers[i].IsFree(exteraTime))
                    {
                        int selectCustomer = (int)SelectCustomer(exteraTime);
                        customers[selectCustomer].Done = true;
                        tellers[i].EndTime += customers[selectCustomer].DurationTime;
                        tellers[i].NumberOfCustomers++;
                        totalWait += customers[selectCustomer].DurationTime
                            + exteraTime - customers[selectCustomer].EnterTime;
                        customers.RemoveAt(selectCustomer);
                    }
                }
            }
            for (Int64 exteraTime = numberOfTimes; ; exteraTime++)
            {
                if (customers2.Count == 0)
                    break;
                if (exteraTime % ((double)(remindedCustomers / progressBar1.Maximum)) == 0)
                    progressBar1.Increment(1);
                for (int i = 0; i < tellers.Count; i++)
                {
                    if (customers2.Count == 0)
                        break;
                    if (tellers2[i].IsFree(exteraTime))
                    {
                        int selectCustomer = (int)SelectCustomer2(exteraTime);
                        customers2[selectCustomer].Done = true;
                        tellers2[i].EndTime += customers2[selectCustomer].DurationTime;
                        tellers2[i].NumberOfCustomers++;
                        totalWait2 += customers2[selectCustomer].DurationTime
                            + exteraTime - customers2[selectCustomer].EnterTime;
                        customers2.RemoveAt(selectCustomer);
                    }
                }
            }
        }
        public void ShowNotCessation()
        {
            totWaitNotCessTB.Text = Convert.ToString(totalWait);
            averageNotCessTB.Text = Convert.ToString((double)totalWait/(double)numberOfCustomers);
            cusNumberTB.Text = Convert.ToString(numberOfCustomers);
            totalWaitNotCess2TB.Text = Convert.ToString(totalWait2);
            averageNotCess2TB.Text = Convert.ToString((double)(totalWait2)/(double)(numberOfCustomers));
            cusNumNotCess2TB.Text = Convert.ToString(numberOfCustomers);
        }
        private void simulateButton_Click(object sender, EventArgs e)
        {
            //numberOfTimes = 600;
            totalWait = 0;

            randInt = new Random();
            tellers = new List<Teller>();
            tellers2 = new List<Teller>();
            customers = new List<Customer>();
            customers2 = new List<Customer>();

            try
            {
                numberOfTellers = Convert.ToInt16(tellerNumberTB.Text);
                numberOfTimes = Convert.ToInt16(numOfTimesTB.Text);
            }
            catch(Exception exp)
            {
                return;
            }


            for (Int64 i = 0; i < numberOfTellers; i++)
            {
                tellers.Add(new Teller());
                tellers2.Add(new Teller());
            }

            this.Enabled = false;
            AddAndAnswerCustomers();
            progressBar1.Value = 0;
            ShowCessation();
            AnswerRemainedCustomers();
            ShowNotCessation();
            this.Enabled = true;
                //averageTB.Text = Convert.ToString((double)totalWait/(double)numberOfCustomers);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

    }
}