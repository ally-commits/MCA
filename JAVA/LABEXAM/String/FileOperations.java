import java.io.*;

class FileFilter implements FilenameFilter {
    String ext;
    FileFilter(String ext) {
        this.ext = ext;
    }

    public boolean accept(File f1,String name) {
        return name.endsWith(ext);
    }
}

class FileOperations {
    public static void main(String args[]) throws Exception {
        FileFilter filter = new FileFilter("txt");
        File f1 = new File("files/");

        File files[] = f1.listFiles(filter);
        int maxLength = 0;
        for(int i=0;i<files.length;i++) {
            String name = files[i].getName();
            int max = name.lastIndexOf(".");
            System.out.println(name + "-" + max);
            if(max > maxLength)
                maxLength = max;
        }
        for(int i=0;i<files.length;i++) {
            String name = files[i].getName();
            int max = name.lastIndexOf(".");
            String appendStr = "00000000000000000".substring(0,maxLength - max);
            String newName = appendStr + name.substring(0,name.lastIndexOf(".")) + ".png";
            
            // System.out.println(newName);
            File rename = new File("files/" + newName);
            files[i].renameTo(rename);
        }
    }
}
