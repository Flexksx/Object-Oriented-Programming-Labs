package Project.classes.menu.StudentGroupMenus;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.mainclasses.Faculty;
import Project.classes.menu.MenuInterface;
import Project.classes.utility.Reader;

public class EditStudentGroupMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;

    public EditStudentGroupMenu(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
    }

    @Override
    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("1. Print Students in this Group.");
        System.out.println("2. Add Student to Group.");
        System.out.println("3. Remove Student from Group.");
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
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }
}
