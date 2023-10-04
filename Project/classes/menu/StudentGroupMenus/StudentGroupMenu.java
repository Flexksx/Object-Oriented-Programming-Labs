package Project.classes.menu.StudentGroupMenus;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.Faculty;
import Project.classes.StudentGroup;
import Project.classes.menu.MenuInterface;

public class StudentGroupMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;
    private Scanner scanner;

    public StudentGroupMenu(ArrayList<Faculty> faculties, Scanner scanner) {
        this.faculties = faculties;
        this.scanner = scanner;
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
            option = safeSelect(4);
            switch (option) {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

    @Override
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

    private void addNewGroup() {
        if (this.faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record to add a Group.");
            System.err.println("Please go to the Faculty Menu and add one.");
        } else {
            for (Faculty faculty : this.faculties) {
                System.out.println("Choose a Faculty to add this group to: ");
                System.out.println(this.faculties.indexOf(faculty) + faculty.getName() + ", " + "Shortname: "
                        + faculty.getGroupNaming() + ", "
                        + "Study Field: " + faculty.getStudyField());
            }
            int options = this.faculties.size();
            int option = safeSelect(options);
            Faculty chosenFaculty = this.faculties.get(option - 1);
            if (chosenFaculty.getGroups().isEmpty()) {
                System.out.println("Please give the group number: ");
                String number = this.scanner.nextLine();
                chosenFaculty.addNewGroup(number);
            } else {
                System.out.println("Please give the group number: ");
                String number = this.scanner.nextLine();
                for (StudentGroup group : chosenFaculty.getGroups()) {

                }
                }
            }
        }
    }
}
