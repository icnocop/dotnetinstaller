using System;

using NUnit.Framework;
using dotNetUnitTestsRunner;
using System.Diagnostics;
using TestStack.White;
using TestStack.White.Factory;
using TestStack.White.UIItems;
using TestStack.White.UIItems.WindowItems;
using TestStack.White.UIItems.WindowStripControls;
using System.IO;
using InstallerLib;

namespace InstallerEditorUnitTests
{
    [TestFixture]
    public class UIMakeExeUnitTests : EnUsUnitTests
    {
        [Test]
        [Retry(2)] // the exe sometimes doesn't get created, maybe because EndUpdateResource fails "randomly"
        public void TestMakeExe()
        {
            ConfigFile configFile = new ConfigFile();
            SetupConfiguration setupConfiguration = new SetupConfiguration();
            string configFileName = Path.Combine(Path.GetTempPath(), Guid.NewGuid().ToString() + ".xml");
            Console.WriteLine("Writing '{0}'", configFileName);
            configFile.SaveAs(configFileName);

            ProcessStartInfo pi = new ProcessStartInfo(InstallerEditorExeUtils.Executable, "\"" + configFileName + "\"");

            using (Application installerEditor = Application.Launch(pi))
            {
                ScreenshotOnFailure(() =>
                {
                    Window mainWindow = installerEditor.GetWindow(string.Format("Installer Editor - {0}", configFileName), InitializeOption.NoCache);

                    // create exe dialog
                    UIAutomation.Find<MenuBar>(mainWindow, "Application").MenuItem("File", "Create Exe...").Click();
                    Window createExeWindow = mainWindow.ModalWindow("Create Executable");

                    GetErrorMessageFromErrorDialogOnFailure(createExeWindow, () =>
                    {
                        Console.WriteLine(dotNetInstallerExeUtils.Executable);
                        UIAutomation.Find<TextBox>(createExeWindow, "txtTemplateFile").BulkText = dotNetInstallerExeUtils.Executable;

                        // opens a Save As dialog
                        UIAutomation.Find<Button>(createExeWindow, "btMake").Click();

                        string outputFilename = Path.Combine(Path.GetTempPath(), string.Format("{0}.exe", Guid.NewGuid()));

                        Console.WriteLine($"Saving file as \"{outputFilename}\"...");

                        Window saveAsWindow = createExeWindow.ModalWindow("Save As");
                        TextBox filenameTextBox = saveAsWindow.Get<TextBox>("File name:");
                        filenameTextBox.BulkText = outputFilename;
                        Button saveButton = saveAsWindow.Get<Button>("Save");

                        TakeScreenshot("Saving 1");

                        saveButton.Click();

                        TakeScreenshot("Saving 2");

                        saveAsWindow.WaitWhileBusy();

                        TakeScreenshot("Saving 3");

                        mainWindow.WaitWhileBusy();

                        TakeScreenshot("Saving 4");

                        Assert.IsTrue(WaitForFileToExist(outputFilename));

                        File.Delete(outputFilename);
                    });
                });
            }

            File.Delete(configFileName);
        }
    }
}
