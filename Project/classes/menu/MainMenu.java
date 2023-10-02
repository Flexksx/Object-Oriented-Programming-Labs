package Project.classes.menu;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.Faculty;

public class MainMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;
    private Scanner scanner = new Scanner(System.in);

    public MainMenu(ArrayList<Faculty> faculties, Scanner scanner) {
        this.faculties = faculties;
        this.scanner = scanner;
    }
    public void navigateToPrevious(){
        System.out.println("Goodbye!");
    }
    public void displayMenu() {
        System.out.println("1. Faculty Menu.");
        System.out.println("2. Student Groups Menu");
        System.out.println("3. Students Menu.");
        System.err.println("===========================");

        handleCommand();
    }

    public void handleCommand() {
        String command = this.scanner.nextLine();
        switch (command) {
            case "1":
                FacultyMenu facultyMenu = new FacultyMenu(faculties, scanner,this);
                facultyMenu.displayMenu();
                break;
            case "q":
                navigateToPrevious();
                break;
        }
    }
}
