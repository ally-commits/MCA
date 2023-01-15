package samplePrograms;

class A {
	
	int a;
	
	A(int a){
		this.a = a;
		System.out.println("Class - A - Conctructor: " + this.a);
	}
	
	void show()
	{
		System.out.println("show() - class A");
	}
}

class B extends A{
	int b;
	
	B(int a, int b){
		super(a);
		this.b = b;
		System.out.println("Class - B - Const: "+ this.b);
	}
	void show(int a)
	{
		System.out.println("show() - class B");
	}
}

class C extends B{
	
	int c;
	
	C(int a, int b, int c){
		super(a, b);
		this.c = c;
		
		System.out.println("Class - C - Const: " + this.c);
	}
	void show(int a, int b)
	{
		System.out.println("show() - class C");
	}
}

public class InheritanceExample {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//A a_obj = new A();
		//B b_obj = new B();
		C c_obj = new C(10, 20, 30);
		c_obj.show(1,2);
	}

}
