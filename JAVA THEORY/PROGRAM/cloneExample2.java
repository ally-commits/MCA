package samplePrograms;

class SampleExample implements Cloneable{
	int aa;
	
	public SampleExample(int a) {
		// TODO Auto-generated constructor stub
		aa = a;
	}
	
	public SampleExample clone() throws CloneNotSupportedException{
		
		SampleExample sObj = (SampleExample)super.clone();
		return sObj;
	}
}


class TestClone implements Cloneable{
	
	int a;
	double b;
	SampleExample s;
	
	public TestClone(int a_1, double b_1, SampleExample s1) {
		// TODO Auto-generated constructor stub
		
		a = a_1;
		b = b_1;
		s = s1;
	}
	
	public TestClone clone() throws CloneNotSupportedException
	{
		TestClone cloned = (TestClone) super.clone();
		cloned.s = (SampleExample) s.clone();
		return cloned;
	}
}

public class cloneExample2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SampleExample s = new SampleExample(1000);
	
		TestClone x1 = new TestClone(10, 200.09, s);
		TestClone x2 = null;
		//TestClone x3 = x1;
		
		
		System.out.println(x1.a + "   " + x1.b + "  " + x1.s.aa);
		
		try {
			x2 = x1.clone();
			System.out.println(x2.a + "   " + x2.b+ "  " + x2.s.aa);
			
			//x1.a = 30;
			//System.out.println("x1.a = 30; -- "+x2.a + "   " + x2.b);
			x2.s.aa = 40;
			System.out.println(x1.a + "   " + x1.b + "  " + x1.s.aa);
		}
		catch (CloneNotSupportedException e) {
			// TODO: handle exception
			System.out.println("Clone not supported");
		}
		//x2.a = 40;
		//System.out.println(x1.a + "   " + x1.b);
		//System.out.println(x3.a + "   " + x3.b);

	}

}
