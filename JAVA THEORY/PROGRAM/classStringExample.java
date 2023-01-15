package samplePrograms;

public class classStringExample {
	
	public static void main(String args[]) {
		
		String str1, str2, str3;
		str1 = "Hello";
		str2 = "world";
	
		// comparision
		if (str1.compareTo(str2) == 0) {
			System.out.println("Same string");
		}
		else {
			System.out.println("Not Equal");
		}
		
		//concatination
		str3 = str1.concat(str2);
		System.out.println(str3);
		
		
		//replace char with ASCII
		char[] charArry = str3.toCharArray();
		StringBuffer str4 = new StringBuffer(str3);
		byte[] c_i;
		for (int i = 0; i < str3.length(); i++) {
			
			if ((i+1)%5 == 0) {
				c_i = (byte) charArry[i];
				str4.deleteCharAt(i);
				str4.insert(i, c_i);
			}
		}
		
		System.out.println(str4);
	}
	

}
