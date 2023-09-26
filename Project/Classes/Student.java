package Project.Classes;

import java.util.ArrayList;

public class Student {

  private String studentID;
  private String name;
  private String dateOfBirth;
  private String faculty;
  private String speciality;
  private String dateOfEnrollment;
  private ArrayList<Mark> marks = new ArrayList<>();

  private  String Status;

  public Student(String id, String name, String dob, String fac, String spec, String status) {
    this.studentID = id;
    this.name = name;
    this.dateOfBirth = dob;
    this.faculty = fac;
    this.speciality = spec;
    this.Status=status;
  }

  public void addMark(String date, float value){
    this.marks.add(new Mark(value, date));
  }
  public void addAbsence(String date){
    this.marks.add(new Mark(date));
  }
  public void setDateOfBirth(String dateOfBirth) {
    this.dateOfBirth = dateOfBirth;
  }

  public void setFaculty(String faculty) {
    this.faculty = faculty;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setSpeciality(String speciality) {
    this.speciality = speciality;
  }

  public void setStudentID(String studentID) {
    this.studentID = studentID;
  }
  public String getDateOfBirth() {
      return this.dateOfBirth;
  }
  public String getFaculty() {
      return this.faculty;
  }
  public ArrayList<Mark> getMarks() {
      return this.marks;
  }
  public String getName() {
      return this.name;
  }
  public String getSpeciality() {
      return this.speciality;
  }
  public String getStudentID() {
      return this.studentID;
  }

  public void setDateOfEnrollment(String dateOfEnrollment) {
    this.dateOfEnrollment = dateOfEnrollment;
  }

  public void setStatus(String status) {
    this.Status = status;
  }

  public void setMarks(ArrayList<Mark> marks) {
    this.marks = marks;
  }

  public String getDateOfEnrollment() {
    return this.dateOfEnrollment;
  }
}

