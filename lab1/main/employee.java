public class employee {
    int id;
    public employee(int id){
            this.id=id;
    }
    class salariedemp extends employee{
        double salary;
        public salariedemp(int id,double salary){
            super(id);
            this.salary=salary;
        }
        public double pay(){
            return salary;
        }
    }
    class hourlyemp extends employee{
        int hours;
        double salaryperhour;
        double otpayph;
        public hourlyemp(int id,int hours,double salaryperhour,double otpayph){
            super(id);
            this.hours=hours;
            this.salaryperhour=salaryperhour;
            this.otpayph=otpayph;
        }
        public double pay(){
            if(hours<=40){
                return hours*salaryperhour;
            }
            else{
                return (40*salaryperhour)+(hours-40)*otpayph;
            }
        }
            
    }
    class commissionemp extends employee{
        double sales;
        double rate;
        public commissionemp(int id,double sales,double rate){
            super(id);
            this.sales=sales;
            this.rate=rate;
        }
        public double pay(){
            return sales*rate;
        }
    }
    class salariedcommissionemp extends employee{
        double base;
        double sales;
        double rate;
        public salariedcommissionemp(int id,double base,double sales,double rate){
            super(id);
            this.base=base;
            this.rate=rate;
            this.sales=sales;
        }
        public double pay(){
            return base +(rate*sales);
        }
    }
    class payroll{
        public void main(String args[]){
                salariedemp emp1 = new salariedemp(100,1000);
                System.out.println("Salaried employee earnings= "+emp1.pay());
                hourlyemp emp2 = new hourlyemp(101,42,20,25);
                System.out.println("Hourly employee earnings= "+emp2.pay());
                commissionemp emp3= new commissionemp(102,100000,0.01);
                System.out.println("Commission employee earnings= "+emp3.pay());
                salariedcommissionemp emp4= new salariedcommissionemp(103,5000,100000,0.02);
                emp4.base=emp4.base+(0.1*emp4.base);
                System.out.println("Salaried commission employee earningswith reward= "+emp4.pay());
        }    
    }
    public static void main(String args[]){}
}
    

