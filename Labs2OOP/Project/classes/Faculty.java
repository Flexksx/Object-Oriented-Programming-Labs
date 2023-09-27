package Project.classes;

import java.util.ArrayList;
import java.util.List;


public class Faculty {
    private String name;
    private String groupNaming;
    private String studyField;
    // fields lowercase
    private ArrayList<StudentGroup> groups = new ArrayList<StudentGroup>();

    public Faculty(String name, String groupNaming, ArrayList<StudentGroup> groups) {
        this.name = name;
        this.groupNaming = groupNaming;
        this.groups = groups;
    }
    public Faculty(String name, String groupnaming){
        this.name =name;
        this.groupNaming =groupnaming;
    }
    public void addGroup(StudentGroup group){
        this.groups.add(group);
    }
    public void addNewGroup(String number){
        this.groups.add(new StudentGroup((groupNaming +"-"+number), this.name));
    }
    public void addNewGroup(int number){
        this.groups.add(new StudentGroup((groupNaming +"-"+Integer.toString(number)), this.name));
    }
    public void addNewGroup(String number, ArrayList<Student> students){
        this.groups.add(new StudentGroup((groupNaming +"-"+number),students, this.name));
    }

    public void setGroupNaming(String groupNaming) {
        this.groupNaming = groupNaming;
    }
    public void setGroups(ArrayList<StudentGroup> groups) {
        this.groups = groups;
    }
    public String getGroupNaming() {
        return this.groupNaming;
    }
    public ArrayList<StudentGroup> getGroups() {
        return this.groups;
    }
    public String getName() {
        return this.name;
    }

    public void printStudentGroups(){
        for (StudentGroup group : this.groups){
            System.out.println(group.getName());
        }
    }

    public void printStudentsbyName() {
        if (this.groups.isEmpty()) {
            System.err.println("There are no Students for this Specialty");
            return;
        }else {
            for (StudentGroup group : this.groups) {
                if(group.getStudents().isEmpty()){
                    continue;
                }
                else {
                    System.out.println("Students of group " + group.getName());
                }
                if (group.getStudents().isEmpty()) {
                    System.err.println("There are no Students in this group");
                } else {
                    for (Student student : group.getStudents()) {
                        System.out.println(student.getName());
                    }
                }
            }
        }
    }


    public void printStudentsbyID() {
        if (this.groups.isEmpty()) {
            System.err.println("There are no Students for this Specialty");
            return;
        }else {
            for (StudentGroup group : this.groups) {
                if(group.getStudents().isEmpty()){
                    continue;
                }
                else {
                    System.out.println("Students of group " + group.getName());
                }
                if (group.getStudents().isEmpty()) {
                    System.err.println("There are no Students in this group");
                } else {
                    for (Student student : group.getStudents()) {
                        System.out.println(student.getStudentID());
                    }
                }
            }
        }
    }
    public StudentGroup getStudentGroupByNumber(int num){
        String strnum = Integer.toString(num);
        for (StudentGroup group : this.groups){
            if(strnum.equals(group.getName().substring(group.getName().length()-3))){
                return group;
            }
        }
        System.err.println("Could not find such group in Specialty "+this.name);
        return null;
    }
}
