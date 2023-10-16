import java.util.Scanner;
interface Shape{
    abstract double Area();
    abstract double Perimeter();
}
class Circle implements Shape{
    float rad;
    public Circle(float rad){
        this.rad=rad;
    }
    public double Area(){
        return Math.PI*rad*rad;
    }
    public double Perimeter(){
        return 2*Math.PI*rad;
    }
}
class Rectangle implements Shape{
    float l,b;
    public Rectangle(float l,float b){
        this.l=l;
        this.b=b;
    }
    public double Area(){
        return (double)l*b;
    }
    public double Perimeter(){
        return 2*((double)l +(double)b);
    }
}
public class shapemethods{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter radius of circle");
        float rad,length,breadth;
        rad=sc.nextFloat();
        System.out.println("Enter length and breadth of reactangle");
        length=sc.nextFloat();
        breadth=sc.nextFloat();

        Circle newcircle=new Circle(rad);
        Rectangle newrect=new Rectangle(length, breadth);
        System.out.println("Circle\nArea : "+newcircle.Area()+"\n"+"Circumference : "+newcircle.Perimeter()+"\n\nRectangle\nArea : "+newrect.Area()+"\nPerimeter : "+newrect.Perimeter());
        sc.close();
    }
}