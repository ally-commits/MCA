package samplePrograms;


class FinallyExample1 {
	static void methodA() {
		try {
			//System.out.println("In methodA");
			throw new NullPointerException("Demo"); 
	}catch (NullPointerException e)
		{ System.out.println ("In methodA's catch"); throw e;}
	}
	public static void main(String args[]) {
		try {
			methodA();
		} catch (NullPointerException e) 
				{System.out.println("Exception caught: + e");}
	}
}		