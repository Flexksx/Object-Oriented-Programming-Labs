package Project.classes.menu.StudentMenus;

import java.util.ArrayList;

import Project.classes.mainclasses.Faculty;
import Project.classes.managers.Faculty.FacultyManager;
import Project.classes.managers.Student.StudentManager;
import Project.classes.managers.StudentGroup.StudentGroupManager;
import Project.classes.menu.MenuInterface;
import Project.classes.utility.Reader;

public class StudentMenu implements MenuInterface {
    private StudentManager studentManager;
    private ArrayList<Faculty> faculties;
    private StudentGroupManager studentGroupManager;
    private FacultyManager facultyManager;
    public StudentMenu(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
        this.facultyManager = new FacultyManager(faculties);
        this.studentGroupManager = new StudentGroupManager(faculties);
        this.studentManager = new StudentManager(faculties, facultyManager, studentGroupManager);
    }

    @Override
    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("1. Add New Student.");
        System.out.println("2. Print All Students.");
        System.out.println("3. Find Student by ID.");
        System.out.println("4. Find Students by Name.");
        System.out.println("0. Go back to the previous Menu.");
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
                    studentManager.addNew();
                    break;
                case 2:
                    studentManager.printAll();
                    break;
                case 3:
                    studentManager.findStudentById();
                    break;
                case 4:
                    studentManager.findStudentByName();
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

}
