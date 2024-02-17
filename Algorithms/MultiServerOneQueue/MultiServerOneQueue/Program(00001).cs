using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
namespace MultiServerOneQueue
{
    class Program
    {
        public static ArrayList tellersEndTime;
        public static int delayDuration;
        public static ArrayList clientEnterTime;
        public static ArrayList clientDuration;

        static void Main(string[] args)
        {
            tellersEndTime = new ArrayList();
            clientDuration = new ArrayList();
            clientEnterTime = new ArrayList();

            for (int timeCounter = 0; timeCounter < 20; timeCounter++)
            {
                if (Console.Read() == 0)
                {
                    Console.WriteLine("yyyyyyx");
                }
            }
        }

        public static void AddTeller(int newEndTime)
        {
            tellersEndTime.Add(newEndTime);
        }
        public static void AddClient(int eTime, int dTime)
        {
            clientEnterTime.Add(eTime);
            clientDuration.Add(dTime);
        }
        public static void AddClientToTeller(int clientNumber, int tellerNumber)
        {
            int x = (int)clientDuration[clientNumber];
        }
    }
}
