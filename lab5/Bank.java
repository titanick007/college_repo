import java.util.Scanner;
interface BankAccount{
    abstract void deposit(double amount);
    abstract void withdraw(double amount);
}
class SavingsAccount implements BankAccount{
    double balance;
    float intrate;
    public SavingsAccount(double balance,float intrate){
        this.balance=balance;
    }
    public void deposit(double amount){
        balance=balance+amount;
    }
    public void withdraw(double amount){
        if(balance>=amount)balance=balance-amount;
        else System.out.println("Insufficient funds available");
    }
    public double calcinterest(){
        return balance+(balance*intrate);
    }
    public double getBalance(){
        return balance;
    }
}
class CheckingAccount implements BankAccount{
    double balance;
    double deductfeeamount;
    public CheckingAccount(double balance,double deductfeeamount){
        this.balance=balance;
        this.deductfeeamount=deductfeeamount;
    }
    public void deposit(double amount){
        balance=balance+amount;
    }
    public void withdraw(double amount){
        if(balance>=amount){
            balance=balance-amount;
        }
        else System.out.println("Insufficient funds available");
    }
    public void deductFees(){
        if(balance>=deductfeeamount){
            balance=balance-deductfeeamount;
        }
        else System.out.println("Insufficient funds available");
    }
    public double getBalance(){
        return balance;
    }
}
public class Bank {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        double sab,cab,monthlyfee,amount;
        float intrate;
        System.out.println("Enter initial balance and interest rate for Savings account");
        sab=sc.nextDouble();
        intrate=sc.nextFloat();
        System.out.println("Enter initial balance and monthly fee to deduct for Checkings account");
        cab=sc.nextDouble();
        monthlyfee=sc.nextDouble();
        SavingsAccount Samuel=new SavingsAccount(sab,intrate);
        CheckingAccount Shashi=new CheckingAccount(cab, monthlyfee);
        System.out.println("Enter amount to withdraw");
        amount=sc.nextDouble();

        System.out.println("withdrawing");
        Samuel.withdraw(amount);    //withdraw from Savings account
        Shashi.withdraw(amount);    //withdraw from Checkings account

        System.out.println("Savings Account\nBalance : "+Samuel.getBalance());
        System.out.println("\nCheckings Account\nBalance : "+Shashi.getBalance());

        System.out.println("Enter amount to deposit");
        amount=sc.nextDouble();

        System.out.println("depositing");
        Samuel.deposit(amount);     //Deposit in savings account
        Shashi.deposit(amount);     //Deposit in Checkings account

        System.out.println("\nSavings Account\nBalance : "+Samuel.getBalance());
        System.out.println("\nCheckings Account\nBalance : "+Shashi.getBalance());

        System.out.println("Interest in Savings account : "+Samuel.calcinterest());

        //Monthly fee deduction
        System.out.println("Deduct monthly fee of "+Shashi.deductfeeamount);
        Shashi.deductFees();
        System.out.println("Balance : "+Shashi.getBalance());
        sc.close();
    }
}
