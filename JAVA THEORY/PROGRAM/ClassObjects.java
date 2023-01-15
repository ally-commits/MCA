package samplePrograms;

class Sample{
	int a;
	int b;
	int result;
	
	public Sample() {
		// TODO Auto-generated constructor stub
		a = 10;
		b = 12;
	}
	
	public Sample(Sample obj) {
		this.a = obj.a;
		this.b = obj.b;
	}
	
	void add() {
		result = a + b;
	}
}

public class ClassObjects {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Sample obj1 = new Sample();
		
		obj1.a = 20;
		obj1.b = 30;
		obj1.add();
		System.out.println(obj1.result);
		
		Sample obj2;
		obj2 = obj1;
		obj2.add();
		System.out.println(obj2.result);
		
		Sample obj3 = new Sample(obj1);
		obj3.add();
		System.out.println(obj3.result);
		
		obj1.a = 25;
		obj1.b = 20;
		obj1.add();
		System.out.println(obj1.result);
		obj2.add();
		System.out.println(obj2.result);
		
		obj3.a = 50;
		obj3.b = 25;
		obj3.add();
		System.out.println(obj3.result);
		
	}

}
