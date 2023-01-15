class Union {
    public static void main(String args[]) {
        // String str1 = "Hello World";
        // String str2 = "dfghjiklmno";

        // char ch1[] = str1.toCharArray();
        // char ch2[] = str2.toCharArray();
        // char ch3[] = new char[30];
        // char ch4[] = new char[30];

        // int count=0;
        // for(int i=0;i<str1.length();i++){
        //     int found = 0;
        //     for(int j=0;j<count;j++) {
        //         if(ch1[i] == ch3[j]) 
        //             found = 1;
        //     }
        //     if(found == 0) 
        //         ch3[count++] = ch1[i];
        // } 
        // for(int i=0;i<str2.length();i++){
        //     int found = 0;
        //     for(int j=0;j<count;j++) {
        //         if(ch2[i] == ch3[j]) 
        //             found = 1;
        //     }
        //     if(found == 0) 
        //         ch3[count++] = ch2[i];
        // }


        // for(int i=0;i<str1.length();i++){
        //     for(int j=0;j<str2.length();j++) {
        //         if(ch1[i] == ch2[j]) 
        //             ch4[count++] = ch1[i];
        //     } 
        // }

        // System.out.println(ch3);
        // System.out.println(str1.replace("World","Alwin"));

        String str = "[1,2,356,678,3378]";

        str = str.replace("[","");
        str = str.replace("]","");
        String strArr[] = str.split(",");
        int arr[] = new int[strArr.length];

        for(int i=0;i<arr.length;i++)
            arr[i] = Integer.parseInt(strArr[i]);

        for(int i=0;i<arr.length;i++)
            System.out.print(arr[i] + " ");

        str = "";
        for(int i=0;i<arr.length;i++)
            str += arr[i] + "-";

        System.out.println(str);

    }
}