public class payroll {
    public static void main(String args[]){
        salariedemp emp1 = new salariedemp(100,1000.0);
                System.out.println("Salaried employee earnings= "+emp1.pay());
                hourlyemp emp2 = new hourlyemp(101,42,20,25,0);
                System.out.println("Hourly employee earnings= "+emp2.pay());
                commissionemp emp3= new commissionemp(102,100000,0.01,0);
                System.out.println("Commission employee earnings= "+emp3.pay());
                salariedcommissionemp emp4= new salariedcommissionemp(103,5000,100000,0.02,0);
                emp4.base=emp4.base+(0.1*emp4.base);
                System.out.println("Salaried commission employee earningswith reward= "+emp4.pay());
    }
}
