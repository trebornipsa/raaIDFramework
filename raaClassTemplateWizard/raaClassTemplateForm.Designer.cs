namespace raaClassTemplateWizard
{
    partial class raaClassTemplateForm
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
            this.input_label = new System.Windows.Forms.Label();
            this.cpp_label = new System.Windows.Forms.Label();
            this.h_label = new System.Windows.Forms.Label();
            this.singleton_check = new System.Windows.Forms.CheckBox();
            this.q_check = new System.Windows.Forms.CheckBox();
            this.cancel_button = new System.Windows.Forms.Button();
            this.accept_button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // input_label
            // 
            this.input_label.AutoSize = true;
            this.input_label.Location = new System.Drawing.Point(13, 13);
            this.input_label.Name = "input_label";
            this.input_label.Size = new System.Drawing.Size(35, 13);
            this.input_label.TabIndex = 0;
            this.input_label.Text = "label1";
            // 
            // cpp_label
            // 
            this.cpp_label.AutoSize = true;
            this.cpp_label.Location = new System.Drawing.Point(131, 12);
            this.cpp_label.Name = "cpp_label";
            this.cpp_label.Size = new System.Drawing.Size(35, 13);
            this.cpp_label.TabIndex = 1;
            this.cpp_label.Text = "label1";
            // 
            // h_label
            // 
            this.h_label.AutoSize = true;
            this.h_label.Location = new System.Drawing.Point(131, 25);
            this.h_label.Name = "h_label";
            this.h_label.Size = new System.Drawing.Size(35, 13);
            this.h_label.TabIndex = 2;
            this.h_label.Text = "label1";
            // 
            // singleton_check
            // 
            this.singleton_check.AutoSize = true;
            this.singleton_check.Location = new System.Drawing.Point(13, 30);
            this.singleton_check.Name = "singleton_check";
            this.singleton_check.Size = new System.Drawing.Size(70, 17);
            this.singleton_check.TabIndex = 3;
            this.singleton_check.Text = "Singleton";
            this.singleton_check.UseVisualStyleBackColor = true;
            this.singleton_check.CheckedChanged += new System.EventHandler(this.singleton_check_CheckedChanged);
            // 
            // q_check
            // 
            this.q_check.AutoSize = true;
            this.q_check.Location = new System.Drawing.Point(13, 54);
            this.q_check.Name = "q_check";
            this.q_check.Size = new System.Drawing.Size(65, 17);
            this.q_check.TabIndex = 4;
            this.q_check.Text = "QObject";
            this.q_check.UseVisualStyleBackColor = true;
            this.q_check.CheckedChanged += new System.EventHandler(this.q_check_CheckedChanged);
            // 
            // cancel_button
            // 
            this.cancel_button.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cancel_button.Location = new System.Drawing.Point(13, 88);
            this.cancel_button.Name = "cancel_button";
            this.cancel_button.Size = new System.Drawing.Size(75, 23);
            this.cancel_button.TabIndex = 5;
            this.cancel_button.Text = "Cancel";
            this.cancel_button.UseVisualStyleBackColor = true;
            // 
            // accept_button
            // 
            this.accept_button.Location = new System.Drawing.Point(205, 87);
            this.accept_button.Name = "accept_button";
            this.accept_button.Size = new System.Drawing.Size(75, 23);
            this.accept_button.TabIndex = 6;
            this.accept_button.Text = "Accept";
            this.accept_button.UseVisualStyleBackColor = true;
            this.accept_button.Click += new System.EventHandler(this.accept_button_Click);
            // 
            // raaClassTemplateForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.CancelButton = this.cancel_button;
            this.ClientSize = new System.Drawing.Size(292, 129);
            this.Controls.Add(this.accept_button);
            this.Controls.Add(this.cancel_button);
            this.Controls.Add(this.q_check);
            this.Controls.Add(this.singleton_check);
            this.Controls.Add(this.h_label);
            this.Controls.Add(this.cpp_label);
            this.Controls.Add(this.input_label);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "raaClassTemplateForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "raaClassTemplateForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label input_label;
        private System.Windows.Forms.Label cpp_label;
        private System.Windows.Forms.Label h_label;
        private System.Windows.Forms.CheckBox singleton_check;
        private System.Windows.Forms.CheckBox q_check;
        private System.Windows.Forms.Button cancel_button;
        private System.Windows.Forms.Button accept_button;
    }
}