import java.io.*;
import java.net.*;

public class Client {
    public static void main(String args[]) throws Exception{
        Socket socket = new Socket("127.0.0.1", 2000);

        BufferedReader sin = new BufferedReader(new InputStreamReader(System.in));
        
        BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintStream output = new PrintStream(socket.getOutputStream());

        

        String s; 
        //READ DATA FROM KEYBOARD
        System.out.print("Enter File Name:");
        s = sin.readLine();

        //SEND DATA
        output.println(s);


        //READ DATA
        s = input.readLine();
        System.out.println("OUTPUT:" + s);
    }
}
