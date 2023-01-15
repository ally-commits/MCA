import java.util.*;
import java.io.*;


class Thread1 implements Runnable {
    Thread t;
    Thread1() {
        t = new Thread(this);
        t.start();
    }
    public void run() {
        try {
            FileReader f1 = new FileReader("sentences.txt");
            File file = new File("sentences.txt");


            char charArray[] = new char[(int) file.length()];
            f1.read(charArray);
            String str = new String(charArray);
            String strArr[] = str.split("\\.");
            int largestCount = 0;
            int largestIndex = 0;
            for(int i=0;i<strArr.length;i++) {
                String strWords[] = strArr[i].split(" ");
                if(strWords.length >= largestCount) {
                    largestCount = strWords.length;
                    largestIndex = i;
                }
            }
            f1.close();

            FileWriter f2 = new FileWriter("largest.txt");
            f2.write(strArr[largestIndex]);
            f2.close();
        } catch(Exception e) {
            System.out.println(e);
        }
    }
}

class Thread2 implements Runnable {
    Thread t;
    Thread2() {
        t = new Thread(this);
        t.start();
    }
    public void run() {
        try {
            FileReader f1 = new FileReader("sentences.txt");
            File file = new File("sentences.txt");

            char charArray[] = new char[(int)file.length()];
            f1.read(charArray);
            String str = new String(charArray);
            String strArr[] = str.split("\\.");
            int smallestCount = 0;
            int smallestIndex = 0;
            for(int i=0;i<strArr.length;i++) {
                String strWords[] = strArr[i].split(" ");
                if(strWords.length <= smallestCount) {
                    smallestCount = strWords.length;
                    smallestIndex = i;
                }
            }
            f1.close();

            FileWriter f2 = new FileWriter("smallest.txt");
            f2.write(strArr[smallestIndex]);
            f2.close();
        } catch(Exception e) {
            System.out.println(e);
        }
    }
}

class MainThread {
    public static void main(String args[]) {
        Thread1 t1 = new Thread1();
        Thread2 t2 = new Thread2();

        try {
            t1.t.join();
            t2.t.join();

            FileReader f1 = new FileReader("largest.txt");
            File file1 = new File("largest.txt");
            
            char charArray1[] = new char[(int)file1.length()];
            f1.read(charArray1);
            String str1 = new String(charArray1);

            FileReader f2 = new FileReader("smallest.txt");
            File file2 = new File("smallest.txt");
            
            char charArray2[] = new char[(int)file2.length()];
            f2.read(charArray2);
            String str2 = new String(charArray2);


            System.out.println("LONGEST:" + str1);
            System.out.println("SMALLEST:" + str2);
            

        } catch(Exception e) {
            System.out.println(e);
        }
    }
}