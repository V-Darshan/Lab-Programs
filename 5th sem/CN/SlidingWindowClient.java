import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.Random;

public class SlidingWindowClient {
    private static final String SERVER_ADDRESS = "localhost";
    private static final int PORT = 12345;
    private static final int WINDOW_SIZE = 4;
    private static final double PACKET_LOSS_RATE = 0.1; // 10% packet loss

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try (
            Socket socket = new Socket(SERVER_ADDRESS, PORT);
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()))
        ) {
            System.out.println("Connected to server.");
            System.out.println("Enter packets (type 'exit' to quit):");

            int base = 0;
            int nextSeqNum = 0;
            String[] window = new String[WINDOW_SIZE];

            while (true) {
                // Send packets within window
                while (nextSeqNum < base + WINDOW_SIZE) {
                    System.out.print("Packet " + nextSeqNum + ": ");
                    String packet = scanner.nextLine();
                    if (packet.equalsIgnoreCase("exit")) {
                        out.println("exit");
                        return;
                    }
                    window[nextSeqNum % WINDOW_SIZE] = packet;
                    if (simulatePacketLoss()) {
                        System.out.println("Packet " + packet + " lost during transmission.");
                    } else {
                        System.out.println("Sending packet: " + packet);
                        out.println(packet);
                    }
                    nextSeqNum++;
                }

                // Wait for acknowledgment
                String ack = in.readLine();
                if (ack != null && ack.startsWith("ACK")) {
                    System.out.println("Received " + ack);
                    base++;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static boolean simulatePacketLoss() {
        Random random = new Random();
        return random.nextDouble() < PACKET_LOSS_RATE;
    }
}
