package Project.Classes;

import java.util.ArrayList;

public class StudentGroup {
    private String Name;
    private ArrayList<Student> Students = new ArrayList<Student>();
    private String Faculty;
    private String Speciality;

    public StudentGroup(String name, ArrayList<Student> students, String faculty, String speciality) {
        this.Name = name;
        this.Students = students;
        this.Faculty = faculty;
        this.Speciality = speciality;
    }

    public StudentGroup(String name, String faculty, String speciality) {
        this.Name = name;
        this.Faculty = faculty;
        this.Speciality = speciality;
    }

    public void addStudent(String studentid, String name, String dob) {
        Students.add(new Student(studentid, name, dob, this.getFaculty(), this.getSpeciality()));
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

    public void setFaculty(String faculty) {
        this.Faculty = faculty;
    }

    public void setSpeciality(String speciality) {
        this.Speciality = speciality;
    }

    public String getFaculty() {
        return this.Faculty;
    }

    public String getSpeciality() {
        return this.Speciality;
    }

}
