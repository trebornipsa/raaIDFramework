using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace raaClassTemplateWizard
{
    public partial class raaClassTemplateForm : Form
    {
        public raaClassTemplateForm(string sName)
        {
            InitializeComponent();

            cpp_label.Text = ".cpp file: " + sName + ".cpp";
            h_label.Text = ".h file: " + sName + ".h";
            input_label.Text = "Class Name: " + sName;


        }

        private void singleton_check_CheckedChanged(object sender, EventArgs e)
        {
            if (singleton_check.Checked) q_check.Checked = false;
        }

        private void q_check_CheckedChanged(object sender, EventArgs e)
        {
            if (q_check.Checked) singleton_check.Checked = false;
        }

        private void accept_button_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }


        public bool singleton()
        {
            return singleton_check.Checked;
        }

        public bool qobject()
        {
            return q_check.Checked;
        }
    }
}
