class Spacecraft{
    String name;
    double fuelCapacity;
    public Spacecraft(String name,double fuelCapacity){
        this.name=name;
        this.fuelCapacity=fuelCapacity;
    }
    public String getSpacecraftname(){
        return name;
    }
    public double getfuelCapacity(){
        return fuelCapacity;
    }
}
class Spaceship extends Spacecraft{
    int crewsize;
    public Spaceship(String name,double fuelCapacity,int crewsize){
        super(name, fuelCapacity);
        this.crewsize=crewsize;
    }
    public int getcrewsize(){
        return crewsize;
    }
}
class Starship extends Spaceship{
    double warpspeed;
    public Starship(String name,double fuelCapacity,int crewsize,double warpspeed){
        super(name,fuelCapacity,crewsize);
        this.warpspeed=warpspeed;
    }
    public double getwarpspeed(){
        return warpspeed;
    }
}
public class SpaceExplore {
    public static void main(String[] args){
        Spacecraft moonlander=new Spacecraft("Moonlander", 100);
        Spaceship  spacex=new Spaceship("spacex", 100, 5);
        Starship  mfalcon=new Starship("mfalcon",100,5,10000);
        System.out.println("Name : "+mfalcon.getSpacecraftname()+"\nFuel Capacity : "+mfalcon.getfuelCapacity()+"\nCrew size : "+mfalcon.getcrewsize()+"\nWarp Speed : "+mfalcon.getwarpspeed());

    }
}
