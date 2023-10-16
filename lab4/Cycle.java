class Bicycle{
    int gear;
    double speed;
    public Bicycle(int gear,double speed){
        this.gear=gear;
        this.speed=speed;
    }
    public void changespeed(double change_by){
        speed=speed+change_by;
    }
    public void displayinfo(){
        System.out.println("Gear : "+gear);
        System.out.println("Speed : "+speed);
    }
}
class MountainBike extends Bicycle{
    double seat_height;
    public  MountainBike(int gear,double speed,double seat_height){
        super(gear, speed);
        this.seat_height=seat_height;
    }
    public void update_seat_height(double new_seat_height){
        seat_height=new_seat_height;
    }
    public void displayinfo(){
        System.out.println("Gear : "+gear);
        System.out.println("Speed : "+speed);
        System.out.println("Seat height : "+seat_height);
    }
}
public class Cycle {
    public static void main(String args[]){
        Bicycle bike=new Bicycle(6, 25);
        System.out.println("Displaying attributes of cycle");
        bike.displayinfo();
        MountainBike mbike=new MountainBike(7,20,15);
        System.out.println("Decreasing bike speed by 10");
        bike.changespeed(-10);
        System.out.println("New bicycle attributes");
        bike.displayinfo();
        System.out.println("Mountain bike attributes");
        mbike.displayinfo();
        System.out.println("Increasing seat height by 3 inches");
        mbike.update_seat_height(18);
        System.out.println("New mountain bike attributes");
        mbike.displayinfo();
    }
}
