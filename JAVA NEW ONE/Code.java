class Code {
    public static void main(String arrgs[]) {
        int N = 10;
        int counter = 1;
        boolean togggle = true;
        for(int i=0;i<N;i++) {
            if(togggle) {
                for (int j = 0; j < counter; j++) {
                    System.out.print("*");
                }
            }
            for(int j=0;j<N-counter;j++) { 
                System.out.print("#");
            }
            if(!togggle) {
                for (int j = 0; j < counter; j++) {
                    System.out.print("*");
                }
            }
            if(counter <= (N / 2)) {
                counter++;
            } else {
                counter--;
            }
            togggle = !togggle;
            System.out.print("\n");
        }
    }
}

select a.id ,a.name from 