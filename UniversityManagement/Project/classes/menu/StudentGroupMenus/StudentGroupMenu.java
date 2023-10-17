package UniversityManagement.Project.classes.menu.StudentGroupMenus;

import java.io.Serializable;
import java.util.ArrayList;

import UniversityManagement.Project.classes.mainclasses.Faculty;
import UniversityManagement.Project.classes.managers.StudentGroupManager;
import UniversityManagement.Project.classes.menu.MenuInterface;
import UniversityManagement.Project.classes.utility.Reader;

public class StudentGroupMenu implements MenuInterface, Serializable {
    private ArrayList<Faculty> faculties;
    private StudentGroupManager studentGroupManager;

    public StudentGroupMenu(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
        this.studentGroupManager = new StudentGroupManager(faculties);

    }

    @Override
    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("1. Create New Student Group.");
        System.out.println("2. Select existing Student Group.");
        System.out.println("3. Print existing Student Groups.");
        System.out.println("0. Go back to previous Menu.");
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
                    studentGroupManager.addNew();
                    break;
                case 2:
                    selectStudentGroup();
                    break;
                case 3:
                    studentGroupManager.printAll();
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

    public void selectStudentGroup() {
        SelectStudentGroupMenu editStudentGroupMenu = new SelectStudentGroupMenu(faculties,studentGroupManager);
        editStudentGroupMenu.mainLoop();
    }
}
