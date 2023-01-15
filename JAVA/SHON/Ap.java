import java.util.HashMap;

class Ap {
    static HashMap<String,String> hashMap = new HashMap<>();


 
    public static void main(String args[]) { 

        String chessMatrix[][] = {
            {"BE","BH","BC","BK","BQ","BC","BH","BE"},
            {"BP","BP","BP","BP","BP","BP","BP","BP"},
            {"EE","EE","EE","EE","EE","EE","EE","EE"},
            {"EE","EE","EE","EE","EE","EE","EE","EE"},
            {"EE","EE","EE","EE","EE","EE","EE","EE"},
            {"EE","EE","EE","EE","EE","EE","EE","EE"},
            {"WP","WP","WP","WP","WP","WP","WP","WP"},
            {"WE","WH","WC","WQ","WK","WC","WH","WE"},
        };
        render(chessMatrix);

        chessMatrix[0][0] = "EMPTY";
        chessMatrix[1][0] = "BPELE";

        render(chessMatrix);
    }

    public static void render(String str[][]) {
        System.out.println("--------------------");
        for(int i=0;i<str.length;i++) {
            for(int j=0;j<str[i].length;j++) {
                System.out.print(hashMap.get(str[i][j]) + "\t");
            }
            System.out.println("");
        }
    }
}