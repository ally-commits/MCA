import java.util.*;



class Student {
    String name;
    int age,regno;

    Student() {}

    Student(int age,int regno,String name) {
        this.name = name;
        this.age = age;
        this.regno = regno;
    }

    void display() {
        System.out.println(name);
        System.out.println(age);
        System.out.println(regno);
    }
}   
class Object {
    public static void main(String args[]) {
        Student s = new Student(10,1234,"Alwin");

        s.display();
    }
}