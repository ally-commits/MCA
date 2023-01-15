public class Rev {
    public static void main(String args[]) {
        int n=3;
        char mainAlpa = 'A';
        char alphabet = 'A';
        boolean toggle = true;
        for(int i=n;i>0;i--) {
            for (int j = 0; j < n-i; j++) {
                System.out.print(" ");
            }
            for(int j=0;j<(i*2)-1;j++) {
                System.out.print(alphabet);
                if(j == ((i*2)- 1) / 2)
                    toggle = false;

                if(toggle)
                    alphabet++;
                else    
                    alphabet--;
            } 
            System.out.print("\n");
            alphabet = ++mainAlpa;
            toggle=true;
        }
    }
}

select charindex('t', name) from employee where name = 'Aditya';
