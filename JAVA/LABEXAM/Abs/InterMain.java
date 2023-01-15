interface Area {
    static final float pi=3.14F;
    int data = 100;
    float compute(float x,float y);
}

class Rect implements Area {
    public float compute(float x,float y) {
        return x * y;
    }
}

class InterMain {
    public static void main(String args[]) {
        Area a;
        Rect r = new Rect();
        a=r;
        System.out.print(a.compute(10,30));
    }
}