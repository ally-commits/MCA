import java.util.*;

class Employee implements Cloneable {
	String name;
	long id;
	String designation;
	int salary = 1000;

	Employee(String name,long id,String designation,int salary) {
		this.name = name;
		this.id = id;
		this.designation = designation;
		this.salary = salary;
	}
	public Employee clone() {
		try {
			return (Employee) super.clone();
		} catch(CloneNotSupportedException e) {
			System.out.println("Error while cloning");
			return this;
		}
	}

	void incrementSalary(double inc) {
		salary += salary * inc;
	}
	void display() {
		System.out.println("\n----------------\nId:" + id);
		System.out.println("Name:" + name);
		System.out.println("Designation:" + designation);
		System.out.println("Salary:" + salary);
	}
}

class EmpMain {
	public static void main(String args[]) {
		Scanner sn = new Scanner(System.in);
		String name,designation;
		int salary;
		long id;

		System.out.println("Enter Id, Name, Designation, Salary");
		id = sn.nextLong();
		name = sn.next();
		designation = sn.next();
		salary = sn.nextInt();

		Employee emp1 = new Employee(name, id ,designation ,salary);
		Employee emp2;

		emp2 = emp1.clone();

		emp1.incrementSalary(0.10);
		emp2.incrementSalary(0.05);

		emp1.display();
		emp2.display();

	}
}
