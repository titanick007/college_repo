class Person {
    String name;
    int age;
    String gender;

    public Person(String name, int age, String gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }
}

class Student extends Person {
    int studentID;
    int grade;

    public Student(String name, int age, String gender, int studentID, int grade) {
        super(name, age, gender);
        this.studentID = studentID;
        this.grade = grade;
    }

    public void displayStudentInfo() {
        System.out.println("Student ID: " + studentID);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
        System.out.println("Grade: " + grade);
    }

    public void displayGradeLevel() {
        System.out.println("Grade Level: " + grade);
    }
}

class Teacher extends Person {
    int teacherID;
    String subject;

    public Teacher(String name, int age, String gender, int teacherID, String subject) {
        super(name, age, gender);
        this.teacherID = teacherID;
        this.subject = subject;
    }

    public void displayTeacherInfo() {
        System.out.println("Teacher ID: " + teacherID);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
        System.out.println("Subject: " + subject);
    }

    public void displaySubject() {
        System.out.println("Teaches: " + subject);
    }
}

class AdministrativeStaff extends Person {
    int staffID;
    String role;

    public AdministrativeStaff(String name, int age, String gender, int staffID, String role) {
        super(name, age, gender);
        this.staffID = staffID;
        this.role = role;
    }

    public void displayStaffInfo() {
        System.out.println("Staff ID: " + staffID);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
        System.out.println("Role: " + role);
    }

    public void displayRole() {
        System.out.println("Role: " + role);
    }
}

class Principal extends Teacher {
    int principalID;
    int yearsOfExperience;

    public Principal(String name, int age, String gender, int teacherID, String subject, int principalID, int yearsOfExperience) {
        super(name, age, gender, teacherID, subject);
        this.principalID = principalID;
        this.yearsOfExperience = yearsOfExperience;
    }

    public void displayPrincipalInfo() {
        System.out.println("Principal ID: " + principalID);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Gender: " + gender);
        System.out.println("Subject: " + subject);
        System.out.println("Years of Experience: " + yearsOfExperience);
    }

    public void displayExperience() {
        System.out.println("Years of Experience: " + yearsOfExperience);
    }
}

public class SchoolManagementSystem {
    public static void main(String[] args) {
        Student student = new Student("Samuel George", 19, "Male", 2022007, 10);
        student.displayStudentInfo();
        student.displayGradeLevel();
        System.out.println();

        Teacher teacher = new Teacher("Bhibhas Goshal", 45, "Male" ,1234567, "Data Structures");
        teacher.displayTeacherInfo();
        teacher.displaySubject();
        System.out.println();

        AdministrativeStaff staff = new AdministrativeStaff("Rohit Kumar", 34, "Male", 1235473, "Administrator");
        staff.displayStaffInfo();
        staff.displayRole();

        System.out.println();

        Principal principal = new Principal("Dr. Paul Walker ", 50, "Male", 2436183, "Computer Science and Mathematics", 149728, 20);
        principal.displayPrincipalInfo();
        principal.displayExperience();
    }
}
