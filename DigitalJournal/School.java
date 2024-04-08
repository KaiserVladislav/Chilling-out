package DigitalJournal;

public class School {
    private Employee[] Employees;
    private Teacher[] Teachers;
    private Student[] Students;
    private static String Address = "1 Knowledge st., Rostov-on-Don 344000, Russian Federation";
    private static String Name = "School for certified Java enjoyers";
    private java.lang.Class[] Classes;
    private Elective[] Electives;
    private ExtraCurriculum[] ExtraCurriculum;

    public Teacher[] getTeachers() {
        return Teachers;
    }

    public Employee[] getEmployees() {
        return Employees;
    }

    public Student[] getStudents() {
        return Students;
    }

    public Participant[] getParticipants(){
        return null;
    }
    public Person[] getAllPeople(){
        return null;
    }

    public static void main(String[] args) {
        Student s = new Student(1, "ALEX",123, new Parent[]{new Parent("Dale", 123), new Parent("Margo", 123)});
        Teacher t = new Teacher(1,"Dal",234, "english lad","high");
        Parent p = new Parent("Name",902);
        Employee e = new Employee(1,"Adolf",134,"high");

    }
}
