package Project.classes.menu;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.Faculty;
import Project.classes.menu.FacultyMenus.FacultyMenu;

public class MainMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;
    private Scanner scanner;

    public MainMenu(ArrayList<Faculty> faculties, Scanner scanner) {
        this.faculties = faculties;
        this.scanner = scanner;
    }

    public void navigateToPrevious() {
        System.out.println("Goodbye!");
    }

    public void displayMenu() {
        System.out.println("1. Faculty Menu.");
        System.out.println("2. Student Groups Menu");
        System.out.println("3. Students Menu.");
        System.out.println("0. Quit.");
        System.out.println("==========================================");
    }

    public void mainLoop() {
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = safeSelect(4);
            switch (option) {
                case 1:
                    FacultyMenu facultyMenu = new FacultyMenu(faculties, scanner);
                    facultyMenu.mainLoop();
                    break;
                case 2:
                    System.out.println("WIP");
                    break;
                case 3:
                    System.out.println("WIP");
                    break;
                case 0:
                    navigateToPrevious();
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

    public int safeSelect(int options) {
        int optionInt = -1;
        while (optionInt < 0 || optionInt > options) {
            String option = this.scanner.nextLine();
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
