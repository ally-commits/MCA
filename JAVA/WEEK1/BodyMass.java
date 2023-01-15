import java.util.Scanner;

class BodyMass {
	public static void main(String args[]) {
		double weight,height,bmi, meter;

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter weight in Kg:");
		weight = sc.nextInt();

		System.out.println("Enter height in cm:");
		height = sc.nextInt();

		meter = height * 0.01;
		bmi = weight / (meter * meter);

		System.out.println("BMI=" + bmi);

		if(bmi < 18.5)
			System.out.println("UnderWeight !");
		else if(bmi >= 18.5 && bmi <= 24.9)
			System.out.println("Normal");
		else if(bmi >= 25 &&  bmi <= 29.9)
			System.out.println("OverWeight");
		else if(bmi >= 30)
			System.out.println("Obese");
	}
}
