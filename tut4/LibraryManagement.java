import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
class Author{
    String name;
    ArrayList<Book> authorbooklist=new ArrayList<Book>();
}
class Book{
    private String title;
    private Author author;
    private String genre;
    private boolean isAvailable;

}
class Patron{
    private String name;
    ArrayList <Book> borrowedBookList= ArrayList <Book>();
}
public class LibraryManagement {
    
}
