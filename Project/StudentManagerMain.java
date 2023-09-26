package Project;

import Project.Classes.*;

public class StudentManagerMain {
    public static void main(String[] args) {
        Faculty FCIM = new Faculty("Facultatea Calculatoare, Informatica si Microelectronica", "FCIM");
        Speciality FAF = new Speciality("Inginerie Software","FAF");
        StudentGroup FAF223 = new StudentGroup("FAF-223","FCIM","FAF");
        Student aaa = new Student("123123123","Gheorghe Lohu","28.08.2003","FCIM","FAF","Enrolled");
        FCIM.addSpeciality(FAF.addGroup(FAF223));
    }
}