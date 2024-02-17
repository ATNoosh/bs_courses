using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace OnLineScheduling
{
    public partial class Form1 : Form
    {
        public cTellers tellers;
        public Form1()
        {
            cManager manager = new cManager();
            tellers = new cTellers(3);
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            button1.Text = Convert.ToString( DateTime.Now.Second);
        }
    }
    public class cTime
    {
        public cTime(int h,int m,int s)
        {
            t_hour = h;
            t_minute = m;
            t_second = s;
        }

        public static bool operator ==(cTime lTime, cTime rTime)
        {
            if (rTime.t_second == lTime.t_second
                && rTime.t_hour == lTime.t_hour
                && rTime.t_minute == lTime.t_minute)
                return true;
            return false;
        }
        public static bool operator >(cTime lTime, cTime rTime)
        {
            if (lTime.t_hour > rTime.t_hour)
                return true;
            if (lTime.t_minute > rTime.t_minute)
                return true;
            if (lTime.t_second > rTime.t_second)
                return true;
            return false;
        }
        public static bool operator >=(cTime lTime, cTime rTime)
        {
            if (lTime > rTime || lTime == rTime)
                return true;
            return false;
        }
        public static bool operator !=(cTime lTime, cTime rTime)
        {
            return !(lTime == rTime);
        }
        public static bool operator <(cTime lTime, cTime rTime)
        {
            if (lTime.t_hour < rTime.t_hour)
                return true;
            if (lTime.t_minute < rTime.t_minute)
                return true;
            if (lTime.t_second < rTime.t_second)
                return true;
            return false;
        }
        public static bool operator <=(cTime lTime, cTime rTime)
        {
            if (lTime < rTime || lTime == rTime)
                return true;
            return false;
        }

        private int t_hour;
        private int t_minute;
        private int t_second;

    };
    public class cTellerEndTime
    {
        public cTime endTime;
    };
    public class cTellers
    {
        public cTellers(int n)
        {
            numOfTellers = n;
            endTimes = new cTellerEndTime[n];
        }
        public cTellerEndTime[] endTimes;
        public int numOfTellers;
    };
    public class cClient
    {
        public cClient(cTime eT, cTime dT)
        {
            enterTime = eT;
            duration = dT;
        }
        public cTime enterTime;
        public cTime duration;
    };
    public class cClients 
    {
        public cClients(int n)
        {
            numOfClients = n;
        }
        public cClient[] clients;
        public int numOfClients;
    };
    public class cManager 
    {
        public cManager()
        {
            totalEndTime = new cTime(DateTime.Now.Hour
                , DateTime.Now.Minute, DateTime.Now.Second);
        }
        public int AddClient(cClient newClient)
        { 

        }
        cTime totalEndTime;
    };
}