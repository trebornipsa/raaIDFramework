using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using EnvDTE;
using Microsoft.VisualStudio.TemplateWizard;

namespace raaDLLTemplateWizard
{

    public class IWizardImplementation : IWizard
    {
        private raaDLLTemplateForm m_Form;
        private string m_sProjectName;

        public void BeforeOpeningFile(ProjectItem projectItem)
        {
 //           throw new NotImplementedException();
        }

        public void ProjectFinishedGenerating(Project project)
        {
 //           throw new NotImplementedException();
        }

        public void ProjectItemFinishedGenerating(ProjectItem projectItem)
        {
 //           throw new NotImplementedException();
        }

        public void RunFinished()
        {
//            throw new NotImplementedException();
        }

        public void RunStarted(object automationObject, Dictionary<string, string> replacementsDictionary, WizardRunKind runKind, object[] customParams)
        {
            try
            {
                string sLibPath = "$(raaInst)\\lib;";
                string sIncPath = "$(raaInst)\\include;";
                string sLinkDebug = "";
                string sLinkRelease = "";
                string sSingleton = "";
                string sPlugin = "";

                m_Form = new raaDLLTemplateForm(replacementsDictionary["$projectname$"]);
                m_Form.ShowDialog();

                if (m_Form.qt())
                {
                    sIncPath += " $(raaInst)\\qtDir\\include;";
                    sLibPath += " $(raaInst)\\qtDir\\lib;";
                    sLinkDebug += m_Form.qtDebug();
                    sLinkRelease += m_Form.qtRelease();
                }

                if (m_Form.osg())
                {
                    sIncPath += " $(raaInst)\\osgDir\\include;";
                    sLibPath += " $(raaInst)\\osgDir\\lib;";
                    sLinkDebug += m_Form.osgDebug();
                    sLinkRelease += m_Form.osgRelease();
                }


                replacementsDictionary.Add("$raaProjectName$", replacementsDictionary["$projectname$"]);
                replacementsDictionary.Add("$raaProjectNameCaps$", replacementsDictionary["$projectname$"].ToUpper());
                replacementsDictionary.Add("$raaLibPath$", sLibPath);
                replacementsDictionary.Add("$raaIncPath$", sIncPath);
                replacementsDictionary.Add("$raaLinkDebug$", sLinkDebug);
                replacementsDictionary.Add("$raaLinkRelease$", sLinkRelease);

                if (m_Form.singleton()) sSingleton = replacementsDictionary["$raaProjectNameCaps$"]+"_SINGLETON";
                else sSingleton = replacementsDictionary["$raaProjectNameCaps$"] + "_NO_SINGLETON";
                if (m_Form.plugin()) sPlugin = replacementsDictionary["$raaProjectNameCaps$"] + "_PLUGIN";
                else sPlugin = replacementsDictionary["$raaProjectNameCaps$"] + "_NO_PLUGIN";

                replacementsDictionary.Add("$raaSingleton$", sSingleton);
                replacementsDictionary.Add("$raaPlugin$", sPlugin);

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
//            throw new NotImplementedException();
        }

        public bool ShouldAddProjectItem(string filePath)
        {
            return true;
        }
    }
}
