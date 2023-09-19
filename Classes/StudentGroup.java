package Labs2OOP.Classes;

import java.util.ArrayList;

public class StudentGroup {
    private String Name;
    private ArrayList<Student> Students = new ArrayList<Student>();

    public StudentGroup(String name, ArrayList<Student> students) {
        this.Name = name;
        this.Students = students;
    }

    public StudentGroup(String name) {
        this.Name = name;
    }

    public String getName() {
        return this.Name;
    }

    public ArrayList<Student> getStudents() {
        return this.Students;
    }

    public void setName(String name) {
        this.Name = name;
    }

    public void setStudents(ArrayList<Student> students) {
        this.Students = students;
    }

}
