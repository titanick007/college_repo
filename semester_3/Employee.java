class Employee{
    int id;
    public Employee(int id){
        this.id=id;
    }
    public double earn(){
        return 0.0;
    }
 }
 class salariedEmployee extends Employee{
    double salary;
    public salariedEmployee(int id,double salary){
        super(id);
        this.salary=salary;
    }
    public double earn(){
        return salary;
    }
 }
 class hourlyEmployee extends Employee{
     double hourly_rate,hours_worked;
     public hourlyEmployee(int id,double hourly_rate,double hours_worked){
          super(id);
          this.hourly_rate=hourly_rate;
          this.hours_worked=hours_worked;
     }
     public double earn(){
         if(hours_worked<=40){
             return hourly_rate*hours_worked;
         }
         else {
             return 40*hours_worked + (hours_worked-40)*1.5*hourly_rate;
         }
     }
 }
 class commissionEmployee extends Employee{
     double sales,rate;
     public commissionEmployee(int id,double sales,double rate){
         super(id);
         this.sales=sales;
         this.rate=rate;
     }
     public double earn(){
         return sales*rate;
     }
 }
 class salariedcommEmployee extends Employee{
     double base,sales,rate;
     public salariedcommEmployee(int id,double base,double sales,double rate){
         super(id);
         this.base=base;
         this.sales=sales;
         this.rate=rate;
     }
     public double earn(){
         return base + sales*rate;
     }
 }
 class Payroll{
     public static void main(String[] args){
         salariedEmployee sa = new salariedEmployee(1000,10000.0);
         System.out.println("Salaried Employee Earnings : " + sa.earn());
         hourlyEmployee ho = new hourlyEmployee(1002,1000.0,45);
         System.out.println("Hourly Employee Earnings : " + ho.earn());
         commissionEmployee co = new commissionEmployee(1003,20000.0,0.4);
         System.out.println("Commission Employee Earnings : " + co.earn());
         salariedcommEmployee saC = new salariedcommEmployee(1004,10000.0,20000.0,0.25);
         System.out.println("Salaried-Commission Employee Earnings : " + saC.earn());
     }
 }