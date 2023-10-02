package Project.classes.menu;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.Faculty;

public class MainMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;
    private Scanner scanner = new Scanner(System.in);

    public void mainLoop() {
        String option = this.scanner.nextLine();
        while (option != "q") {
            displayMenu();
        }
    }

    public MainMenu(ArrayList<Faculty> faculties, Scanner scanner) {
        this.faculties = faculties;
        this.scanner = scanner;
    }

    public void navigateToPrevious() {
        return;
    }

    public void displayMenu() {
        System.out.println("1. Faculty Menu.");
        System.out.println("2. Student Groups Menu");
        System.out.println("3. Students Menu.");
        System.out.println("q. Quit.");
        System.err.println("===========================");
        handleOption();
    }

    public void handleOption() {
        String option = this.scanner.nextLine();
        switch (option) {
            case "1":
                FacultyMenu facultyMenu = new FacultyMenu(faculties, scanner, this);
                facultyMenu.displayMenu();
                break;
            case "q":
                navigateToPrevious();
                break;
        }
    }
}
