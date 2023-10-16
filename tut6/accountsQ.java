import java.util.LinkedList;
class Account {
    double bal; // The current balance
    int accnum; // The account number

    public Account(double bal,int a) {
        this.bal=bal;
        this.accnum = a;
    }

    public void deposit(double sum) {
        if (sum > 0)
            bal += sum;
        else
            System.err.println("Account.deposit(...): "
                    + "cannot deposit negative amount.");
    }

    public void withdraw(double sum) {
        if (sum > 0)
            bal -= sum;
        else
            System.err.println("Account.withdraw(...): "
                    + "cannot withdraw negative amount.");
    }

    public double getBalance() {
        return bal;
    }

    public double getAccountNumber() {
        return accnum;
    }

    public String toString() {
        return "Acc " + accnum + ": " + "balance = " + bal;
    }

    public final void print() {
        System.out.println(toString());
    }

}
class SavingsAccount extends Account{
    double interest;
    public SavingsAccount(double bal,int a,double interest){
        super(bal,a);
        this.interest=interest;
    }
    public double calcinterest(){
        return (bal*interest)/100;
    }
}

class CurrentAccount extends Account{
    double overdraft_limit;
    public CurrentAccount(double bal,int a,double odlimit){
        super(bal,a);
        this.overdraft_limit=odlimit;
    }
    @Override
    public void withdraw(double amount) {
        if(amount <= overdraft_limit+bal) bal -= amount;
        else System.out.println("Exceeded overdraft limit");
    }
}

class Bank{
    LinkedList<Account> accounts=new LinkedList<>();
    public Bank(LinkedList<Account> accounts){
        this.accounts = accounts;
    }
    public void displayAccounts(){
        int n=accounts.size();
        for(int i=0;i<n;++i){
            Account temp=accounts.get(i);
            System.out.println("Account Number : "+temp.accnum);
            System.out.println("Balance : $"+temp.bal);
            System.out.println("\n\n");
        }
    }
}
public class accountsQ{
    public static void main(String[] args){
        SavingsAccount Shashank= new SavingsAccount(2000000, 123432, 6.0);
        SavingsAccount Saketh=new SavingsAccount(1500000, 5384573, 4.5);
        CurrentAccount Jai =new CurrentAccount(1600000, 88675463, 100000);
        LinkedList <Account> accounts= new LinkedList<>();
        accounts.add(Shashank);
        accounts.add(Saketh);
        accounts.add(Jai);
        Bank bank=new Bank(accounts);
        bank.displayAccounts();
    }
}