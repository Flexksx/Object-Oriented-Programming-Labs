package Project.classes;

import java.util.ArrayList;
import java.util.List;

public class StudentGroup {
    private String name;
    private ArrayList<Student> students = new ArrayList<Student>();
    private String faculty;

    public StudentGroup(String name, ArrayList<Student> students, String faculty) {
        this.name = name;
        this.students = students;
        this.faculty = faculty;
    }

    public StudentGroup(String name, String faculty) {
        this.name = name;
        this.faculty = faculty;
    }


    public void addStudent(Student student){
        this.students.add(student);
    }

    public void addNewStudent(String studentid, String name, String dob, String status) {
        students.add(new Student(studentid, name, dob, this.getFaculty(), status));
    }

    public String getName() {
        return this.name;
    }

    public ArrayList<Student> getStudents() {
        return this.students;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setStudents(ArrayList<Student> students) {
        this.students = students;
    }

    public void setFaculty(String faculty) {
        this.faculty = faculty;
    }


    public String getFaculty() {
        return this.faculty;
    }


    public Student getStudentByName(String name){
        for(Student student : this.students){
            if(name.equals(student.getName())){
                return student;
            }
        }
        System.err.println("Could not find student "+name+" in group" + this.name);
        return null;
    }

}
