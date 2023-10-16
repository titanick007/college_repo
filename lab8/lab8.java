class Vehicle{
    public void start_engine(){
        System.out.println("Engine started");
    }
}
class Car extends Vehicle{
    @Override
    public void start_engine(){
        System.out.println("Car engine started");
    }
}
public class lab8{
    public static void main(String[] args){
        Vehicle v1=new Vehicle();
        Car myCar=new Car();
        //start_engine() for Vehicle class
        v1.start_engine();
        //start_engine() for Car class
        myCar.start_engine();
    }
}