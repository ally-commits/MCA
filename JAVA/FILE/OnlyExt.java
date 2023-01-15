import java.io.*;

class OnlyExtTemp implements FilenameFilter {
    String ext;

    public OnlyExtTemp(String ext) {
        this.ext = "." + ext;
    }

    public boolean accept(File dir, String name) {
        return name.endsWith(ext);
    }   
}

class OnlyExt {
    public static void main(String args[]) {
        String dirName = "/Users/alwincrasta/MCA/JAVA/FILE";
        FilenameFilter filter = new OnlyExtTemp("java");

        File f1 = new File(dirName);

        String files[] = f1.list(filter);

        for (int i = 0; i < files.length; i++)
            System.out.println(files[i]);

    }
}