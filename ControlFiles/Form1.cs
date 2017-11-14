﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Google.Protobuf;
using System.Threading;
using Info;
using System.IO;



namespace RAT_Control
{

    public partial class Form1 : Form
    {
        static Server server = new Server();
        
        public Form1()
        {
            Thread loopthread = new Thread(new ThreadStart(checkForData));

            loopthread.Start();
            InitializeComponent();

        }


        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
          
            
        }

        public void setData()
        {
            string path = @"C:\Users\Wilky\Desktop\Packetproto\kek2.text";
            byte[] file = packGlobal.myPacket.File.ToByteArray();
            int len = file.Length;

            File.WriteAllBytes(path, file);          
            

            string formatted = string.Format("{1}\nDate: {2}\nProcessor: {3}\n",packGlobal.myPacket.Name,packGlobal.IP,packGlobal.myPacket.Date, packGlobal.myPacket.Processor);
            BeginInvoke((Action)(() => { richTextBox1.Text = formatted; }), null);
           // BeginInvoke((Action)(() => { listBox1.Items.Add(packGlobal.myPacket); }),null);



        }

        private void Form1_Load(object sender, EventArgs e)
        {
         
        }

        private void Refresh_Click(object sender, EventArgs e)
        {
            int i = 0;
           

            this.Refresh();
        }

        private void ListBox1_DataSourceChanged(Object sender, EventArgs e)
        {

        }

        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
          //  int visibleItems = listBox1.ClientSize.Height / listBox1.ItemHeight;
          // listBox1.TopIndex = Math.Max(listBox1.Items.Count - visibleItems + 1, 0);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        public void convertBitmap()
        {
            //gotta redo google proto or actually I would rather just kill myself that works too.
        }

        public void checkForData()
        {
            while(true)
            {
                if(packGlobal.myPacket!=null)
                {
                    setData();
                    break;
                }
            }
        }
    }
}
    
