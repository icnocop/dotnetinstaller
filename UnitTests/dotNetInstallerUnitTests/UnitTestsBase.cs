// <copyright file="UnitTestsBase.cs" company="DevAge, Vestris Inc. &amp; Contributors">
//   Copyright (c) DevAge, Vestris Inc. &amp; Contributors.
// </copyright>

namespace dotNetInstallerUnitTests
{
    using System;
    using System.IO;
    using dotNetUnitTestsRunner;
    using NUnit.Framework;

    public abstract class UnitTestsBase
    {
        private static readonly string InstallerLinkerLogFilePath = Path.Combine(Path.GetTempPath(), "InstallerLinker.txt");

        [SetUp]
        public void SetUp()
        {
            if (File.Exists(dotNetInstallerExeUtils.RunOptions.DefaultLogFile))
            {
                File.Delete(dotNetInstallerExeUtils.RunOptions.DefaultLogFile);
            }

            if (File.Exists(InstallerLinkerLogFilePath))
            {
                File.Delete(InstallerLinkerLogFilePath);
            }
        }

        [TearDown]
        public void TearDown()
        {
            if (File.Exists(dotNetInstallerExeUtils.RunOptions.DefaultLogFile))
            {
                if ((TestContext.CurrentContext.Result.State == TestState.Failure)
                    || (TestContext.CurrentContext.Result.State == TestState.Error)
                    || (TestContext.CurrentContext.Result.Status == TestStatus.Failed))
                {
                    Console.WriteLine(File.ReadAllText(dotNetInstallerExeUtils.RunOptions.DefaultLogFile));
                }

                File.Delete(dotNetInstallerExeUtils.RunOptions.DefaultLogFile);
            }

            if (File.Exists(InstallerLinkerLogFilePath))
            {
                if ((TestContext.CurrentContext.Result.State == TestState.Failure)
                    || (TestContext.CurrentContext.Result.State == TestState.Error)
                    || (TestContext.CurrentContext.Result.Status == TestStatus.Failed))
                {
                    Console.WriteLine(File.ReadAllText(InstallerLinkerLogFilePath));
                }

                File.Delete(InstallerLinkerLogFilePath);
            }
        }
    }
}
