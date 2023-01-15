class MyExceptionError extends Exception {
    MyExceptionError(String msg) {
        super(msg);
    }
}


class MyException {
    public static void main(String args[]) {
        try {
            throw new MyExceptionError("Hey there ");
        } catch(Exception e) {
            System.out.print(e);
        }
    }
}