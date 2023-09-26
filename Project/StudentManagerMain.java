package Project;

import Project.Classes.*;

public class StudentManagerMain {
    public static void main(String[] args) {
        Faculty FCIM = new Faculty("Facultatea Calculatoare, Informatica si Microelectronica","FCIM");
        FCIM.addNewSpeciality("Inginerie Software","FAF");
        Speciality FAF =FCIM.getSpecialityByShortName("FAF");
        FAF.addNewGroup(223);
        StudentGroup FAF223 = FAF.getStudentGroupByNumber(223);
        FAF223.addNewStudent("69","gheorghe","12.9.2003","Active");
        FAF.addNewGroup(224);
        FAF.printStudentsbyName();

    }

}