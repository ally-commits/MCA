public class Extract {
    public static void main(String args[]) {
        String str = "v=spf1 ip4:40.113.200.201 ip6:2001:db8:85a3:8d3:1319:8a2e:370:7348 include:thirdpartydomain.com";

        String newStr[];
        newStr = str.split(" ");

        for (String s: newStr) {
            if(s.contains("ip6")) {
                String extractStr[] = s.split("ip6:");
                System.out.println("EXTRACTED IPV6:" + extractStr[1]);
            }
        }
    }
}
