import java.util.Scanner;
public class LeakyBucket {
public static void main(String[] args) {
    int[] packets = new int[20];
    int buck_rem = 0, buck_cap = 4, rate = 3, sent, recv;
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the number of packets:");
    int n = in.nextInt();
    System.out.println("Enter the packets:");
    for (int i = 1; i <= n; i++) packets[i] = in.nextInt();
        System.out.println("Clock\tPacket Size\tAccept\tSent\tRemaining");
        for (int i = 1; i <= n; i++) {
            if (packets[i] != 0) {
                if (buck_rem + packets[i] > buck_cap)
                    recv = -1;
                else {
                    recv = packets[i]; buck_rem += packets[i];
                }
            } else recv = 0;
            if (buck_rem != 0) {
                if (buck_rem < rate) {
                    sent = buck_rem; buck_rem = 0;
                }
                else {
                    sent = rate; buck_rem -= rate;
                }
            }
            else sent = 0;
            if (recv == -1)
                System.out.println(i + "\t" + packets[i] + "\tDropped\t" + sent + "\t" + buck_rem);
            else
                System.out.println(i + "\t" + packets[i] + "\t" + recv + "\t" + sent + "\t" + buck_rem);
        }
    }
}