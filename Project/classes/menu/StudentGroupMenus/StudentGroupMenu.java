package Project.classes.menu.StudentGroupMenus;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.mainclasses.Faculty;
import Project.classes.mainclasses.StudentGroup;
import Project.classes.managers.StudentGroup.StudentGroupManager;
import Project.classes.menu.MenuInterface;
import Project.classes.utility.Reader;

public class StudentGroupMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;

    public StudentGroupMenu(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
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
        StudentGroupManager studentGroupManager = new StudentGroupManager(faculties);
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = Reader.safeSelect(4);
            switch (option) {
                case 1:
                    studentGroupManager.addNew();
                    break;
                case 2:
                    EditStudentGroupMenu editStudentGroupMenu = new EditStudentGroupMenu(faculties);
                    editStudentGroupMenu.mainLoop();
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
}
