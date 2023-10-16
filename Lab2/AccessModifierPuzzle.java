class Parent{
    private int age;
    public Parent(int age){
        this.age=age;
    }
    public void displayinfo(){
        System.out.println("Age = "+age);
    }
}

public class AccessModifierPuzzle {
    public static void main(String args[]){
        Parent p1 = new Parent(35);
        p1.displayinfo();
    }
}
