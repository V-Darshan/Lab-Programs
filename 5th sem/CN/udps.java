import java.io.*;
importjava.net.*;
importjava.util.*;
public class udps
{
publicstaticvoid main(String[]args)
{
DatagramSocketskt=null;
Scannersc=newScanner(System.in); try
{
skt=newDatagramSocket(2400); byte[] buffer=new
byte[1000]; while(true)
{
DatagramPacketrequest=newDatagramPacket(buffer,buffer.length);
skt.receive(request);
Stringmessage=sc.nextLine();
byte[]sendMsg=message.getByte
s(); DatagramPacket reply=new
DatagramPacket(sendMsg,sendMsg.length,request.getAddress(),request.getPort());
skt.send(reply);
}
}
catch(Exceptionex)
{
}
}
}
