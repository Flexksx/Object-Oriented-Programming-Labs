package Project.classes;

import java.util.ArrayList;

public class Student {

  private String studentID;
  private String name;
  private String dateOfBirth;
  private Faculty faculty;
  private String dateOfEnrollment;
  private ArrayList<Mark> marks = new ArrayList<>();
  private Status status;

  public Student(String id, String name, String dob, Faculty fac, Status status, String doe) {
    this.studentID = id;
    this.name = name;
    this.dateOfBirth = dob;
    this.faculty = fac;
    this.status = status;
    this.dateOfEnrollment=doe;
  }

  public void addMark(String date, float value) {
    this.marks.add(new Mark(value, date));
  }

  public void addAbsence(String date) {
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

  public String getStudentID() {
    return this.studentID;
  }

  public void setDateOfEnrollment(String dateOfEnrollment) {
    this.dateOfEnrollment = dateOfEnrollment;
  }

  public void setStatus(Status status) {
    this.status = status;
  }

  public void setMarks(ArrayList<Mark> marks) {
    this.marks = marks;
  }

  public String getDateOfEnrollment() {
    return this.dateOfEnrollment;
  }

  public Status getStatus() {
    return this.status;
  }

}
