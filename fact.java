import java.util.Scanner;
public class fact {
    public static int fact(int a){
        if(a==1)return 1;
        return a*fact(a-1);
    }
    public static void main(String args[]){
        System.out.println("Enter a number");
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        System.out.println("factorial of "+a+" is "+fact(a));
    }
}
