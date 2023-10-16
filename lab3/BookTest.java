class Book{
    private String title;
    private String author;
    private int year_published;
    private double price;
    public Book(){
        title="Harry Potter and the Chamber of Secrets";
        author="J.K. Rowling";
        year_published=1998;
        price=500;
    }
    public Book(String title, String author, int year_published,double price){
        this.title=title;
        this.author=author;
        this.year_published=year_published;
        this.price=price;
    }
    public void display_details(Book b){
        System.out.println("Title : "+b.title);
        System.out.println("Author : "+b.author);
        System.out.println("Year published : "+b.year_published);
        System.out.println("Price : "+b.price);
        System.out.println("\n");
    }
}
public class BookTest{
    public static void main(String args[]){
        Book b1=new Book();
        Book b2=new Book("Wizard of Oz","L. Frank Baum",1900,350);
        b1.display_details(b1);
        b2.display_details(b2);
    }
}