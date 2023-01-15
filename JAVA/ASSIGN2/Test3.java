import java.io.*; 
class Test3 {
    public static void main(String args[])throws IOException {
        FileReader file = new FileReader("a.txt"); 
        BufferedReader fileInput = new BufferedReader(file); 
        System.out.println (fileInput.readLine()); 
        fileInput.close();
    } 
}
