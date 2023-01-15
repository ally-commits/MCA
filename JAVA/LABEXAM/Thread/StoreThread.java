class Store {
    int arr[] = new arr[10];

}

class NewThread extends Thread {
    static Store s = new Store();

    NewThread() {
        start();
    }

    public void run() {
        for(int i=0;i<s.arr.length;i++) {
            
        }
    }
}