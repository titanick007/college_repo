class Car extends Vehicle{
	private String carmodel;
	private int numdoors;
	private String manufacturer;
	public Car(){};
	public void setvalues(String fueltype,String carmodel,int numdoors,String manufacturer){
		this.manufacturer=manufacturer;
		this.carmodel=carmodel;
		this.numdoors=numdoors;
		this.fueltype=fueltype;
	}
	public String getcarmodel(){
		return carmodel;
	}
	public String getfueltype(){
		return fueltype;
	}
	public int getnumdoors(){
		return numdoors;
	}
	public String getmanufacturer(){
		return manufacturer;
	}
}
class Bike extends Vehicle{
	private String has_sidecar;
	private String manufacturer;
	private String bikemodel;
	public Bike(){};
	public void setbikevalues(String fueltype,String manufacturer,String bikemodel,String has_sidecar){
		this.fueltype=fueltype;
		this.manufacturer=manufacturer;
		this.bikemodel=bikemodel;
		this.has_sidecar=has_sidecar;
	}
	public String getfueltype(){
		return fueltype;
	}
	public String getmanufacturer(){
		return manufacturer;
	}
	public String getbikemodel(){
		return bikemodel;
	}
	public String check_sidecar(){
		return has_sidecar;
	}
}
public class Vehicle{
	String fueltype;
	public void printfueltype(){
		System.out.println("Fuel type is "+fueltype);
	} 
	public static void main(String args[]){
		Car c1=new Car();
		Bike bike1=new Bike();
		c1.setvalues("diesel","Aventador",2,"Lamborghini");
		bike1.setbikevalues("Petrol","Honda","CBR 250R","NO");
		System.out.println("Car Model : "+c1.getcarmodel()+"\nManufacturer : "+c1.getmanufacturer()+"\nFuel type : "+c1.getfueltype()+"\nNo. of doors : "+c1.getnumdoors());
		System.out.println("Bike Model : "+bike1.getbikemodel()+"\nManufacturer : "+bike1.getmanufacturer()+"\nFuel type : "+bike1.getfueltype()+"\nSidecar availability : "+bike1.check_sidecar());
	}	
}
