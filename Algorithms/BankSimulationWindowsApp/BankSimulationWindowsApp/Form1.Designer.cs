namespace BankSimulationWindowsApp
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.simulateButton = new System.Windows.Forms.Button();
            this.tellerNumberTB = new System.Windows.Forms.TextBox();
            this.tellerNumberLB = new System.Windows.Forms.Label();
            this.averageTB = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.remindedCustomersCessationTB = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.answeredCustomersCessationTB = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.Cessation = new System.Windows.Forms.GroupBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.totWaitAllTB = new System.Windows.Forms.TextBox();
            this.totalWaitTB = new System.Windows.Forms.TextBox();
            this.totAverageTB = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.cusNumberTB = new System.Windows.Forms.TextBox();
            this.totWaitNotCessTB = new System.Windows.Forms.TextBox();
            this.averageNotCessTB = new System.Windows.Forms.TextBox();
            this.numOfTimesTB = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.label14 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.ansCus2TB = new System.Windows.Forms.TextBox();
            this.totWait2TB = new System.Windows.Forms.TextBox();
            this.totalWait2TB = new System.Windows.Forms.TextBox();
            this.totAverage2TB = new System.Windows.Forms.TextBox();
            this.averageWait2TB = new System.Windows.Forms.TextBox();
            this.label19 = new System.Windows.Forms.Label();
            this.rem2TB = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.cusNumNotCess2TB = new System.Windows.Forms.TextBox();
            this.totalWaitNotCess2TB = new System.Windows.Forms.TextBox();
            this.averageNotCess2TB = new System.Windows.Forms.TextBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.Cessation.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.SuspendLayout();
            // 
            // simulateButton
            // 
            this.simulateButton.Location = new System.Drawing.Point(422, 356);
            this.simulateButton.Name = "simulateButton";
            this.simulateButton.Size = new System.Drawing.Size(214, 39);
            this.simulateButton.TabIndex = 2;
            this.simulateButton.Text = "Simulate";
            this.simulateButton.UseVisualStyleBackColor = true;
            this.simulateButton.Click += new System.EventHandler(this.simulateButton_Click);
            // 
            // tellerNumberTB
            // 
            this.tellerNumberTB.Location = new System.Drawing.Point(25, 375);
            this.tellerNumberTB.Name = "tellerNumberTB";
            this.tellerNumberTB.Size = new System.Drawing.Size(156, 20);
            this.tellerNumberTB.TabIndex = 0;
            // 
            // tellerNumberLB
            // 
            this.tellerNumberLB.AutoSize = true;
            this.tellerNumberLB.Location = new System.Drawing.Point(22, 356);
            this.tellerNumberLB.Name = "tellerNumberLB";
            this.tellerNumberLB.Size = new System.Drawing.Size(90, 13);
            this.tellerNumberLB.TabIndex = 6;
            this.tellerNumberLB.Text = "Number of Tellers";
            // 
            // averageTB
            // 
            this.averageTB.Location = new System.Drawing.Point(20, 82);
            this.averageTB.Name = "averageTB";
            this.averageTB.ReadOnly = true;
            this.averageTB.Size = new System.Drawing.Size(100, 20);
            this.averageTB.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(17, 66);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(72, 13);
            this.label1.TabIndex = 8;
            this.label1.Text = "Average Wait";
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(25, 417);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(639, 23);
            this.progressBar1.TabIndex = 9;
            // 
            // remindedCustomersCessationTB
            // 
            this.remindedCustomersCessationTB.Location = new System.Drawing.Point(20, 215);
            this.remindedCustomersCessationTB.Name = "remindedCustomersCessationTB";
            this.remindedCustomersCessationTB.ReadOnly = true;
            this.remindedCustomersCessationTB.Size = new System.Drawing.Size(100, 20);
            this.remindedCustomersCessationTB.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(17, 199);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(107, 13);
            this.label2.TabIndex = 12;
            this.label2.Text = "Reminded Customers";
            // 
            // answeredCustomersCessationTB
            // 
            this.answeredCustomersCessationTB.Location = new System.Drawing.Point(20, 254);
            this.answeredCustomersCessationTB.Name = "answeredCustomersCessationTB";
            this.answeredCustomersCessationTB.ReadOnly = true;
            this.answeredCustomersCessationTB.Size = new System.Drawing.Size(100, 20);
            this.answeredCustomersCessationTB.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(17, 238);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(106, 13);
            this.label3.TabIndex = 12;
            this.label3.Text = "Answered Customers";
            // 
            // Cessation
            // 
            this.Cessation.Controls.Add(this.label6);
            this.Cessation.Controls.Add(this.label4);
            this.Cessation.Controls.Add(this.label5);
            this.Cessation.Controls.Add(this.label1);
            this.Cessation.Controls.Add(this.label3);
            this.Cessation.Controls.Add(this.answeredCustomersCessationTB);
            this.Cessation.Controls.Add(this.totWaitAllTB);
            this.Cessation.Controls.Add(this.totalWaitTB);
            this.Cessation.Controls.Add(this.totAverageTB);
            this.Cessation.Controls.Add(this.averageTB);
            this.Cessation.Controls.Add(this.label2);
            this.Cessation.Controls.Add(this.remindedCustomersCessationTB);
            this.Cessation.Location = new System.Drawing.Point(10, 24);
            this.Cessation.Name = "Cessation";
            this.Cessation.Size = new System.Drawing.Size(146, 292);
            this.Cessation.TabIndex = 13;
            this.Cessation.TabStop = false;
            this.Cessation.Text = "Cessation";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(17, 112);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(85, 13);
            this.label6.TabIndex = 8;
            this.label6.Text = "Total Wait for All";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(17, 27);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(56, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Total Wait";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(17, 151);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(99, 13);
            this.label5.TabIndex = 8;
            this.label5.Text = "Total Average Wait";
            // 
            // totWaitAllTB
            // 
            this.totWaitAllTB.Location = new System.Drawing.Point(20, 128);
            this.totWaitAllTB.Name = "totWaitAllTB";
            this.totWaitAllTB.ReadOnly = true;
            this.totWaitAllTB.Size = new System.Drawing.Size(100, 20);
            this.totWaitAllTB.TabIndex = 2;
            // 
            // totalWaitTB
            // 
            this.totalWaitTB.Location = new System.Drawing.Point(20, 43);
            this.totalWaitTB.Name = "totalWaitTB";
            this.totalWaitTB.ReadOnly = true;
            this.totalWaitTB.Size = new System.Drawing.Size(100, 20);
            this.totalWaitTB.TabIndex = 0;
            // 
            // totAverageTB
            // 
            this.totAverageTB.Location = new System.Drawing.Point(20, 167);
            this.totAverageTB.Name = "totAverageTB";
            this.totAverageTB.ReadOnly = true;
            this.totAverageTB.Size = new System.Drawing.Size(100, 20);
            this.totAverageTB.TabIndex = 3;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label8);
            this.groupBox3.Controls.Add(this.label10);
            this.groupBox3.Controls.Add(this.label11);
            this.groupBox3.Controls.Add(this.cusNumberTB);
            this.groupBox3.Controls.Add(this.totWaitNotCessTB);
            this.groupBox3.Controls.Add(this.averageNotCessTB);
            this.groupBox3.Location = new System.Drawing.Point(162, 24);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(141, 164);
            this.groupBox3.TabIndex = 13;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Not Cessation";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(17, 27);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(56, 13);
            this.label8.TabIndex = 8;
            this.label8.Text = "Total Wait";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(17, 66);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(72, 13);
            this.label10.TabIndex = 8;
            this.label10.Text = "Average Wait";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(17, 112);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(111, 13);
            this.label11.TabIndex = 12;
            this.label11.Text = "Number of  Customers";
            // 
            // cusNumberTB
            // 
            this.cusNumberTB.Location = new System.Drawing.Point(20, 128);
            this.cusNumberTB.Name = "cusNumberTB";
            this.cusNumberTB.ReadOnly = true;
            this.cusNumberTB.Size = new System.Drawing.Size(100, 20);
            this.cusNumberTB.TabIndex = 2;
            // 
            // totWaitNotCessTB
            // 
            this.totWaitNotCessTB.Location = new System.Drawing.Point(20, 43);
            this.totWaitNotCessTB.Name = "totWaitNotCessTB";
            this.totWaitNotCessTB.ReadOnly = true;
            this.totWaitNotCessTB.Size = new System.Drawing.Size(100, 20);
            this.totWaitNotCessTB.TabIndex = 0;
            // 
            // averageNotCessTB
            // 
            this.averageNotCessTB.Location = new System.Drawing.Point(20, 82);
            this.averageNotCessTB.Name = "averageNotCessTB";
            this.averageNotCessTB.ReadOnly = true;
            this.averageNotCessTB.Size = new System.Drawing.Size(100, 20);
            this.averageNotCessTB.TabIndex = 1;
            // 
            // numOfTimesTB
            // 
            this.numOfTimesTB.Location = new System.Drawing.Point(187, 375);
            this.numOfTimesTB.Name = "numOfTimesTB";
            this.numOfTimesTB.Size = new System.Drawing.Size(147, 20);
            this.numOfTimesTB.TabIndex = 1;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(184, 356);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(109, 13);
            this.label7.TabIndex = 6;
            this.label7.Text = "Number of Unit Times";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.label14);
            this.groupBox4.Controls.Add(this.label15);
            this.groupBox4.Controls.Add(this.label16);
            this.groupBox4.Controls.Add(this.label17);
            this.groupBox4.Controls.Add(this.label18);
            this.groupBox4.Controls.Add(this.ansCus2TB);
            this.groupBox4.Controls.Add(this.totWait2TB);
            this.groupBox4.Controls.Add(this.totalWait2TB);
            this.groupBox4.Controls.Add(this.totAverage2TB);
            this.groupBox4.Controls.Add(this.averageWait2TB);
            this.groupBox4.Controls.Add(this.label19);
            this.groupBox4.Controls.Add(this.rem2TB);
            this.groupBox4.Location = new System.Drawing.Point(6, 24);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(135, 292);
            this.groupBox4.TabIndex = 13;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Cessation";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(16, 112);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(85, 13);
            this.label14.TabIndex = 8;
            this.label14.Text = "Total Wait for All";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(16, 27);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(56, 13);
            this.label15.TabIndex = 8;
            this.label15.Text = "Total Wait";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(16, 151);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(99, 13);
            this.label16.TabIndex = 8;
            this.label16.Text = "Total Average Wait";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(16, 66);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(72, 13);
            this.label17.TabIndex = 8;
            this.label17.Text = "Average Wait";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(16, 238);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(106, 13);
            this.label18.TabIndex = 12;
            this.label18.Text = "Answered Customers";
            // 
            // ansCus2TB
            // 
            this.ansCus2TB.Location = new System.Drawing.Point(19, 254);
            this.ansCus2TB.Name = "ansCus2TB";
            this.ansCus2TB.ReadOnly = true;
            this.ansCus2TB.Size = new System.Drawing.Size(100, 20);
            this.ansCus2TB.TabIndex = 5;
            // 
            // totWait2TB
            // 
            this.totWait2TB.Location = new System.Drawing.Point(19, 128);
            this.totWait2TB.Name = "totWait2TB";
            this.totWait2TB.ReadOnly = true;
            this.totWait2TB.Size = new System.Drawing.Size(100, 20);
            this.totWait2TB.TabIndex = 2;
            // 
            // totalWait2TB
            // 
            this.totalWait2TB.Location = new System.Drawing.Point(19, 43);
            this.totalWait2TB.Name = "totalWait2TB";
            this.totalWait2TB.ReadOnly = true;
            this.totalWait2TB.Size = new System.Drawing.Size(100, 20);
            this.totalWait2TB.TabIndex = 0;
            // 
            // totAverage2TB
            // 
            this.totAverage2TB.Location = new System.Drawing.Point(19, 167);
            this.totAverage2TB.Name = "totAverage2TB";
            this.totAverage2TB.ReadOnly = true;
            this.totAverage2TB.Size = new System.Drawing.Size(100, 20);
            this.totAverage2TB.TabIndex = 3;
            // 
            // averageWait2TB
            // 
            this.averageWait2TB.Location = new System.Drawing.Point(19, 82);
            this.averageWait2TB.Name = "averageWait2TB";
            this.averageWait2TB.ReadOnly = true;
            this.averageWait2TB.Size = new System.Drawing.Size(100, 20);
            this.averageWait2TB.TabIndex = 1;
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(16, 199);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(107, 13);
            this.label19.TabIndex = 12;
            this.label19.Text = "Reminded Customers";
            // 
            // rem2TB
            // 
            this.rem2TB.Location = new System.Drawing.Point(19, 215);
            this.rem2TB.Name = "rem2TB";
            this.rem2TB.ReadOnly = true;
            this.rem2TB.Size = new System.Drawing.Size(100, 20);
            this.rem2TB.TabIndex = 4;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.groupBox3);
            this.groupBox1.Controls.Add(this.Cessation);
            this.groupBox1.Location = new System.Drawing.Point(25, 21);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(309, 322);
            this.groupBox1.TabIndex = 14;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Detention Time Based";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label12);
            this.groupBox2.Controls.Add(this.label13);
            this.groupBox2.Controls.Add(this.cusNumNotCess2TB);
            this.groupBox2.Controls.Add(this.totalWaitNotCess2TB);
            this.groupBox2.Controls.Add(this.averageNotCess2TB);
            this.groupBox2.Location = new System.Drawing.Point(165, 24);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(135, 164);
            this.groupBox2.TabIndex = 13;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Not Cessation";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(18, 27);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(56, 13);
            this.label9.TabIndex = 8;
            this.label9.Text = "Total Wait";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(18, 66);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(72, 13);
            this.label12.TabIndex = 8;
            this.label12.Text = "Average Wait";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(18, 112);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(111, 13);
            this.label13.TabIndex = 12;
            this.label13.Text = "Number of  Customers";
            // 
            // cusNumNotCess2TB
            // 
            this.cusNumNotCess2TB.Location = new System.Drawing.Point(21, 128);
            this.cusNumNotCess2TB.Name = "cusNumNotCess2TB";
            this.cusNumNotCess2TB.ReadOnly = true;
            this.cusNumNotCess2TB.Size = new System.Drawing.Size(100, 20);
            this.cusNumNotCess2TB.TabIndex = 2;
            // 
            // totalWaitNotCess2TB
            // 
            this.totalWaitNotCess2TB.Location = new System.Drawing.Point(21, 43);
            this.totalWaitNotCess2TB.Name = "totalWaitNotCess2TB";
            this.totalWaitNotCess2TB.ReadOnly = true;
            this.totalWaitNotCess2TB.Size = new System.Drawing.Size(100, 20);
            this.totalWaitNotCess2TB.TabIndex = 0;
            // 
            // averageNotCess2TB
            // 
            this.averageNotCess2TB.Location = new System.Drawing.Point(21, 82);
            this.averageNotCess2TB.Name = "averageNotCess2TB";
            this.averageNotCess2TB.ReadOnly = true;
            this.averageNotCess2TB.Size = new System.Drawing.Size(100, 20);
            this.averageNotCess2TB.TabIndex = 1;
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.groupBox2);
            this.groupBox5.Controls.Add(this.groupBox4);
            this.groupBox5.Location = new System.Drawing.Point(350, 21);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(314, 322);
            this.groupBox5.TabIndex = 15;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Enter Time Based";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(693, 469);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.tellerNumberLB);
            this.Controls.Add(this.numOfTimesTB);
            this.Controls.Add(this.tellerNumberTB);
            this.Controls.Add(this.simulateButton);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Text = "Bank Simulation";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.Cessation.ResumeLayout(false);
            this.Cessation.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button simulateButton;
        private System.Windows.Forms.TextBox tellerNumberTB;
        private System.Windows.Forms.Label tellerNumberLB;
        private System.Windows.Forms.TextBox averageTB;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.TextBox remindedCustomersCessationTB;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox answeredCustomersCessationTB;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox Cessation;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox totalWaitTB;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox totAverageTB;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox totWaitAllTB;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox cusNumberTB;
        private System.Windows.Forms.TextBox totWaitNotCessTB;
        private System.Windows.Forms.TextBox averageNotCessTB;
        private System.Windows.Forms.TextBox numOfTimesTB;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.TextBox ansCus2TB;
        private System.Windows.Forms.TextBox totWait2TB;
        private System.Windows.Forms.TextBox totalWait2TB;
        private System.Windows.Forms.TextBox totAverage2TB;
        private System.Windows.Forms.TextBox averageWait2TB;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.TextBox rem2TB;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox cusNumNotCess2TB;
        private System.Windows.Forms.TextBox totalWaitNotCess2TB;
        private System.Windows.Forms.TextBox averageNotCess2TB;
        private System.Windows.Forms.GroupBox groupBox5;
    }
}

