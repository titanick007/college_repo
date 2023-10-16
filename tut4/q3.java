import java.util.*;

class Product {
    private int productId;
    private String productName;
    private double price;
    private int quantityInStock;
    private List<Review> reviews;

    public Product(int productId, String productName, double price, int quantityInStock) {
        this.productId = productId;
        this.productName = productName;
        this.price = price;
        this.quantityInStock = quantityInStock;
        this.reviews = new ArrayList<>();
    }

    public int getProductId() {
        return productId;
    }

    public String getProductName() {
        return productName;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantityInStock() {
        return quantityInStock;
    }

    public void setQuantityInStock(int quantityInStock) {
        this.quantityInStock = quantityInStock;
    }

    public List<Review> getReviews() {
        return reviews;
    }

    public void addReview(Review review) {
        reviews.add(review);
    }
}

class Customer {
    private int customerId;
    private String firstName;
    private String lastName;
    private String email;

    public Customer(int customerId, String firstName, String lastName, String email) {
        this.customerId = customerId;
        this.firstName = firstName;
        this.lastName = lastName;
        this.email = email;
    }

    public int getCustomerId() {
        return customerId;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getEmail() {
        return email;
    }
}

class Review {
    private int rating;
    private String comment;

    public Review(int rating, String comment) {
        this.rating = rating;
        this.comment = comment;
    }

    public int getRating() {
        return rating;
    }

    public String getComment() {
        return comment;
    }
}

class CartItem {
    private Product product;
    private int quantity;

    public CartItem(Product product, int quantity) {
        this.product = product;
        this.quantity = quantity;
    }

    public Product getProduct() {
        return product;
    }

    public int getQuantity() {
        return quantity;
    }
}

class ShoppingCart {
    private int cartId;
    private Customer customer;
    private List<CartItem> cartItems;

    public ShoppingCart(int cartId, Customer customer) {
        this.cartId = cartId;
        this.customer = customer;
        this.cartItems = new ArrayList<>();
    }

    public void addItem(Product product, int quantity) {
        if (product.getQuantityInStock() >= quantity) {
            cartItems.add(new CartItem(product, quantity));
            product.setQuantityInStock(product.getQuantityInStock() - quantity);
        } else {
            System.out.println("Insufficient quantity in stock for " + product.getProductName());
        }
    }

    public void removeItem(Product product) {
        cartItems.removeIf(cartItem -> cartItem.getProduct() == product);
    }

    public double calculateTotal() {
        double total = 0.0;
        for (CartItem cartItem : cartItems) {
            total += cartItem.getProduct().getPrice() * cartItem.getQuantity();
        }
        return total;
    }

    public void displayCart() {
        System.out.println("Shopping Cart for " + customer.getFirstName() + " " + customer.getLastName());
        for (CartItem cartItem : cartItems) {
            Product product = cartItem.getProduct();
            System.out.println("Product: " + product.getProductName() + ", Quantity: " + cartItem.getQuantity() + ", Price: $" + product.getPrice());
        }
        System.out.println("Total: $" + calculateTotal());
    }
}

public class q3{
    public static void main(String[] args) {
        // Create some customers
        Customer customer1 = new Customer(1, "Thomas", "Brady", "tom@example.com");
        Customer customer2 = new Customer(2, "Jane", "Spielman", "jane@example.com");

        // Create some products
        Product product1 = new Product(101, "Laptop", 999.99, 15);
        Product product2 = new Product(102, "Phone", 399.99, 30);
        Product product3 = new Product(103, "Tablet", 199.99, 10);

        // Create shopping carts for customers
        ShoppingCart cart1 = new ShoppingCart(1, customer1);
        ShoppingCart cart2 = new ShoppingCart(2, customer2);

        // Add items to carts
        cart1.addItem(product1, 2);
        cart1.addItem(product2, 1);
        cart2.addItem(product2, 3);
        cart2.addItem(product3, 2);

        // Display carts and calculate total
        cart1.displayCart();
        cart2.displayCart();
    }
}
