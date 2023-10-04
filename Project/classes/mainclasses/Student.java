package Project.classes.mainclasses;

import java.util.ArrayList;

public class Student {

  private int studentID;
  private String name;
  private String dateOfBirth;
  private Faculty faculty;
  private String dateOfEnrollment;
  private ArrayList<Mark> marks = new ArrayList<>();
  private Status status;
  private static int ID = 1;


  public Student(String name, String dob, Faculty fac, Status status, String doe) {
    this.name = name;
    this.dateOfBirth = dob;
    this.faculty = fac;
    this.status = status;
    this.dateOfEnrollment=doe;
    this.studentID=ID++;
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

  public void setFaculty(Faculty faculty) {
    this.faculty = faculty;
  }

  public void setName(String name) {
    this.name = name;
  }

  public void setStudentID(int studentID) {
    this.studentID = studentID;
  }

  public String getDateOfBirth() {
    return this.dateOfBirth;
  }

  public Faculty getFaculty() {
    return this.faculty;
  }

  public ArrayList<Mark> getMarks() {
    return this.marks;
  }

  public String getName() {
    return this.name;
  }

  public int getStudentID() {
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
