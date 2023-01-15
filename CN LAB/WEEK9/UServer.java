import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UServer {
    static byte[] buff = new byte[1024];
    public static void main(String args[]) throws Exception {
        DatagramSocket socket = new DatagramSocket(4001);
        DatagramPacket dp = new DatagramPacket(buff, buff.length);
        BufferedReader sin = new BufferedReader(new InputStreamReader(System.in));

        InetAddress ip = InetAddress.getLocalHost();

        socket.receive(dp);
        String str = new String(dp.getData(), 0, dp.getLength());
        System.out.println(str);

        String str1 = new String(sin.readLine());
        buff = str1.getBytes();

        socket.send(new DatagramPacket(buff, str.length(), ip, 4000));
    }
}
