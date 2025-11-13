import java.net.*;
import java.util.Scanner;

public class udps {
	public static void main(String[] args) {
		DatagramSocket skt = null;
		Scanner sc = new Scanner(System.in);
		try {
			skt = new DatagramSocket(2400);
			byte[] buffer = new byte[1000];

			while (true) {
				DatagramPacket request = new DatagramPacket(buffer, buffer.length);
				skt.receive(request);

				String received = new String(request.getData(), 0, request.getLength());
				System.out.println("server received: " + received);

				System.out.print("Reply: ");
				String message = sc.nextLine();
				byte[] sendMsg = message.getBytes();

				DatagramPacket reply = new DatagramPacket(sendMsg, sendMsg.length, request.getAddress(), request.getPort());
				skt.send(reply);
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			if (skt != null) skt.close();
			sc.close();
		}
	}
}
