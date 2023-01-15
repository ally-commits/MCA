import java.io.File;

public class First {
    public static void main(String args[]) throws Exception{
        File f1 = new File("files/two.txt");
        File f2 = new File("files/one.txt");
        File f3 = new File("files/three.txt");
        File f4 = new File("files/folder");
        File f5 = new File("files");

        f3.createNewFile();
        f4.mkdir();
        System.out.println(f1.renameTo(f2));

        String strList[] = f5.list();

        for (String str : strList) {
            System.out.println(str);
        }

        File fileList[] = f5.listFiles();
        int count = 1;
        for (File f : fileList) {
            if(f.isFile()) {
                String fileName = "files/" + count + ".txt";
                File newF = new File(fileName);
                count++;
                f.renameTo(newF);
            } 
        }
    }
}