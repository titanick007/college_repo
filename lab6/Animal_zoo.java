import java.util.ArrayList;

// Interface for eating behavior
interface Eater {
    void eat();
}

// Interface for sound-making behavior
interface SoundMaker {
    void makeSound();
}

// Base class for all animals
class Animal {
    String name;
    int age;
    String gender;

    public Animal(String name, int age, String gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
}

// Mammal class
class Mammal extends Animal implements Eater, SoundMaker {
    String furColor;

    public Mammal(String name, int age, String gender, String furColor) {
        super(name, age, gender);
        this.furColor = furColor;
    }

    @Override
    public void eat() {
        System.out.println(name+ " is eating.");
    }

    @Override
    public void makeSound() {
        System.out.println(name+ " is making a sound.");
    }
}

// Bird class
class Bird extends Animal implements Eater, SoundMaker {
    private double wingSpan;

    public Bird(String name, int age, String gender, double wingSpan) {
        super(name, age, gender);
        this.wingSpan = wingSpan;
    }

    @Override
    public void eat() {
        System.out.println(name + " is eating.");
    }

    @Override
    public void makeSound() {
        System.out.println(name + " is making a sound.");
    }
}

// Reptile class
class Reptile extends Animal implements Eater {
    String scaleColor;

    public Reptile(String name, int age, String gender, String scaleColor) {
        super(name, age, gender);
        this.scaleColor = scaleColor;
    }

    @Override
    public void eat() {
        System.out.println(name + "  is eating.");
    }
}

// Zoo class
class Zoo {
    ArrayList <Mammal> mammallist=new ArrayList<>();
    ArrayList <Bird> birdlist=new ArrayList<>();
    ArrayList <Reptile> reptilelist=new ArrayList<>();
    public void addMammal(Mammal animal) {
        mammallist.add(animal);
    }
    public void addBird(Bird animal) {
        birdlist.add(animal);
    }
    public void addReptile(Reptile animal) {
        reptilelist.add(animal);
    }

    public void performDailyActivities_mammal() {
        for (Mammal animal : mammallist) {
            animal.eat();
            animal.makeSound();
        }
    }
    public void performDailyActivities_bird() {
        for (Bird animal : birdlist) {
            animal.eat();
            animal.makeSound();
        }
    }
    public void performDailyActivities_reptile() {
        for (Reptile animal : reptilelist) {
            animal.eat();
        }
    }
}

// Main class
public class Animal_zoo {
    public static void main(String[] args) {
        // Create a Zoo
        Zoo zoo = new Zoo();

        // Add animals to the zoo
        zoo.addMammal(new Mammal("Lion", 5, "Male", "Golden"));
        zoo.addBird(new Bird("Eagle", 3, "Female", 6.5));
        zoo.addReptile(new Reptile("Snake", 2, "Male", "Green"));

        // Perform daily activities at the zoo
        zoo.performDailyActivities_mammal();
        zoo.performDailyActivities_bird();
        zoo.performDailyActivities_reptile();
    }
}
