package Project;

import Project.classes.*;

public class StudentManagerMain {
    public static void main(String[] args) {
        Faculty FAF = new Faculty("Inginerie Software", "FAF");
        FAF.addNewGroup(223);
        StudentGroup FAF223 = FAF.getStudentGroupByNumber(223);
        FAF223.addNewStudent("69","gheorghe","12.9.2003","Active");
        FAF223.addNewStudent("420", "Dragos", "12.8.2003", "Active");
        FAF.addNewGroup(224);
        StudentGroup FAF224 = FAF.getGroups().get(1);
        FAF224.addNewStudent("421", "Vaniusha", "29.01.1002", "Active");
        FAF.printStudentsbyName();
    }
}