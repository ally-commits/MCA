import java.io.*;

public class Replica {
    public static void main(String args[]) throws Exception {
        File mainFile = new File("replica/");
        File files[] = mainFile.listFiles();

        for(int i=0;i<files.length;i++) {
            for(int j=i+1;j<files.length;j++) {
                Boolean equal = true;
                FileInputStream f1 = new FileInputStream(files[i]);
                FileInputStream f2 = new FileInputStream(files[j]);

                int inputA = f1.read(),inputB = f2.read();

                while(inputA != -1 || inputB != -1) {
                    if(inputA != inputB) {
                        equal = false;
                        break;
                    }
                    inputA = f1.read();
                    inputB = f2.read();
                }
                if(equal) {
                    System.out.println(files[i].getName() + "=>" + files[j].getName());
                }

            }
        }
    }
}
