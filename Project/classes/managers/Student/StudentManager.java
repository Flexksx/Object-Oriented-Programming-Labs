package Project.classes.managers.Student;

import java.util.ArrayList;

import Project.classes.mainclasses.Faculty;
import Project.classes.mainclasses.Student;
import Project.classes.mainclasses.StudentGroup;
import Project.classes.managers.ManagerInterface;
import Project.classes.managers.Faculty.FacultyManager;
import Project.classes.managers.StudentGroup.StudentGroupManager;
import Project.classes.utility.Reader;

public class StudentManager implements ManagerInterface {
    private ArrayList<Faculty> faculties;
    private Faculty faculty = null;
    private ArrayList<StudentGroup> groups;
    private StudentGroup group = null;
    private Student student = null;
    private FacultyManager facultyManager;
    private StudentGroupManager studentGroupManager;

    public StudentManager(ArrayList<Faculty> faculties, FacultyManager facultyManager,
            StudentGroupManager studentGroupManager) {
        this.faculties = faculties;
        this.facultyManager = facultyManager;
        this.studentGroupManager = studentGroupManager;
    }

    @Override
    public void addNew() {
        facultyManager.selectOne();
        this.faculty = this.facultyManager.getFaculty();
        studentGroupManager.setFaculty(this.faculty);
        studentGroupManager.addNewSubordinate();
    }

    @Override
    public void printAll() {

    }

    @Override
    public void addNewSubordinate() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'addNewSubordinate'");
    }

    @Override
    public void printAllSubordinates() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'printAllSubordinates'");
    }

    @Override
    public void selectSubordinate() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'selectSubordinate'");
    }

    @Override
    public void selectOne() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'selectOne'");
    }

    public void findStudentById() {
        System.out.println("found");
    }

    public void findStudentByName() {
        System.out.println("found");
    }
}
