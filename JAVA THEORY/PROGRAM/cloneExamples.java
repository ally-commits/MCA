package samplePrograms;

class Person{
	String name;
	int age, weight;
	
	Person(String s, int a, int w){
		name = s;
		age = a;
		weight = w;
	}
	
	public boolean equals(Person p) {
		return name.equals(p.name) && age == p.age && weight == p.weight;
	}
}

public class cloneExamples {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Person p1 = new Person("abc", 35, 50);
		Person p2 = new Person("abc", 35, 50);
		Person p3 = new Person("xyz", 35, 120);
		
		System.out.println(p1.toString());
		System.out.println(p2.toString());
		 
		if (p1.equals(p2)) {
			System.out.println("Equal");
		}
		else {
			System.out.println("Not Equal");
		}
		
		if (p1 == p2){
			System.out.println("Equal ==");
		}
		else {
			System.out.println("Not Equal ==");
		}
		
		if (p3 == p1){
			System.out.println("Equal == object");
		}
		else {
			System.out.println("Not Equal == object");
		}
		
		if (p3.equals(p1)){
			System.out.println("Equal  object");
		}
		else {
			System.out.println("Not Equal  object");
		}

	}

}
