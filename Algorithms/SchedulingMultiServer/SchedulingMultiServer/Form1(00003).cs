using System;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SchedulingMultiServer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
    }
    public class Work 
    {
        public int enterTime
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
        public int duration
        {
            get
            {
                return duration;
            }
            set
            {
                duration = value;
            }
        }
    };
    public class WorkQueue
    {
        private ArrayList workList;
        private int endTime;

        public WorkQueue() 
        {
            workList = new ArrayList();
            endTime = 0;
        }

        public bool AddWork(Work newWork) 
        {
            workList.Add(newWork);

        }
        public bool RemoveWork(Work removeWork)
        {
            workList.Remove(removeWork);
        }
    };
    public class WorkQueues
    {
        private ArrayList workQueueList;

        public WorkQueues()
        {
            workQueueList = new ArrayList();
        }

        public bool AddQueue(WorkQueue newQueue)
        {
            workQueueList.Add(newQueue);
        }
        public bool RemoveQueue(WorkQueue removeQueue) 
        {
            workQueueList.Remove(removeQueue);
        }
    };
}