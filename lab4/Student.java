public class Student{
    int rollnumber;
    int height;
    public Student(int rollnumber,int height){
        this.rollnumber=rollnumber;
        this.height=height;
    }
    public void displayinfo(){
        System.out.println("Roll no. : "+rollnumber+"\t"+"Height : "+height);
    }
    public static void main(String args[]){
        Student[] arrStudent;
        arrStudent= new Student[4];
        arrStudent[0]=new Student(5, 180);
        arrStudent[1]=new Student(6,177);
        arrStudent[2]=new Student(7, 174);
        arrStudent[3]=new Student(8, 172);
        int sum=0;
        for(int i=0;i<4;++i){
            arrStudent[i].displayinfo();
            sum=sum+arrStudent[i].height;
        }
        System.out.println("Average height = "+sum/4.0);

    }
}