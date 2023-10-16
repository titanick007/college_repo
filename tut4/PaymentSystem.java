// base class
abstract class PaymentMethod{
    abstract void processPayment(float amount);
    abstract void printReceipt();
}
class CreditCard extends PaymentMethod(){
    float amount;
    private long cardNumber;
    private String cardHolder;
    public CreditCard(long cardNumber,String cardHolder){
        this.cardHolder=cardHolder;
        this.cardNumber=cardNumber;
    }
    public void processPayment(float amount){
        amount=amount;
    }
}