import java.io.*;
import java.util.Scanner;
public class selection {
    public static void main(int a,int b){
        int temp=a;
        a=b;
        b=temp;
    }
    public static void main(String args[]){
        int[] arr;
        Scanner s =new Scanner(System.in);
        System.out.println("Enter size of list");
        int n= s.nextInt();
        int i;
        for(i=0;i<n;++i){
            arr[i]=s.nextInt();
        }
    }
}
