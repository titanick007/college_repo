import java.util.ArrayList;
import java.util.Scanner;

public class AL{
    public static void main(String args[]){
        ArrayList<Integer> list1=new ArrayList<>();
        Scanner s=new Scanner(System.in);
        System.out.println("Enter elements into list");
        for(int i=0;i<4;++i){
            int a=s.nextInt();
            list1.add(a);   //adding elements
        }
        System.out.println(list1);
        System.out.println(list1.get(2));   //getting elements from an index
        list1.add(1,4);     //adding elements at an index
        System.out.println(list1);
        list1.remove(3);    //deleting element at a specific index
        System.out.println(list1);
    }
}