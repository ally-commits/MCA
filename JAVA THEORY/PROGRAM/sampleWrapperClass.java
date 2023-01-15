package samplePrograms;

public class sampleWrapperClass {
	
	public void show(Integer obj) {
		System.out.println(obj);
	}
	
	public Integer valueReturn(Integer obj) {
		System.out.println("Value:" + obj.toString());
		return obj;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		sampleWrapperClass sampleObj = new sampleWrapperClass();
		
		Integer intObj = new Integer(10);
		
		int a = 10;
		//Integer intObj = new Integer(a);
		
		//.`.out.println(int.toString());
		
		System.out.println(intObj);
		
		System.out.println(intObj.floatValue());
		
		System.out.println(intObj.toString());
		
		Byte b = new Byte((byte)1);
		
		
		String  str = new String(b.toString());
		
		System.out.println(Byte.valueOf(str));
		
		sampleObj.show(a);
		
		int int_b = sampleObj.valueReturn(a);
		
		System.out.println(int_b);
	}

}
