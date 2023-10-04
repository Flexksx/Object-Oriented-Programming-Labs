package Project.classes.menu.StudentGroupMenus;

import java.util.ArrayList;
import Project.classes.mainclasses.Faculty;
import Project.classes.managers.StudentGroup.StudentGroupManager;
import Project.classes.menu.MenuInterface;
import Project.classes.utility.Reader;

public class StudentGroupMenu implements MenuInterface {
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
                    editStudentGroup();
                    break;
                case 3:
                    studentGroupManager.printAll();
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

    public void editStudentGroup() {
        SelectStudentGroupMenu editStudentGroupMenu = new SelectStudentGroupMenu(faculties,studentGroupManager);
        editStudentGroupMenu.mainLoop();
    }
}
