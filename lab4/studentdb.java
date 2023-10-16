import java.util.*;
import java.util.Scanner;
class student{
    int studentid;
    String firstname;
    String lastname;
}
public class studentdb{
    ArrayList<student> studentlist=new ArrayList<student>();
    public void addstudent(){
        Scanner obj=new Scanner(System.in);
        student s=new student();
        System.out.println("Enter student id");
        s.studentid=obj.nextInt();
        obj.nextLine();
        System.out.println("Enter first name");
        s.firstname=obj.nextLine();
        System.out.println("Enter last name");
        s.lastname=obj.nextLine();
        studentlist.add(s);
    }
    public void removestudent(int studentid){
        studentlist.size();
        int flag=0;
        for(int i=0;i<studentlist.size();++i){
            student temp=studentlist.get(i);
            if(temp.studentid==studentid){
                studentlist.remove(i);
                flag=1;break;
            }
        }
        if(flag==0){
            System.out.println("Student with id "+studentid+" is not in the list");
        }
    }
    public void printdetails(student s){
        System.out.println("IIT202200"+s.studentid+"\t"+s.firstname+" "+s.lastname);
    }
    public void printall(){
        for(int i=0;i<studentlist.size();++i){
            student temp=studentlist.get(i);
            printdetails(temp);
        }
    }
    public static void main(String[] args){
        Scanner obj=new Scanner(System.in);
        System.out.println("Enter no. of students to add");
        studentdb STDB=new studentdb();
        int n=obj.nextInt();
        for(int i=0;i<n;++i){
            STDB.addstudent();
        }
        STDB.printall();
        System.out.println("Enter student id to remove student");
        int id=obj.nextInt();
        STDB.removestudent(id);
        STDB.printall();
        obj.close();
    }
}