import java.io.*;
import java.lang.*;


public class FileComp {
    public static void main(String args[]) {
        File f1 = new File("/Users/alwincrasta/MCA/JAVA/FILE");
        File f2 = new File("two.txt");

        System.out.println(f1.getName());
        System.out.println(f1.getParent());
        System.out.println(f1.getPath());
        System.out.println(f1.getAbsolutePath());
        System.out.println(f1.isAbsolute());
        System.out.println(f1.length());

        System.out.println(f1.exists());
        System.out.println(f1.canWrite());
        System.out.println(f1.canRead());
        System.out.println(f1.canExecute());
        System.out.println(f1.isDirectory());
        System.out.println(f1.isFile());

        System.out.println(f1.lastModified());


        System.out.println(f1.renameTo(f2));
        f2.delete();
        



        System.out.println("-------------");
        String str[] = f1.list();
        for(int i=0;i<str.length;i++)
            System.out.println(str[i]);


        System.out.print(f1.lastModified());


        new File("newpath/1/2/3/4").mkdirs();


        System.out.println("-------------");
        File list[] = f1.listFiles();
        for (int i = 0; i < list.length; i++)
            System.out.println(list[i]);
 

    }
}