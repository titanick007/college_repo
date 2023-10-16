import java.util.Scanner;
public class sumnum {
    public static int sum(int a,int b){
        return a+b;
    }
    public static void main(String args[]){
        System.out.println("Enter two numbers\n");
        Scanner s= new Scanner(System.in);
        int a=s.nextInt();
        int b=s.nextInt();
        System.out.println("Sum="+sum(a,b));
    }
}
