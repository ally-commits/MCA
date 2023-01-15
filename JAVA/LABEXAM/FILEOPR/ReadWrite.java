import java.io.*;

class ReadWrite {
    public static void main(String args[]) throws Exception{
        File mainFile = new File("replica/");
        File fileList[] = mainFile.listFiles();

        for(int i=0;i<fileList.length;i++) {
            for(int j=i+1;j<fileList.length;j++) {
                FileReader f1 = new FileReader(fileList[i]);
                FileReader f2 = new FileReader(fileList[j]);

                char f1Char[] = new char[50];
                char f2Char[] = new char[50];

                f1.read(f1Char);
                f2.read(f2Char);

                String s1 = new String(f1Char);
                String s2 = new String(f2Char);

                if(s1.equals(s2)) {
                    System.out.println(fileList[i].getName() + "=>" + fileList[j].getName());
                }

            }
        }
    }
}