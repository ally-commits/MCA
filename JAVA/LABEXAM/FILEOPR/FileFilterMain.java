import java.io.*;

class FileFilterComp implements FilenameFilter{
    String ext;
    
    FileFilterComp(String ext) {
        this.ext = ext;
    }
    public boolean accept(File dir,String name) {
        return name.endsWith(ext);
    }
}

class FileFilterMain {
    public static void main(String args[]) {
        File f1 = new File("files/");
        FileFilterComp filter = new FileFilterComp("txt");


        String strList[] = f1.list(filter);


        for (String str : strList) {
            System.out.println(str);
        }

    }
} 
