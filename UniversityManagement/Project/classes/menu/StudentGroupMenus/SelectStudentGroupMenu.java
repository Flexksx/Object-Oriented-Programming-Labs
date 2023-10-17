package UniversityManagement.Project.classes.menu.StudentGroupMenus;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Scanner;

import UniversityManagement.Project.classes.mainclasses.Faculty;
import UniversityManagement.Project.classes.mainclasses.Student;
import UniversityManagement.Project.classes.mainclasses.StudentGroup;
import UniversityManagement.Project.classes.managers.StudentGroupManager;
import UniversityManagement.Project.classes.managers.StudentManager;
import UniversityManagement.Project.classes.menu.MenuInterface;
import UniversityManagement.Project.classes.menu.StudentMenus.SelectStudentMenu;
import UniversityManagement.Project.classes.utility.Reader;

public class SelectStudentGroupMenu implements MenuInterface, Serializable {
    private ArrayList<Faculty> faculties;
    private StudentGroupManager studentGroupManager;
    private StudentGroup studentGroup;
    private Faculty faculty;

    public SelectStudentGroupMenu(ArrayList<Faculty> faculties, StudentGroupManager studentGroupManager) {
        this.faculties = faculties;
        this.studentGroupManager = studentGroupManager;
        this.faculty = studentGroupManager.getFaculty();
        studentGroupManager.selectOne();
        this.studentGroup = studentGroupManager.getStudentGroup();
    }

    @Override
    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("1. Print Students in this Group.");
        System.out.println("2. Add Student to Group.");
        System.out.println("3. Move Student to another Group.");
        System.out.println("4. Select Student.");
        System.out.println("0. Go back to the Previous Menu.");
        System.out.println("==========================================");

    }

    @Override
    public void mainLoop() {
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = Reader.safeSelect(4);
            switch (option) {
                case 1:
                    studentGroupManager.printAllSubordinates();
                    break;
                case 2:
                    studentGroupManager.addNewSubordinate();
                    break;
                case 3:
                    studentGroupManager.moveStudentToAnotherGroup();
                    break;
                case 4:
                    navigateToStudent();
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

    private void navigateToStudent() {
        StudentManager studentManager = new StudentManager(this.faculties, this.faculty, this.studentGroup);
        studentManager.selectOne();
        Student student = studentManager.getStudent();
        SelectStudentMenu selectStudentMenu = new SelectStudentMenu(student);
        selectStudentMenu.mainLoop();
    }
}
