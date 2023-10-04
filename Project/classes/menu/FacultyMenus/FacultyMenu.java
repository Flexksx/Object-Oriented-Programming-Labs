package Project.classes.menu.FacultyMenus;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.mainclasses.Faculty;
import Project.classes.managers.Faculty.FacultyManager;
import Project.classes.menu.MenuInterface;
import Project.classes.utility.Reader;

public class FacultyMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;
    private FacultyManager facultyManager;

    public FacultyMenu(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
        this.facultyManager = new FacultyManager(this.faculties);
    }

    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("1. Add new Faculty.");
        System.out.println("2. Select existing Faculty.");
        System.out.println("3. Print existing Faculties.");
        System.out.println("0. Go back to the previous Menu.");
        System.out.println("==========================================");
    }

    public void mainLoop() {
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = Reader.safeSelect(4);
            switch (option) {
                case 1:
                    this.facultyManager.addNew();
                    break;
                case 2:
                    editFaculty();
                    break;
                case 3:
                    this.facultyManager.printAll();
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

    private void editFaculty() {
        FacultyEditMenu facEditMenu = new FacultyEditMenu(faculties);
        facEditMenu.mainLoop();
    }
}
