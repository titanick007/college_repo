import java.util.*;
import java.util.ArrayList;
class Book{
    String title;
    String author;
    long ISBN;
    public Book(String title,String author,long ISBN){
            this.title=title;
            this.author=author;
            this.ISBN=ISBN;
    }
}
class user extends Library{
    String name;
    int id;
    public ArrayList <Book> borrowedbooklist;
    public user(ArrayList <user> userlist,ArrayList <Book> Availablebooklist,ArrayList <transaction>transactionslist,String name,int id, ArrayList<Book>borrowedbooklist){
        super(userlist, Availablebooklist,transactionslist);
        this.name=name;
        this.id=id;
        this.borrowedbooklist=borrowedbooklist;
    }
    public void addbook(Book book,user user){
        borrowedbooklist.add(book);
        Availablebooklist.remove(book);
        transaction t= new transaction(user, book,new Date(),null);
        transactionslist.add(t);
    }
    public void returnbook(Book book,user user,transaction t){
        borrowedbooklist.remove(book);
        Availablebooklist.add(book);
        t.returndate=new Date();
    }
    public void listusertransactions(user now){
        int i=0;int n=transactionslist.size();
        while(i<n){
            transaction t=transactionslist.get(i);
            if(t.Username.name==now.name){
                System.out.println(t.Username.name+" "+t.book.title+" "+t.borrowdate+" "+t.returndate);
            }
            ++i;
        }
    }
}
class Library{
    public ArrayList <user> userlist;
    public ArrayList <Book> Availablebooklist;
    public ArrayList <transaction> transactionslist;
    public Library(ArrayList <user> userlist,ArrayList <Book> Availablebooklist,ArrayList <transaction> transactionslist){
        this.userlist=userlist;
        this.Availablebooklist=Availablebooklist;
        this.transactionslist=transactionslist;
    }
    public void newbook(Book book){
        Availablebooklist.add(book);
    }
    public void newuser(user User){
        userlist.add(User);
    }
    public void listavailablebooks(){
        Availablebooklist.forEach((n) -> System.out.println(n.title));
        System.out.println("\n\n");
    }
}
class transaction{
    user Username;
    Book book;
    Date borrowdate;
    Date returndate;
    public transaction(user Username, Book book,Date borrowdate,Date returndate){
        this.Username=Username;
        this.book=book;
        this.borrowdate=borrowdate;
        this.returndate=returndate;
    }
}
public class Q3_main {
    public static void main(String args[]){
        ArrayList <Book> ABL= new ArrayList<>();
         ArrayList <Book> BBL= new ArrayList<>();
        ArrayList<user> Userslist=new ArrayList<>();
        ArrayList <transaction> translist=new ArrayList<>();
        Book b1=new Book("Atomic Habits","James Clear",173847);
        Book b2=new Book("Rich Dad Poor Dad","Robert T. Kiyosaki",173888);
        Book b3=new Book("12 Rules of Life"," Dr. Jordan Peterson",173567);
        Library MyLib= new Library(Userslist, ABL,translist);
        user shashi= new user(Userslist, ABL,translist,"Shashi shashidar",100,BBL);
        user jai=new user(Userslist, ABL,translist,"Jai Khanna",101,BBL);
        user samuel=new user(Userslist, ABL,translist,"Samuel George",107,BBL);
        user saketh=new user(Userslist,ABL,translist,"Saketh Mahadevan",106,BBL);
        MyLib.newbook(b1);      //adding book to available book list
        MyLib.newbook(b2);
        MyLib.newbook(b3);
        MyLib.newuser(shashi);  //adding user to user list
        MyLib.newuser(saketh);
        MyLib.newuser(jai);
        MyLib.newuser(samuel);
        MyLib.listavailablebooks();
        saketh.addbook(b1,saketh);      // saketh borrowin book 1
        MyLib.listavailablebooks();     // book 1 is removed from available book list
        saketh.returnbook(b1, saketh, saketh.transactionslist.get(0));      // saketh returning book 1
        MyLib.listavailablebooks();
        saketh.listusertransactions(saketh);    // printing saketh's transactions
    }
}