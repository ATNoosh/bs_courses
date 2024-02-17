namespace N_Queens
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
            this.N_QueensTB = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.Solve = new System.Windows.Forms.Button();
            this.N_SolvesTB = new System.Windows.Forms.TextBox();
            this.N_PromisTB = new System.Windows.Forms.TextBox();
            this.N_SolvesLb = new System.Windows.Forms.Label();
            this.N_PromisNodelb = new System.Windows.Forms.Label();
            this.YesRadio = new System.Windows.Forms.RadioButton();
            this.NoRadio = new System.Windows.Forms.RadioButton();
            this.radioGroup = new System.Windows.Forms.GroupBox();
            this.N_checkTB = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.DFSRadio = new System.Windows.Forms.RadioButton();
            this.BackTrackRadio = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.radioGroup.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // N_QueensTB
            // 
            this.N_QueensTB.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.N_QueensTB.Location = new System.Drawing.Point(10, 34);
            this.N_QueensTB.Name = "N_QueensTB";
            this.N_QueensTB.Size = new System.Drawing.Size(109, 20);
            this.N_QueensTB.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(96, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Number of Queens";
            // 
            // Solve
            // 
            this.Solve.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.Solve.Location = new System.Drawing.Point(10, 69);
            this.Solve.Name = "Solve";
            this.Solve.Size = new System.Drawing.Size(75, 23);
            this.Solve.TabIndex = 2;
            this.Solve.Text = "Solve";
            this.Solve.UseVisualStyleBackColor = true;
            this.Solve.Click += new System.EventHandler(this.Solve_Click);
            // 
            // N_SolvesTB
            // 
            this.N_SolvesTB.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.N_SolvesTB.Location = new System.Drawing.Point(10, 44);
            this.N_SolvesTB.Name = "N_SolvesTB";
            this.N_SolvesTB.Size = new System.Drawing.Size(109, 20);
            this.N_SolvesTB.TabIndex = 0;
            // 
            // N_PromisTB
            // 
            this.N_PromisTB.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.N_PromisTB.Location = new System.Drawing.Point(289, 44);
            this.N_PromisTB.Name = "N_PromisTB";
            this.N_PromisTB.Size = new System.Drawing.Size(109, 20);
            this.N_PromisTB.TabIndex = 0;
            // 
            // N_SolvesLb
            // 
            this.N_SolvesLb.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.N_SolvesLb.AutoSize = true;
            this.N_SolvesLb.Location = new System.Drawing.Point(7, 28);
            this.N_SolvesLb.Name = "N_SolvesLb";
            this.N_SolvesLb.Size = new System.Drawing.Size(128, 13);
            this.N_SolvesLb.TabIndex = 1;
            this.N_SolvesLb.Text = "Number of Answer Nodes";
            // 
            // N_PromisNodelb
            // 
            this.N_PromisNodelb.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.N_PromisNodelb.AutoSize = true;
            this.N_PromisNodelb.Location = new System.Drawing.Point(286, 28);
            this.N_PromisNodelb.Name = "N_PromisNodelb";
            this.N_PromisNodelb.Size = new System.Drawing.Size(117, 13);
            this.N_PromisNodelb.TabIndex = 1;
            this.N_PromisNodelb.Text = "Number of Promis node";
            // 
            // YesRadio
            // 
            this.YesRadio.AutoSize = true;
            this.YesRadio.Location = new System.Drawing.Point(8, 27);
            this.YesRadio.Name = "YesRadio";
            this.YesRadio.Size = new System.Drawing.Size(43, 17);
            this.YesRadio.TabIndex = 3;
            this.YesRadio.TabStop = true;
            this.YesRadio.Text = "Yes";
            this.YesRadio.UseVisualStyleBackColor = true;
            // 
            // NoRadio
            // 
            this.NoRadio.AutoSize = true;
            this.NoRadio.Location = new System.Drawing.Point(8, 47);
            this.NoRadio.Name = "NoRadio";
            this.NoRadio.Size = new System.Drawing.Size(39, 17);
            this.NoRadio.TabIndex = 3;
            this.NoRadio.TabStop = true;
            this.NoRadio.Text = "No";
            this.NoRadio.UseVisualStyleBackColor = true;
            // 
            // radioGroup
            // 
            this.radioGroup.Controls.Add(this.NoRadio);
            this.radioGroup.Controls.Add(this.YesRadio);
            this.radioGroup.Location = new System.Drawing.Point(289, 12);
            this.radioGroup.Name = "radioGroup";
            this.radioGroup.Size = new System.Drawing.Size(135, 82);
            this.radioGroup.TabIndex = 4;
            this.radioGroup.TabStop = false;
            this.radioGroup.Text = "Column and Row Only";
            // 
            // N_checkTB
            // 
            this.N_checkTB.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.N_checkTB.Location = new System.Drawing.Point(149, 44);
            this.N_checkTB.Name = "N_checkTB";
            this.N_checkTB.Size = new System.Drawing.Size(109, 20);
            this.N_checkTB.TabIndex = 0;
            // 
            // label2
            // 
            this.label2.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(146, 28);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(136, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Number of Checked Nodes";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.DFSRadio);
            this.groupBox2.Controls.Add(this.BackTrackRadio);
            this.groupBox2.Location = new System.Drawing.Point(175, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(103, 82);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Solve Type";
            // 
            // DFSRadio
            // 
            this.DFSRadio.AutoSize = true;
            this.DFSRadio.Location = new System.Drawing.Point(8, 47);
            this.DFSRadio.Name = "DFSRadio";
            this.DFSRadio.Size = new System.Drawing.Size(46, 17);
            this.DFSRadio.TabIndex = 3;
            this.DFSRadio.TabStop = true;
            this.DFSRadio.Text = "DFS";
            this.DFSRadio.UseVisualStyleBackColor = true;
            // 
            // BackTrackRadio
            // 
            this.BackTrackRadio.AutoSize = true;
            this.BackTrackRadio.Location = new System.Drawing.Point(8, 27);
            this.BackTrackRadio.Name = "BackTrackRadio";
            this.BackTrackRadio.Size = new System.Drawing.Size(81, 17);
            this.BackTrackRadio.TabIndex = 3;
            this.BackTrackRadio.TabStop = true;
            this.BackTrackRadio.Text = "Back Track";
            this.BackTrackRadio.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.N_PromisNodelb);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.N_SolvesLb);
            this.groupBox1.Controls.Add(this.N_PromisTB);
            this.groupBox1.Controls.Add(this.N_checkTB);
            this.groupBox1.Controls.Add(this.N_SolvesTB);
            this.groupBox1.Location = new System.Drawing.Point(26, 125);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(414, 85);
            this.groupBox1.TabIndex = 5;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Counters ";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.Solve);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.N_QueensTB);
            this.groupBox3.Location = new System.Drawing.Point(26, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(125, 106);
            this.groupBox3.TabIndex = 6;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Inputs";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(456, 231);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.radioGroup);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Queens";
            this.radioGroup.ResumeLayout(false);
            this.radioGroup.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        public System.Windows.Forms.TextBox N_QueensTB;
        public System.Windows.Forms.Label label1;
        public System.Windows.Forms.Button Solve;
        public System.Windows.Forms.TextBox N_SolvesTB;
        public System.Windows.Forms.TextBox N_PromisTB;
        public System.Windows.Forms.Label N_SolvesLb;
        public System.Windows.Forms.Label N_PromisNodelb;
        private System.Windows.Forms.RadioButton YesRadio;
        private System.Windows.Forms.RadioButton NoRadio;
        private System.Windows.Forms.GroupBox radioGroup;
        public System.Windows.Forms.TextBox N_checkTB;
        public System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton DFSRadio;
        private System.Windows.Forms.RadioButton BackTrackRadio;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox3;


    }
}

