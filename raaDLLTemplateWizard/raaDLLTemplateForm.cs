using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace raaDLLTemplateWizard
{
    public partial class raaDLLTemplateForm : Form
    {


        public raaDLLTemplateForm(string sName)
        {
            InitializeComponent();

            label1.Text = "Project Name: " + sName;

            form_singleton_checkbox.Checked = true;
            qtCore_check.Checked = true;
            qtGui_check.Checked = true;
            qtWidgets_check.Checked = true;

        }

        private void accept_button_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        public bool singleton()
        {
            return form_singleton_checkbox.Checked;
        }

        public bool plugin()
        {
            return form_plugin_check.Checked;
        }

        public bool qt()
        {
            return qtCore_check.Checked;
        }

        public bool osg()
        {
            return osg_check.Checked;
        }

        public string qtDebug()
        {
            string sMsg="";

            if (qtCore_check.Checked) sMsg += " Qt5Cored.lib;";
            if (qtGui_check.Checked) sMsg += " Qt5Guid.lib;";
            if (qtWidgets_check.Checked) sMsg += " Qt5Widgetsd.lib;";
            if (qtOpenGL_check.Checked) sMsg += " Qt5OpenGLd.lib;";
            if (qtXML_check.Checked) sMsg += " Qt5Xmld.lib;";
            if (qtSQL_check.Checked) sMsg += " Qt5Sqld.lib;";
            if (qtNetwork_check.Checked) sMsg += " Qt5Networkd.lib;";

            return sMsg;
        }

        public string qtRelease()
        {
            string sMsg="";

            if (qtCore_check.Checked) sMsg += " Qt5Core.lib;";
            if (qtGui_check.Checked) sMsg += " Qt5Gui.lib;";
            if (qtWidgets_check.Checked) sMsg += " Qt5Widgets.lib;";
            if (qtOpenGL_check.Checked) sMsg += " Qt5OpenGL.lib;";
            if (qtXML_check.Checked) sMsg += " Qt5Xml.lib;";
            if (qtSQL_check.Checked) sMsg += " Qt5Sql.lib;";
            if (qtNetwork_check.Checked) sMsg += " Qt5Network.lib;";

            return sMsg;
        }

        public string osgDebug()
        {
            string sMsg="";

            if (osg_check.Checked) sMsg += " osgd.lib;";
            if (osgGA_check.Checked) sMsg += " osgGAd.lib;";
            if (osgDB_check.Checked) sMsg += " osgDBd.lib;";
            if (osgViewer_check.Checked) sMsg += " osgViewerd.lib;";
            if (osgUtil_check.Checked) sMsg += " osgUtild.lib;";
            if (osgManipulator_check.Checked) sMsg += " osgManipulatord.lib;";
            if (osgText_check.Checked) sMsg += " osgTextd.lib;";
            if (osgTerrain_check.Checked) sMsg += " osgTerraind.lib;";
            if (osgParticle_check.Checked) sMsg += " osgParticled.lib;";
            if (osgFX_check.Checked) sMsg += " osgFXd.lib;";

            return sMsg;
        }

        public string osgRelease()
        {
            string sMsg="";

            if (osg_check.Checked) sMsg += " osg.dll;";
            if (osgGA_check.Checked) sMsg += " osgGA.dll;";
            if (osgDB_check.Checked) sMsg += " osgDB.dll;";
            if (osgViewer_check.Checked) sMsg += " osgViewer.dll;";
            if (osgUtil_check.Checked) sMsg += " osgUtil.dll;";
            if (osgManipulator_check.Checked) sMsg += " osgManipulator.dll;";
            if (osgText_check.Checked) sMsg += " osgText.dll;";
            if (osgTerrain_check.Checked) sMsg += " osgTerrain.dll;";
            if (osgParticle_check.Checked) sMsg += " osgParticle.dll;";
            if (osgFX_check.Checked) sMsg += " osgFX.dll;";

            return sMsg;
        }




        private void qtGui_check_CheckedChanged(object sender, EventArgs e)
        {
            if (qtGui_check.Checked) qtCore_check.Checked = true;
        }

        private void qtWidgets_check_CheckedChanged(object sender, EventArgs e)
        {
            if (qtWidgets_check.Checked)
            {
                qtCore_check.Checked = true;
                qtGui_check.Checked = true;
            }
        }

        private void qtOpenGL_check_CheckedChanged(object sender, EventArgs e)
        {
            if (qtOpenGL_check.Checked) qtCore_check.Checked = true;
        }

        private void qtXML_check_CheckedChanged(object sender, EventArgs e)
        {
            if (qtXML_check.Checked) qtCore_check.Checked = true;
        }

        private void qtSQL_check_CheckedChanged(object sender, EventArgs e)
        {
            if (qtSQL_check.Checked) qtCore_check.Checked = true;
        }

        private void qtNetwork_check_CheckedChanged(object sender, EventArgs e)
        {
            if (qtNetwork_check.Checked) qtCore_check.Checked = true;
        }

        private void osgGA_check_CheckedChanged(object sender, EventArgs e)
        {
            if (osgGA_check.Checked) osg_check.Checked = true;
        }

        private void osgDB_check_CheckedChanged(object sender, EventArgs e)
        {
            if (osgDB_check.Checked) osg_check.Checked = true;
        }

        private void osgViewer_check_CheckedChanged(object sender, EventArgs e)
        {
            if (osgViewer_check.Checked) osg_check.Checked = true;
        }

        private void osgUtil_check_CheckedChanged(object sender, EventArgs e)
        {
            if (osgUtil_check.Checked) osg_check.Checked = true;
        }

        private void osgManippulator_check_CheckedChanged(object sender, EventArgs e)
        {
            if (osgManipulator_check.Checked) osg_check.Checked = true;
        }

        private void osgText_check_CheckedChanged(object sender, EventArgs e)
        {
            if (osgText_check.Checked) osg_check.Checked = true;
        }

        private void osgTerrain_check_CheckedChanged(object sender, EventArgs e)
        {
            if (osgTerrain_check.Checked) osg_check.Checked = true;
        }

        private void osgParticle_check_CheckedChanged(object sender, EventArgs e)
        {
            if (osgParticle_check.Checked) osg_check.Checked = true;
        }

        private void osgFX_check_CheckedChanged(object sender, EventArgs e)
        {
            if (osgFX_check.Checked) osg_check.Checked = true;
        }
    }
}
