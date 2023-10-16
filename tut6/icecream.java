class ABCIceCream {
}
class XIceCream extends ABCIceCream {
    public void icecream() {
        System.out.println("Vanilla flavor ice cream from your local parlor.");
    }
}
class YIceCream extends ABCIceCream {
    public void icecream() {
        System.out.println("Vanilla and chocolate flavor ice cream from the neighboring town parlor.");
    }
}
public class tut6q2 {
    public static void main(String[] args) {
        XIceCream local = new XIceCream();
        YIceCream neighbor = new YIceCream();
        local.icecream();
        neighbor.icecream();
    }
}
