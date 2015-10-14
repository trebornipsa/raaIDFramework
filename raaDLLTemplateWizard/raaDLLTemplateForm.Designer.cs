namespace raaDLLTemplateWizard
{
    partial class raaDLLTemplateForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.form_singleton_checkbox = new System.Windows.Forms.CheckBox();
            this.cancel_button = new System.Windows.Forms.Button();
            this.accept_button = new System.Windows.Forms.Button();
            this.form_group_box = new System.Windows.Forms.GroupBox();
            this.form_plugin_check = new System.Windows.Forms.CheckBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.osgFX_check = new System.Windows.Forms.CheckBox();
            this.osgParticle_check = new System.Windows.Forms.CheckBox();
            this.osgTerrain_check = new System.Windows.Forms.CheckBox();
            this.osgText_check = new System.Windows.Forms.CheckBox();
            this.osgManipulator_check = new System.Windows.Forms.CheckBox();
            this.osgUtil_check = new System.Windows.Forms.CheckBox();
            this.osgViewer_check = new System.Windows.Forms.CheckBox();
            this.osgDB_check = new System.Windows.Forms.CheckBox();
            this.osgGA_check = new System.Windows.Forms.CheckBox();
            this.osg_check = new System.Windows.Forms.CheckBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.qtNetwork_check = new System.Windows.Forms.CheckBox();
            this.qtSQL_check = new System.Windows.Forms.CheckBox();
            this.qtXML_check = new System.Windows.Forms.CheckBox();
            this.qtOpenGL_check = new System.Windows.Forms.CheckBox();
            this.qtWidgets_check = new System.Windows.Forms.CheckBox();
            this.qtGui_check = new System.Windows.Forms.CheckBox();
            this.qtCore_check = new System.Windows.Forms.CheckBox();
            this.form_group_box.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(71, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Project Name";
            // 
            // form_singleton_checkbox
            // 
            this.form_singleton_checkbox.AutoSize = true;
            this.form_singleton_checkbox.Location = new System.Drawing.Point(13, 19);
            this.form_singleton_checkbox.Name = "form_singleton_checkbox";
            this.form_singleton_checkbox.Size = new System.Drawing.Size(70, 17);
            this.form_singleton_checkbox.TabIndex = 2;
            this.form_singleton_checkbox.Text = "Singleton";
            this.form_singleton_checkbox.UseVisualStyleBackColor = true;
            // 
            // cancel_button
            // 
            this.cancel_button.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cancel_button.Location = new System.Drawing.Point(15, 289);
            this.cancel_button.Name = "cancel_button";
            this.cancel_button.Size = new System.Drawing.Size(75, 23);
            this.cancel_button.TabIndex = 3;
            this.cancel_button.Text = "Cancel";
            this.cancel_button.UseVisualStyleBackColor = true;
            // 
            // accept_button
            // 
            this.accept_button.Location = new System.Drawing.Point(250, 289);
            this.accept_button.Name = "accept_button";
            this.accept_button.Size = new System.Drawing.Size(75, 23);
            this.accept_button.TabIndex = 4;
            this.accept_button.Text = "Accept";
            this.accept_button.UseVisualStyleBackColor = true;
            this.accept_button.Click += new System.EventHandler(this.accept_button_Click);
            // 
            // form_group_box
            // 
            this.form_group_box.Controls.Add(this.form_singleton_checkbox);
            this.form_group_box.Controls.Add(this.form_plugin_check);
            this.form_group_box.Location = new System.Drawing.Point(15, 28);
            this.form_group_box.Name = "form_group_box";
            this.form_group_box.Size = new System.Drawing.Size(92, 255);
            this.form_group_box.TabIndex = 5;
            this.form_group_box.TabStop = false;
            this.form_group_box.Text = "Form";
            // 
            // form_plugin_check
            // 
            this.form_plugin_check.AutoSize = true;
            this.form_plugin_check.Location = new System.Drawing.Point(13, 42);
            this.form_plugin_check.Name = "form_plugin_check";
            this.form_plugin_check.Size = new System.Drawing.Size(55, 17);
            this.form_plugin_check.TabIndex = 7;
            this.form_plugin_check.Text = "Plugin";
            this.form_plugin_check.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.osgFX_check);
            this.groupBox2.Controls.Add(this.osgParticle_check);
            this.groupBox2.Controls.Add(this.osgTerrain_check);
            this.groupBox2.Controls.Add(this.osgText_check);
            this.groupBox2.Controls.Add(this.osgManipulator_check);
            this.groupBox2.Controls.Add(this.osgUtil_check);
            this.groupBox2.Controls.Add(this.osgViewer_check);
            this.groupBox2.Controls.Add(this.osgDB_check);
            this.groupBox2.Controls.Add(this.osgGA_check);
            this.groupBox2.Controls.Add(this.osg_check);
            this.groupBox2.Location = new System.Drawing.Point(215, 28);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(110, 255);
            this.groupBox2.TabIndex = 6;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "QSG";
            // 
            // osgFX_check
            // 
            this.osgFX_check.AutoSize = true;
            this.osgFX_check.Location = new System.Drawing.Point(6, 232);
            this.osgFX_check.Name = "osgFX_check";
            this.osgFX_check.Size = new System.Drawing.Size(56, 17);
            this.osgFX_check.TabIndex = 9;
            this.osgFX_check.Text = "osgFX";
            this.osgFX_check.UseVisualStyleBackColor = true;
            this.osgFX_check.CheckedChanged += new System.EventHandler(this.osgFX_check_CheckedChanged);
            // 
            // osgParticle_check
            // 
            this.osgParticle_check.AutoSize = true;
            this.osgParticle_check.Location = new System.Drawing.Point(7, 211);
            this.osgParticle_check.Name = "osgParticle_check";
            this.osgParticle_check.Size = new System.Drawing.Size(78, 17);
            this.osgParticle_check.TabIndex = 8;
            this.osgParticle_check.Text = "osgParticle";
            this.osgParticle_check.UseVisualStyleBackColor = true;
            this.osgParticle_check.CheckedChanged += new System.EventHandler(this.osgParticle_check_CheckedChanged);
            // 
            // osgTerrain_check
            // 
            this.osgTerrain_check.AutoSize = true;
            this.osgTerrain_check.Location = new System.Drawing.Point(7, 187);
            this.osgTerrain_check.Name = "osgTerrain_check";
            this.osgTerrain_check.Size = new System.Drawing.Size(76, 17);
            this.osgTerrain_check.TabIndex = 7;
            this.osgTerrain_check.Text = "osgTerrain";
            this.osgTerrain_check.UseVisualStyleBackColor = true;
            this.osgTerrain_check.CheckedChanged += new System.EventHandler(this.osgTerrain_check_CheckedChanged);
            // 
            // osgText_check
            // 
            this.osgText_check.AutoSize = true;
            this.osgText_check.Location = new System.Drawing.Point(7, 163);
            this.osgText_check.Name = "osgText_check";
            this.osgText_check.Size = new System.Drawing.Size(64, 17);
            this.osgText_check.TabIndex = 6;
            this.osgText_check.Text = "osgText";
            this.osgText_check.UseVisualStyleBackColor = true;
            this.osgText_check.CheckedChanged += new System.EventHandler(this.osgText_check_CheckedChanged);
            // 
            // osgManipulator_check
            // 
            this.osgManipulator_check.AutoSize = true;
            this.osgManipulator_check.Location = new System.Drawing.Point(7, 139);
            this.osgManipulator_check.Name = "osgManipulator_check";
            this.osgManipulator_check.Size = new System.Drawing.Size(98, 17);
            this.osgManipulator_check.TabIndex = 5;
            this.osgManipulator_check.Text = "osgManipulator";
            this.osgManipulator_check.UseVisualStyleBackColor = true;
            this.osgManipulator_check.CheckedChanged += new System.EventHandler(this.osgManippulator_check_CheckedChanged);
            // 
            // osgUtil_check
            // 
            this.osgUtil_check.AutoSize = true;
            this.osgUtil_check.Location = new System.Drawing.Point(7, 115);
            this.osgUtil_check.Name = "osgUtil_check";
            this.osgUtil_check.Size = new System.Drawing.Size(58, 17);
            this.osgUtil_check.TabIndex = 4;
            this.osgUtil_check.Text = "osgUtil";
            this.osgUtil_check.UseVisualStyleBackColor = true;
            this.osgUtil_check.CheckedChanged += new System.EventHandler(this.osgUtil_check_CheckedChanged);
            // 
            // osgViewer_check
            // 
            this.osgViewer_check.AutoSize = true;
            this.osgViewer_check.Location = new System.Drawing.Point(7, 91);
            this.osgViewer_check.Name = "osgViewer_check";
            this.osgViewer_check.Size = new System.Drawing.Size(75, 17);
            this.osgViewer_check.TabIndex = 3;
            this.osgViewer_check.Text = "osgViewer";
            this.osgViewer_check.UseVisualStyleBackColor = true;
            this.osgViewer_check.CheckedChanged += new System.EventHandler(this.osgViewer_check_CheckedChanged);
            // 
            // osgDB_check
            // 
            this.osgDB_check.AutoSize = true;
            this.osgDB_check.Location = new System.Drawing.Point(7, 67);
            this.osgDB_check.Name = "osgDB_check";
            this.osgDB_check.Size = new System.Drawing.Size(58, 17);
            this.osgDB_check.TabIndex = 2;
            this.osgDB_check.Text = "osgDB";
            this.osgDB_check.UseVisualStyleBackColor = true;
            this.osgDB_check.CheckedChanged += new System.EventHandler(this.osgDB_check_CheckedChanged);
            // 
            // osgGA_check
            // 
            this.osgGA_check.AutoSize = true;
            this.osgGA_check.Location = new System.Drawing.Point(7, 43);
            this.osgGA_check.Name = "osgGA_check";
            this.osgGA_check.Size = new System.Drawing.Size(58, 17);
            this.osgGA_check.TabIndex = 1;
            this.osgGA_check.Text = "osgGA";
            this.osgGA_check.UseVisualStyleBackColor = true;
            this.osgGA_check.CheckedChanged += new System.EventHandler(this.osgGA_check_CheckedChanged);
            // 
            // osg_check
            // 
            this.osg_check.AutoSize = true;
            this.osg_check.Location = new System.Drawing.Point(7, 19);
            this.osg_check.Name = "osg_check";
            this.osg_check.Size = new System.Drawing.Size(43, 17);
            this.osg_check.TabIndex = 0;
            this.osg_check.Text = "osg";
            this.osg_check.UseVisualStyleBackColor = true;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.qtNetwork_check);
            this.groupBox3.Controls.Add(this.qtSQL_check);
            this.groupBox3.Controls.Add(this.qtXML_check);
            this.groupBox3.Controls.Add(this.qtOpenGL_check);
            this.groupBox3.Controls.Add(this.qtWidgets_check);
            this.groupBox3.Controls.Add(this.qtGui_check);
            this.groupBox3.Controls.Add(this.qtCore_check);
            this.groupBox3.Location = new System.Drawing.Point(113, 28);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(96, 255);
            this.groupBox3.TabIndex = 7;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Qt5";
            // 
            // qtNetwork_check
            // 
            this.qtNetwork_check.AutoSize = true;
            this.qtNetwork_check.Location = new System.Drawing.Point(7, 163);
            this.qtNetwork_check.Name = "qtNetwork_check";
            this.qtNetwork_check.Size = new System.Drawing.Size(77, 17);
            this.qtNetwork_check.TabIndex = 6;
            this.qtNetwork_check.Text = "QtNetwork";
            this.qtNetwork_check.UseVisualStyleBackColor = true;
            this.qtNetwork_check.CheckedChanged += new System.EventHandler(this.qtNetwork_check_CheckedChanged);
            // 
            // qtSQL_check
            // 
            this.qtSQL_check.AutoSize = true;
            this.qtSQL_check.Location = new System.Drawing.Point(7, 139);
            this.qtSQL_check.Name = "qtSQL_check";
            this.qtSQL_check.Size = new System.Drawing.Size(58, 17);
            this.qtSQL_check.TabIndex = 5;
            this.qtSQL_check.Text = "QtSQL";
            this.qtSQL_check.UseVisualStyleBackColor = true;
            this.qtSQL_check.CheckedChanged += new System.EventHandler(this.qtSQL_check_CheckedChanged);
            // 
            // qtXML_check
            // 
            this.qtXML_check.AutoSize = true;
            this.qtXML_check.Location = new System.Drawing.Point(7, 115);
            this.qtXML_check.Name = "qtXML_check";
            this.qtXML_check.Size = new System.Drawing.Size(59, 17);
            this.qtXML_check.TabIndex = 4;
            this.qtXML_check.Text = "QtXML";
            this.qtXML_check.UseVisualStyleBackColor = true;
            this.qtXML_check.CheckedChanged += new System.EventHandler(this.qtXML_check_CheckedChanged);
            // 
            // qtOpenGL_check
            // 
            this.qtOpenGL_check.AutoSize = true;
            this.qtOpenGL_check.Location = new System.Drawing.Point(7, 91);
            this.qtOpenGL_check.Name = "qtOpenGL_check";
            this.qtOpenGL_check.Size = new System.Drawing.Size(77, 17);
            this.qtOpenGL_check.TabIndex = 3;
            this.qtOpenGL_check.Text = "QtOpenGL";
            this.qtOpenGL_check.UseVisualStyleBackColor = true;
            this.qtOpenGL_check.CheckedChanged += new System.EventHandler(this.qtOpenGL_check_CheckedChanged);
            // 
            // qtWidgets_check
            // 
            this.qtWidgets_check.AutoSize = true;
            this.qtWidgets_check.Location = new System.Drawing.Point(7, 67);
            this.qtWidgets_check.Name = "qtWidgets_check";
            this.qtWidgets_check.Size = new System.Drawing.Size(76, 17);
            this.qtWidgets_check.TabIndex = 2;
            this.qtWidgets_check.Text = "QtWidgets";
            this.qtWidgets_check.UseVisualStyleBackColor = true;
            this.qtWidgets_check.CheckedChanged += new System.EventHandler(this.qtWidgets_check_CheckedChanged);
            // 
            // qtGui_check
            // 
            this.qtGui_check.AutoSize = true;
            this.qtGui_check.Location = new System.Drawing.Point(7, 43);
            this.qtGui_check.Name = "qtGui_check";
            this.qtGui_check.Size = new System.Drawing.Size(53, 17);
            this.qtGui_check.TabIndex = 1;
            this.qtGui_check.Text = "QtGui";
            this.qtGui_check.UseVisualStyleBackColor = true;
            this.qtGui_check.CheckedChanged += new System.EventHandler(this.qtGui_check_CheckedChanged);
            // 
            // qtCore_check
            // 
            this.qtCore_check.AutoSize = true;
            this.qtCore_check.Location = new System.Drawing.Point(7, 19);
            this.qtCore_check.Name = "qtCore_check";
            this.qtCore_check.Size = new System.Drawing.Size(59, 17);
            this.qtCore_check.TabIndex = 0;
            this.qtCore_check.Text = "QtCore";
            this.qtCore_check.UseVisualStyleBackColor = true;
            // 
            // raaDLLTemplateForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.cancel_button;
            this.ClientSize = new System.Drawing.Size(338, 321);
            this.ControlBox = false;
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.form_group_box);
            this.Controls.Add(this.accept_button);
            this.Controls.Add(this.cancel_button);
            this.Controls.Add(this.label1);
            this.Name = "raaDLLTemplateForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "raaDLLTemplateForm";
            this.form_group_box.ResumeLayout(false);
            this.form_group_box.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox form_singleton_checkbox;
        private System.Windows.Forms.Button cancel_button;
        private System.Windows.Forms.Button accept_button;
        private System.Windows.Forms.GroupBox form_group_box;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.CheckBox form_plugin_check;
        private System.Windows.Forms.CheckBox osgFX_check;
        private System.Windows.Forms.CheckBox osgParticle_check;
        private System.Windows.Forms.CheckBox osgTerrain_check;
        private System.Windows.Forms.CheckBox osgText_check;
        private System.Windows.Forms.CheckBox osgManipulator_check;
        private System.Windows.Forms.CheckBox osgUtil_check;
        private System.Windows.Forms.CheckBox osgViewer_check;
        private System.Windows.Forms.CheckBox osgDB_check;
        private System.Windows.Forms.CheckBox osgGA_check;
        private System.Windows.Forms.CheckBox osg_check;
        private System.Windows.Forms.CheckBox qtNetwork_check;
        private System.Windows.Forms.CheckBox qtSQL_check;
        private System.Windows.Forms.CheckBox qtXML_check;
        private System.Windows.Forms.CheckBox qtOpenGL_check;
        private System.Windows.Forms.CheckBox qtWidgets_check;
        private System.Windows.Forms.CheckBox qtGui_check;
        private System.Windows.Forms.CheckBox qtCore_check;
    }
}