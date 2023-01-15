package samplePrograms;

import java.util.ArrayList;

public class ArrayListExample {

	public static void main(String arg[]) {
		ArrayList<String> al = new ArrayList<String>();
		
		System.out.println(al.size());
		System.out.println(al);
		
		al.add("A");
		al.add("B");
		al.add("C");
		al.add("D");
		al.add("E");
		al.add("F");
		
		System.out.println(al.size());
		System.out.println(al);
		al.add(1, "A1");
		
		System.out.println("After insert" + al.size());
		System.out.println(al);
		
		al.remove(2);
		
		System.out.println("After remove" + al.size());
		System.out.println(al);
		
		int pos = al.indexOf("A1");
		
		System.out.println(pos);
		
		
	}
}
