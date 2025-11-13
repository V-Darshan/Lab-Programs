import java.net.*;

public class udpc {
	public static void main(String[] args) {
		DatagramSocket skt = null;
		try {
			skt = new DatagramSocket();
			String msg = "text message";
			byte[] b = msg.getBytes();
			InetAddress host = InetAddress.getByName("127.0.0.1");
			int serverSocket = 2400;
			DatagramPacket request = new DatagramPacket(b, b.length, host, serverSocket);
			skt.send(request);

			byte[] buffer = new byte[1000];
			DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
			skt.receive(reply);

			String received = new String(reply.getData(), 0, reply.getLength());
			System.out.println("client received: " + received);
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			if (skt != null) skt.close();
		}
	}
}
