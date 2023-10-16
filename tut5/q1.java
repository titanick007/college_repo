/* one way to do successfully do mutliple inheritance is to use @override on methods
    another way is to create an interface and define methods in the class it is inherited in 
    */
interface Animal{
    public abstract void speak();
}
class Dog implements Animal{  // inheriting from interface
    String breed;
    public Dog(String breed){
        this.breed=breed;
    }
    public void speak(){
        System.out.println("Woof - Woof");
    }
}
class puppydog extends Dog{ 
    public puppydog(String breed){
        super(breed);
    }
    @Override
    public void speak(){        //  overriding pre existing method
        System.out.println("arf-arf");
    }
}
public class q1 {
    public static void main(String[] args){
         
    }
}
