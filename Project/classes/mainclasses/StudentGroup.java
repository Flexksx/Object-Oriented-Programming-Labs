package Project.classes.mainclasses;

import java.util.ArrayList;

import Project.classes.mainclasses.enums.Status;

public class StudentGroup {
    private String name;
    private ArrayList<Student> students = new ArrayList<Student>();
    private Faculty faculty;

    public StudentGroup(String name, ArrayList<Student> students, Faculty faculty) {
        this.name = name;
        this.students = students;
        this.faculty = faculty;
    }

    public StudentGroup(String name, Faculty faculty) {
        this.name = name;
        this.faculty = faculty;
    }

    public void addStudent(Student student) {
        this.students.add(student);
    }

    public void addNewStudent(String name, String dob, Status status, String doe) {
        students.add(new Student(name, dob, this.getFaculty(), status, doe));
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

    public void setFaculty(Faculty faculty) {
        this.faculty = faculty;
    }

    public Faculty getFaculty() {
        return this.faculty;
    }

    public Student getStudentByName(String name) {
        for (Student student : this.students) {
            if (name.equals(student.getName())) {
                return student;
            }
        }
        System.err.println("Could not find student " + name + " in group" + this.name);
        return null;
    }

    public boolean removeStudent(Student studentToRemove) {
        if (students.contains(studentToRemove)) {
            students.remove(studentToRemove);
            return true;
        }
        return false;
    }

}
