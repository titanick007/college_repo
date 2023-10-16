abstract class Animal{
    String name;
    int age;
    abstract void speak();
    abstract void eat();
}
class Lion extends Animal{
    public Lion(){}
    public void speak(){
        System.out.println("Roar!!");
    }
    public void eat(){
        System.out.println(name+" is eating");
    }
}
class Dolphin extends Animal{
    public Dolphin(){}
    public void speak(){
        System.out.println("Ee-ee!!!");
    }
    public void eat(){
        System.out.println(name+" is eating");
    }
}
public class Zoo {
    public static void main(String[] args){
        Lion L=new Lion();
        Dolphin D=new Dolphin();
        L.name="Simba";
        L.age=4;
        D.name="Willy";
        D.age=18;
        L.speak();
        L.eat();
        D.speak();
        D.eat();
    }
}
