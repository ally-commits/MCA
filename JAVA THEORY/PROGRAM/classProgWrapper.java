package samplePrograms;

public class classProgWrapper {
	
	public void input(Float obj) {
		System.out.println(obj);
	}
	
	public Float output(float b) {
		Float obj = new Float(b);
		return obj;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		float float_a = (float) 10.0;
		
		Float obj_float = new Float(float_a);
		
		String str1 = new String(obj_float.toString());
		
		System.out.println(Float.valueOf(str1));
		
		System.out.println(obj_float.floatValue());
		
		classProgWrapper objClass = new classProgWrapper();
		objClass.input((float)20.0);
		
		float out = objClass.output((float)5.5);
		System.out.println(out);
	}

}
