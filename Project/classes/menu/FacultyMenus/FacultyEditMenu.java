package Project.classes.menu.FacultyMenus;

import java.util.ArrayList;
import Project.classes.mainclasses.Faculty;
import Project.classes.managers.Faculty.FacultyManager;
import Project.classes.menu.MenuInterface;
import Project.classes.utility.Reader;

public class FacultyEditMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;

    public FacultyEditMenu(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
    }

    @Override
    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("What do you want to do with this Faculty?");
        System.out.println("1. Print its' Students by Name.");
        System.out.println("2. Print its' Students by ID.");
        System.out.println("3. Print existing Student Groups.");
        System.out.println("4. Add new Student Group.");
        System.out.println("5. Select Student Group.");
        System.out.println("0. Go back to the Previous Menu.");
        System.out.println("==========================================");
    }

    @Override
    public void mainLoop() {
        FacultyManager facultyManager = new FacultyManager(this.faculties);
        facultyManager.selectFaculty();
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = Reader.safeSelect(6);
            switch (option) {
                case 1:
                    facultyManager.getFaculty().printStudentsbyName();
                    break;
                case 2:
                    facultyManager.getFaculty().printStudentsbyID();
                    break;
                case 3:
                    facultyManager.printAllSubordinates();
                    break;
                case 4:
                    facultyManager.addNewSubordinate();
                    break;
                case 5:
                    facultyManager.selectStudentGroup();
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }
}