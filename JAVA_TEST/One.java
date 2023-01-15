public class One {
    public static void main(String args[]) {
        String text = "\"Student\":{\"Name\":\"John\",\"Age\":\"15\"},\"Class\":\"10\"";
        String queries[] = { "Student.Name", "Student.Age", "Class" };
        
        String solve[] = new String[queries.length];
        int count = 0;

        System.out.println(text);
        String newStr = text.replace("\"", "");
        newStr = newStr.replace("{", "");
        newStr = newStr.replace("}", "");

        System.out.println(newStr);

        for(String s:queries) {
            for(String s1: newStr.split(",")) {
                String[] newStrArr = s1.split(":");
                String[] ansStr = s.split("\\.");
                String keyValue = ansStr.length > 1 ? ansStr[1] : ansStr[0];

                for(int i=0;i<newStrArr.length;i++) {
                    if(newStrArr[i].equals(keyValue)) {
                        solve[count++] = newStrArr[i+1];
                        break;
                    }
                }
                 
            }
        }
        for(String s: solve) {
            System.out.println(s);
        }
    }
}
