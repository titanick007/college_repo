class Person {
    String name;
    int age;
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
class Course {
    String courseCode;
    String courseName;
    public Course(String courseCode, String courseName) {
        this.courseCode = courseCode;
        this.courseName = courseName;
    }
}

class Student extends Person {
    int studentID;
    int batch;
    public Student(String name, int age, int studentID, int batch) {
        super(name, age);
        this.studentID = studentID;
        this.batch = batch;
    }
    public void displayStudentInfo() {
        System.out.println("Student ID: " + studentID);
        System.out.println("Name: " + name);
        System.out.println("Batch: " + batch);
    }
    public int calculateAge() {
        return age;
    }
}

class Faculty extends Person {
    int employeeID;
    String department;
    public Faculty(String name, int age, int employeeID, String department) {
        super(name, age);
        this.employeeID = employeeID;
        this.department = department;
    }
    public void displayFacultyInfo() {
        System.out.println("Employee ID: " + employeeID);
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);
    }

    public int calculateAge() {
        return age;
    }
}

class CourseEnrollment extends Student {
    String enrollmentID;
    String semester;
    Course course;
    public CourseEnrollment(String name, int age, int studentID, int batch, String enrollmentID, String semester, Course course) {
        super(name, age, studentID, batch);
        this.enrollmentID = enrollmentID;
        this.semester = semester;
        this.course = course;
    }

    public void displayEnrollmentInfo() {
        System.out.println("Enrollment ID: " + enrollmentID);
        System.out.println("Student Name: " + name);
        System.out.println("Course Name: " + course.courseName);
        System.out.println("Semester: " + semester);
    }

    public String calculateCourseDuration() {
        int currentYear = java.time.Year.now().getValue();
        int batchYear = currentYear - batch + 1; 
        String[] semesterParts = semester.split(" ");
        int semesterNumber = Integer.parseInt(semesterParts[1]);
        int courseDurationYears = currentYear - batchYear + (semesterNumber > 1 ? 1 : 0);
        return "Duration: " + courseDurationYears + " years";
    }
}

class TeachingAssignment extends Faculty {
    String assignmentID;
    String academicYear;
    Course course;

    public TeachingAssignment(String name, int age, int employeeID, String department, String assignmentID, String academicYear, Course course) {
        super(name, age, employeeID, department);
        this.assignmentID = assignmentID;
        this.academicYear = academicYear;
        this.course = course;
    }

    public void displayAssignmentInfo() {
        System.out.println("Assignment ID: " + assignmentID);
        System.out.println("Faculty Name: " + name);
        System.out.println("Course Name: " + course.courseName);
        System.out.println("Academic Year: " + academicYear);
    }

    public String describeAssignmentDuration() {
        int startYear = Integer.parseInt(academicYear.substring(0, 4));
        int endYear = Integer.parseInt(academicYear.substring(5, 9));

        int assignmentDurationYears = endYear - startYear + 1;

        return "Duration: " + assignmentDurationYears + " years";
    }
}
public class EducationalInstitute {
    public static void main(String[] args) {
        Course mathCourse = new Course("OOM", "Object Oriented Methodologies");

        Student student = new Student("Samuel George", 19, 2022007, 2022);
        student.displayStudentInfo();
        System.out.println("Age: " + student.calculateAge());

        System.out.println();

        Faculty faculty = new Faculty("Jai Singh", 40, 1234567, "Computer Science");
        faculty.displayFacultyInfo();
        System.out.println("Age: " + faculty.calculateAge());

        System.out.println();

        CourseEnrollment enrollment = new CourseEnrollment("Tommy Fury", 24, 2023023, 2023, "IIT2023007", "Autumn 2023", mathCourse);
        enrollment.displayEnrollmentInfo();
        System.out.println(enrollment.calculateCourseDuration());

        System.out.println();

        TeachingAssignment assignment = new TeachingAssignment("Jai Khan", 52, 1243567, "Electrical Engineering", "ECE172", "2023-2024", mathCourse);
        assignment.displayAssignmentInfo();
        System.out.println(assignment.describeAssignmentDuration());
    }
}
