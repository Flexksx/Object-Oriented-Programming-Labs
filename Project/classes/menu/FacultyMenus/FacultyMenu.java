package Project.classes.menu.FacultyMenus;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.mainclasses.Faculty;
import Project.classes.managers.FacultyManager;
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
            option = safeSelect(4);
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
        if (faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record.");
            return;
        } else {
            System.out.println("Which one of the Faculties do you want to edit?");
            for (int i = 0; i < this.faculties.size(); i++) {
                System.out.println(Integer.toString(i + 1) + ". " + this.faculties.get(i).getName());
            }
            int option = safeSelect(this.faculties.size());
            Faculty chosenFaculty = this.faculties.get(option - 1);
            FacultyEditMenu facEditMenu = new FacultyEditMenu(chosenFaculty);
            facEditMenu.mainLoop();
        }
    }

    public int safeSelect(int options) {
        int optionInt = -1;
        while (optionInt < 0 || optionInt > options) {
            String option = Reader.readln();
            try {
                optionInt = Integer.parseInt(option);
            } catch (NumberFormatException e) {
                System.err.println("Invalid input. Please enter a valid integer.");
            }
            if (optionInt < 0 || optionInt > options) {
                System.err.println("Invalid option. Please choose a valid option.");
            }
        }
        return optionInt;
    }
}
