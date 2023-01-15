public class One {
    public static void main(String args[]) {
        int listInput1[]= {1,1,2,3,4,5,5,7,6,9,10};
        int listInput2[] = {11,12,13,4,5,6,7,18,19,20};
        int answer = 0;

        for(int i=0;i<listInput1.length;i++) {
            int found = 0;
            for(int j=0;j<listInput2.length;j++) {
                if(listInput1[i] == listInput2[j]) 
                    found = 1;
            }
            if(found == 0)
                answer++;
        }
        for(int i=0;i<listInput2.length;i++) {
            int found = 0;
            for(int j=0;j<listInput1.length;j++) {
                if(listInput2[i] == listInput1[j]) 
                    found = 1;
            }
            if(found == 0)
                answer++;
        }

        System.out.println(answer);

    }
}