import java.util.*;

class MarksOutOfBound extends Exception {
	String  detail;

	MarksOutOfBound(String detail) {
		this.detail = detail;
	}

	public String toString() {
		return "Marks Out Of Bound: " + detail;
	}
}
class StudentComp {
	String studentName;
	int stringName;
	long rollNumber;
	int marks[] = new int[3];

	Scanner sn = new Scanner(System.in);
	void getMarks() {
		try {
			System.out.println("Enter Student Name:");
			studentName = sn.next();
			System.out.println("Enter Student Roll Number:");
			rollNumber = sn.nextLong();
			System.out.println("Enter Marks in 3 Subjects:");

			for(int i=0;i<marks.length;i++) {
				marks[i] = sn.nextInt();
				if(marks[i] < 0 || marks[i] > 100)
					throw new MarksOutOfBound(marks[i] + " is invalid it should be between 0 - 100");
			}
			stringName = Integer.valueOf(studentName);

		} catch(NumberFormatException exc) {
			System.out.println("Invalid conversion of a string to a numeric format:" + exc);
		} catch(MarksOutOfBound exc) {
			System.out.println(exc);
		}
	}
}

class Student {
	public static void main(String args[]) {
		StudentComp sc = new StudentComp();
		sc.getMarks();
	}
}