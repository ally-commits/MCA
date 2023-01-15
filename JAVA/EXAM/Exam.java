import java.util.ArrayList;
import java.util.List;

public class Exam {
    public static void main(String args[]) {
        int carSpeed = 100;
        ArrayList<Integer> lights = new ArrayList<Integer>();
        // lights.add(2);
        // lights.add(100);
        // lights.add(10);
        // lights.add(200);
        // lights.add(10);

        lights.add(3);
        lights.add(100);
        lights.add(10);
        lights.add(200);
        lights.add(15);
        lights.add(300);
        lights.add(10);
        
        boolean failed = true;

        while(failed) {
            failed = false;
            double meterPerSecond = (float) carSpeed / 3.6;
            System.out.println("SPEED PER SEC:" + meterPerSecond);

            int counter = 1;
            for (int i = 0; i < lights.get(0); i++) {
                int distance = lights.get(counter);
                int toggler = lights.get(counter + 1);
                double reachingSignalIn = distance / meterPerSecond;

                System.out.println("DISTANCE:" + distance);
                System.out.println("TOGGLER:" + toggler);
                System.out.println("R SIGNAL:" + reachingSignalIn);

                boolean isGreen = true;
                boolean covered = false;

                for(int j=0;j<distance;j=j+toggler) {
                    if(isGreen && (reachingSignalIn >= j && reachingSignalIn <= j+toggler)) {
                        covered = true;
                        System.out.println("SECONDS COVERED:" + j + "-" + (j+toggler));
                        break;
                    }
                    isGreen = !isGreen;
                }
                if(!covered) {
                    failed = true;
                }
                counter +=2;
            }
            if(failed) {
                carSpeed--;
            }
        }

        System.out.println("\nCAR SPEED:" + carSpeed + "\n");
    }
}