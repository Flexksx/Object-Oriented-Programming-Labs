package Labs2OOP;

import java.util.ArrayList;

public class Student {
    private String StudentID;
    private String Name;
    private String DateOfBirth;
    private String Faculty;
    private String Speciality;
    private ArrayList<Mark> Marks;

    public void setDateOfBirth(String dateOfBirth) {
        this.DateOfBirth = dateOfBirth;
    }

    public void setFaculty(String faculty) {
        this.Faculty = faculty;
    }

    public void setName(String name) {
        this.Name = name;
    }

    public void setSpeciality(String speciality) {
        this.Speciality = speciality;
    }

    public void setStudentID(String studentID) {
        this.StudentID = studentID;
    }

}