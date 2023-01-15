import java.util.ArrayList;
import java.util.Collections;

public class Raj {

    static ArrayList<String> strArr = new ArrayList<>();

    private static void permutations(String candidate, String remaining) {
        // base case
        if (remaining == null) {
            return;
        }

        if (remaining.length() == 0) {
            // System.out.println(candidate);
            strArr.add(candidate);
        }

        for (int i = 0; i < remaining.length(); i++) {
            String newCandidate = candidate + remaining.charAt(i);

            String newRemaining = remaining.substring(0, i) +
                    remaining.substring(i + 1);

            permutations(newCandidate, newRemaining);
        }
    }
    public static void main(String args[]) { 

        int L1 = 3;
        String w1 = "ram";
        int L2 = 6;
        String w2 = "cmarma";
        permutations("", w1);

        ArrayList<String> ansArr = new ArrayList<>();

        for(String s : strArr) {
            if(w2.contains(s)) {
                ansArr.add(s);
            }
        } 


        System.out.println(ansArr.size());
        for(String s : ansArr) {
            System.out.println(s);
        }
    }
}
