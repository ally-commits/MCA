import java.io.*;
import java.net.*;
import java.nio.file.Files;
import java.nio.file.Path;

public class Server {
    public static boolean isPalindrome(String s) {
        StringBuffer str = new StringBuffer(s);
        if(str.reverse().toString().equals(s)) { 
            return true;
        } else {
            return false;
        } 
    }
    public static void main(String args[]) throws Exception {
        ServerSocket socketS = new ServerSocket(2000);
        Socket socket = socketS.accept();

        BufferedReader sin = new BufferedReader(new InputStreamReader(System.in));

        BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintStream output = new PrintStream(socket.getOutputStream());

        String s;
        while (true) {
            //READ FROM KEYBOARD
            s = input.readLine();
            System.out.println("FILE NAME:" + s);

            Path path =  Path.of(s);
            Path path2 = Path.of("new.txt");
            String str = Files.readString(path);
            String newStr = "";

            for(String val: str.split(" ")) {
                if(isPalindrome(val)) {
                    newStr += val + " ";
                }
            }

            Files.writeString(path2, newStr);

            //RESPONSE
            output.println(newStr);
        }
    }
}
