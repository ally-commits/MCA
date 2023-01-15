package samplePrograms;

public class sampleVarags {
	static void vaTest (int ... v ) {
		System.out.print("Number of args: " + v.length + "\nContents: ");
		for(int x : v) System.out.print (x + " ");
		System.out.println();
	}

	public static void main(String args[]) {
		vaTest (); 		// no args
		vaTest (10); 	// 1 arg
		vaTest (15, 18); 	// 2 args
		vaTest (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	}


}
