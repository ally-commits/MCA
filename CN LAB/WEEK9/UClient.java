import java.io.*;
import java.net.*;

public class UClient {
    static byte[] buff = new byte[1024];

    public static void main(String args[]) {
        try {
            DatagramSocket socket = new DatagramSocket(4000);
            DatagramPacket dp = new DatagramPacket(buff, buff.length);
            
            BufferedReader sin = new BufferedReader(new InputStreamReader(System.in));
            InetAddress ip = InetAddress.getLocalHost();


            String str = new String(sin.readLine());
            buff = str.getBytes();

            socket.send(new DatagramPacket(buff,str.length(), ip, 4001));

            socket.receive(dp);

            String str2 = new String(dp.getData(),0,dp.getLength());
            System.out.println(str2);
            
        } catch(Exception e) {
            System.out.println(e);
        }
    }
}
