using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EnvDTE;
using Microsoft.VisualStudio.TemplateWizard;
using System.Windows.Forms;

namespace raaClassTemplateWizard
{
    public class IWizardImplementation : IWizard
    {
        private raaClassTemplateForm m_Form;

        public void RunStarted(object automationObject, Dictionary<string, string> replacementsDictionary, WizardRunKind runKind, object[] customParams)
        {
            try
            {
                m_Form=new raaClassTemplateForm(replacementsDictionary["$rootnamespace$"]);
                m_Form.ShowDialog();

                if (m_Form.singleton())
                {
                    
                }
                else
                {
                    
                }

                if (m_Form.qobject())
                {
                    
                }
                else
                {
                    
                }


            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        public void ProjectFinishedGenerating(Project project)
        {
        }

        public void ProjectItemFinishedGenerating(ProjectItem projectItem)
        {
        }

        public bool ShouldAddProjectItem(string filePath)
        {
            return false;
        }

        public void BeforeOpeningFile(ProjectItem projectItem)
        {
        }

        public void RunFinished()
        {
        }
    }
}
