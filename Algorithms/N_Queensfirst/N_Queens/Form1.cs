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
            
        }
        
        private void Solve_Click(object sender, EventArgs e)
        {
            try
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
            }
        }

    }
    class ChessBoard
    {
        public int boardSize;
        public bool[,] board;
        public int[] column;
        public int solveCounter;
        public int promisCounter;
        public int checkedNodes;
        public bool RowColOnlyFlag;

        public ChessBoard(int n)
        {
            boardSize = n;
            RowColOnlyFlag = false;
            promisCounter = 0;
            solveCounter = 0;
            checkedNodes = 0;
            board = new bool[boardSize + 1, boardSize + 1];
            column = new int[boardSize + 1];
        }
        public void Queens1(int i)
        {
            checkedNodes++;
            if (Promising(i))
            {
                promisCounter++;
                if (i == boardSize)
                    PrintColumns();
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
            solveCounter++;
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
    };
}