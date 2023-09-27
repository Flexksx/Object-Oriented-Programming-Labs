package Project;

import Project.classes.*;

public class StudentManagerMain {
    public static void main(String[] args) {
        Faculty FAF = new Faculty("Inginerie Software", "FAF");
        FAF.addNewGroup(223);
        StudentGroup FAF223 = FAF.getStudentGroupByNumber(223);
        FAF223.addNewStudent("69","gheorghe","12.9.2003","Active");
        FAF.addNewGroup(224);
        FAF.printStudentsbyName();
    }

}