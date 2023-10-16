interface Scene{
    public void display();
}
class Home implements Scene{
    public void display(){
        System.out.println("Inside the house\n");
    }
}
class Supermarket implements Scene{
    public void display(){
        System.out.println("Inside super maket\n");
    }
}
class Kitchen extends Home{
    @Override 
    public void display(){
        System.out.println("Inside the kitchen\n");
    }
}
public class Game_scenes {
    public static void main(String[] args){
        Home h1=new Home();
        Supermarket s1=new Supermarket();
        Kitchen k1=new Kitchen();
        //display() for Home
        h1.display();
        //display() for supermaket
        s1.display();
        //display() for kitchen
        k1.display();
    }
}
