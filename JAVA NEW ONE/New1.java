import java.util.HashMap;
import java.util.Scanner;

public class New1 {
    public static void main(String args[]) {
        Scanner sn = new Scanner(System.in);

        int weight;
        System.out.println("Enter the weight:");
        weight = sn.nextInt();

        int planet;
        System.out.println("Enter the number:\n1.Venus\t2.Mars\t3.Jupiter\t4.Saturn\t5.Uranus\t6.Neptune\t");
        planet = sn.nextInt();

        switch(planet) {
            case 1:
                System.out.println("Weight on Venus:" + weight * 0.78);
                break;
            case 2:
                System.out.println("Weight on Mars:" + weight * 0.39);
                break;
            case 3:
                System.out.println("Weight on Jupiter:" + weight * 2.65);
                break;
            case 4:
                System.out.println("Weight on Saturn:" + weight * 1.17);
                break;
            case 5:
                System.out.println("Weight on Uranus:" + weight * 1.05);
                break;
            case 6:
                System.out.println("Weight on Neptune:" + weight * 1.23);
                break;
            default:
                System.out.println("Invalid Input");
        }


        
    }
}
