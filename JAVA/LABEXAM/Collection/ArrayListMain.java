import java.util.*;

class ArrayListMain {
    public static void main(String args[]) {
        ArrayList<Integer> arr = new ArrayList<Integer>();

        arr.add(100);
        arr.add(200);
        arr.add(300);
        arr.add(400);
        arr.add(500);
        arr.add(600);

        arr.add(1,5000);

        for(int v:arr) {
            System.out.print(v + " ");
        }
        System.out.print("\n");
        arr.remove(1);
        arr.remove(1);
        arr.remove(1);

        Object arrObj[] = arr.toArray();


        for(Object v : arrObj) {
            System.out.print(v + " ");
        }
        System.out.print("\n");
        arr.set(1,50000);

        System.out.println(arr.contains(10));
        System.out.println(arr.get(1));

        ArrayList<Integer> arr2 = new ArrayList<Integer>();

        arr2.add(1);
        arr2.add(1);
        arr2.add(1);
        arr2.add(1);
        arr2.addAll(arr);

        System.out.println(arr2);

        Collections.sort(arr2);

        System.out.println(arr2);



        Iterator<Integer> itr = arr2.iterator();

        while(itr.hasNext()) {
            System.out.println(itr.next());
        }

        ListIterator<Integer> listItr = arr2.listIterator();

        while(listItr.hasNext()) {
            System.out.println(listItr.next());
        }
        while(listItr.hasPrevious()) {
            System.out.println(listItr.previous());
        }
    }
}