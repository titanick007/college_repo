public class circle{
    double rad;
    public circle(double rad){
        this.rad=rad;
    }
    public double calcArea(){
        return (Math.PI)*rad*rad;
    }
    public double calcCircumference(){
        return 2*Math.PI*rad;
    }
    public static void main(String args[]){
        circle C1= new circle(14.5);
        System.out.println("radius of circle = "+C1.rad);
        System.out.println("Area of circle = "+C1.calcArea());
        System.out.println("Circumference of circle= "+C1.calcCircumference());
        
    }
}