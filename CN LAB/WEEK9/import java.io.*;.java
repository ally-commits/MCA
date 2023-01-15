import java.io.*;
import java.net.*;

public class Server { 
    public static void main(String args[]) throws Exception {
        ServerSocket socketS = new ServerSocket(2000);
        Socket socket = socketS.accept();

        BufferedReader sin = new BufferedReader(new InputStreamReader(System.in));

        BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintStream output = new PrintStream(socket.getOutputStream());

        //GOT FROM CLIENT
        String s = input.readLine();
        System.out.println("FILE NAME:" + s);
 
        //RESPONSE
        output.println("RETURN STRING");
    }
}
