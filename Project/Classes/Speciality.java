package Project.Classes;

import java.util.ArrayList;

public class Speciality {
    private String Name;
    private String GroupNaming;
    private String Faculty;
    private ArrayList<StudentGroup> Groups = new ArrayList<StudentGroup>();

    public Speciality(String name, String groupnaming, ArrayList<StudentGroup> groups) {
        this.Name = name;
        this.GroupNaming = groupnaming;
        this.Groups = groups;
    }
    public Speciality(String name, String groupnaming){
        this.Name=name;
        this.GroupNaming=groupnaming;
    }
    public void addGroup(StudentGroup group){
        this.Groups.add(group);
    }
    public void addNewGroup(String number){
        this.Groups.add(new StudentGroup((GroupNaming+"-"+number), this.Faculty, this.Name));
    }
    public void addNewGroup(String number, ArrayList<Student> students){
        this.Groups.add(new StudentGroup((GroupNaming+"-"+number),students, this.Faculty, this.Name));
    }

    public void setFaculty(String faculty) {
        this.Faculty = faculty;
    }
    public void setGroupNaming(String groupNaming) {
        this.GroupNaming = groupNaming;
    }
    public void setGroups(ArrayList<StudentGroup> groups) {
        this.Groups = groups;
    }
    public String getFaculty() {
        return this.Faculty;
    }
    public String getGroupNaming() {
        return this.GroupNaming;
    }
    public ArrayList<StudentGroup> getGroups() {
        return this.Groups;
    }
    public String getName() {
        return this.Name;
    }
}
