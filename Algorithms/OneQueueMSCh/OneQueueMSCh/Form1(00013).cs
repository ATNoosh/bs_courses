using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Timers;
using System.Threading;

namespace OneQueueMSCh
{
    public partial class Form1 : Form
    {
        public Thread timerThread = null;
        public Form1()
        {
            InitializeComponent();
        }
        public void ShowTimer()
        {
            for (int counter = 0; counter < 20; counter++)
            {
                label1.Text = Convert.ToString(DateTime.Now.Second);
            }
        }
        public static System.Timers.Timer mainTimer = new System.Timers.Timer();

        private void startButton_Click(object sender, EventArgs e)
        {
            this.timerThread = new Thread(new ThreadStart(this.ShowTimer));
            this.timerThread.Start();
        }
    }
}