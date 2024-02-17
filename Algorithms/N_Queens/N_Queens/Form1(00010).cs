using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace N_Queens
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            /*tv.Nodes.Add("Ali");
            tv.Nodes.Add("Reza");
            tv.Nodes.Add("Abbas");
            tv.Nodes.Add("Hossein");
            tv.Nodes.Insert(2, "Hassan");
            tv.Nodes[0].Nodes.Add("Child");*/
            tempTn.Text = "(0,0)";
            tv.Nodes.Add(tempTn);
            boardSize = 8;
            RowColOnlyFlag = false;
            promisCounter = 0;
            solveCounter = 0;
            checkedNodes = 0;
            board = new bool[boardSize + 1, boardSize + 1];
            column = new int[boardSize + 1];
            buttonsMatrix = new Button[8,8];
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    buttonsMatrix[i, j] = new Button();
                    BoardGB.Controls.Add(buttonsMatrix[i, j]);
                    buttonsMatrix[i, j].Location = new Point(j * 40 +20,20+ i * 40);
                    buttonsMatrix[i, j].Width = 35;
                    buttonsMatrix[i, j].Height = 35;
                }
            }
        }

        private void Solve_Click(object sender, EventArgs e)
        {
            /*try
            {
                int n = Convert.ToInt16( N_QueensTB.Text);
                ChessBoard cb;
                cb = new ChessBoard(n);

                if (YesRadio.Checked)
                    cb.RowColOnlyFlag = true;
                else 
                    cb.RowColOnlyFlag = false;

                if (BackTrackRadio.Checked)
                    cb.Queens1(0);
                else
                    cb.QueensAllNode(0);
                N_SolvesTB.Text = Convert.ToString(cb.solveCounter);
                N_PromisTB.Text = Convert.ToString(cb.promisCounter);
                N_checkTB.Text = Convert.ToString(cb.checkedNodes);
            }
            catch(Exception exp)
            {
            }*/
            Queens1(0);
        }
        
        public int boardSize;
        public bool[,] board;
        public int[] column;
        public int solveCounter;
        public int currentShowNumber = 1;
        public int promisCounter;
        public int checkedNodes;
        public bool RowColOnlyFlag;
        public int column0Changed = 1;
        Button[,] buttonsMatrix;
        private TreeNode tempTn = new TreeNode();

        public void Queens1(int i)
        {
            if (column[1] != -1)
            {
                if (tempTn.Text[1] != Convert.ToChar(column[i]))
                {
                    tempTn.Nodes.Add(String.Format("({0},{1})", column[i], i));
                    tempTn = tempTn.Nodes[0];
                }
            }
            checkedNodes++;
            if (Promising(i))
            {
                promisCounter++;
                if (i == boardSize)
                {
                    PrintColumns();
                }
                else
                {
                    for (int j = 1; j <= boardSize; j++)
                    {
                        column[i + 1] = j;
                        Queens1(i + 1);
                    }
                }
            }
        }
        public void QueensAllNode(int i)
        {
            promisCounter++;
            checkedNodes++;
            if (i == boardSize)
            {
                if(AllNodePromising())
                    PrintColumns();
                return;
            }

            else
            {
                for (int j = 1; j <= boardSize; j++)
                {
                    column[i + 1] = j;
                    QueensAllNode(i + 1);
                }
            }
        }

        private bool AllNodePromising()
        {
            for (int i = 1; i <= boardSize; i++)
            {
                for (int j = i + 1; j <= boardSize; j++)
                {
                    if (!RowColOnlyFlag)
                    {
                        if (Math.Abs(j - i) == Math.Abs(column[j] - column[i]))
                            return false;
                    }
                    if (column[i] == column[j])
                        return false;
                }
            }
            return true;
        }
        private void PrintColumns()
        {
            /*char[] tempChar = new char[9];
            for (int i = 1; i < 9; i++)
            {
                tempChar[i] = Convert.ToChar(column[i]);
            }
            String temp = new String(tempChar,1,8);
            //string temp = new string(tempChar, 1, 8);*/
            //tv.Nodes.Add(String.Format("Solve({0}) : {1}{2}{3}{4}{5}{6}{7}{8}"
              //  ,solveCounter,column[1],column[2],column[3],column[4],column[5],column[6],column[7],column[8]));
            solveCounter++;
            if(solveCounter == currentShowNumber)
            for (int i = 0; i < 8; i++)
            {
                buttonsMatrix[i, column[i+1]-1].BackColor = Color.Black;
            }    
        }
        private bool Promising(int i)
        {
            int k = 1;
            bool retValue = true;
            while (k < i && retValue)
            {
                if (RowColOnlyFlag)
                {
                    if (column[i] == column[k] )
                        retValue = false;
                }
                else
                {
                    if (column[i] == column[k] || Math.Abs(column[i] - column[k]) == i - k)
                        retValue = false;
                }
                k++;
            }
            return retValue;
        }

        private void NextButton_Click(object sender, EventArgs e)
        {
            InitialButtons();
            solveCounter = 0;
            currentShowNumber = (currentShowNumber + 1) % 92;
            Queens1(0);
        }

        private void BackButton_Click(object sender, EventArgs e)
        {
            InitialButtons();
            solveCounter = 0;
            currentShowNumber = (currentShowNumber - 1) % 92;
            Queens1(0);
        }
        private void InitialButtons()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    buttonsMatrix[i, j].BackColor = Color.WhiteSmoke;
                }
                column[i] = -1;
            }
        }
    }
}