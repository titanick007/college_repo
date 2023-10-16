

abstract class Beverage{
    String name;
    int sugar_amount;
    int milk_amount;
    public void prepare(){}
}
class Coffee extends Beverage{
    public void prepare(){
        System.out.println("Preparing Coffee");
    }
}
class Tea extends Beverage{
    public void prepare(){
        System.out.println("Preparing Tea");
    }
}
class LemonTea extends Beverage{
    public void prepare(){
        System.out.println("Preparing Lemon Tea");
    }
}
class CoffeeMachine{
    public void dispense(Beverage bev){
        if(bev.name=="Coffee"||bev.name=="Tea"||bev.name=="Lemon Tea") bev.prepare();
        else System.out.println("Unsupported beverage type");
    }
}
public class CoffeeMachinemain {
    public static void main(String[] args){
        CoffeeMachine nescafe=new CoffeeMachine();
        Beverage Coffee=new Coffee();
        Coffee.name="Coffee";
        Beverage Tea=new Tea();
        Tea.name="Tea";
        Beverage LemonTea=new LemonTea();
        LemonTea.name="Lemon Tea";
        nescafe.dispense(Coffee);
        nescafe.dispense(Tea);
        nescafe.dispense(LemonTea);
    }
}
