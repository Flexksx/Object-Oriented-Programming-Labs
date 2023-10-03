package Project.classes.menu.FacultyMenus;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.Faculty;
import Project.classes.StudyField;
import Project.classes.menu.MenuInterface;

public class FacultyMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;
    private MenuInterface previousMenu;
    private Scanner scanner;

    public FacultyMenu(ArrayList<Faculty> faculties, MenuInterface previous, Scanner scanner) {
        this.faculties = faculties;
        this.previousMenu = previous;
        this.scanner = scanner;
    }

    public void navigateToPrevious() {
        previousMenu.switchOption();
    }

    public void displayMenu() {
        System.out.println("===========================");
        System.out.println("1. Add new Faculty.");
        System.out.println("2. Select existing Faculty.");
        System.out.println("3. Print existing Faculties.");
        System.out.println("0. Go back to the previous Menu.");
        System.out.println("===========================");
    }

    public void switchOption() {
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = safeSelect(4);
            switch (option) {
                case 1:
                    addNewFaculty();
                    break;
                case 2:
                    editFaculty();
                    break;
                case 3:
                    printFaculties();
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

    private void addNewFaculty() {
        System.out.println("Enter the Faculty full name: ");
        String name = this.scanner.nextLine();
        System.out.println("Enter the Group Naming for this Faculty (example Mechanical Engineering - ME): ");
        String shortName = this.scanner.nextLine();
        System.out.println("Choose the Study Field: ");
        StudyField[] fields = { StudyField.FOOD_TECHNOLOGY,
                StudyField.MECHANICAL_ENGINEERING,
                StudyField.SOFTWARE_ENGINEERING,
                StudyField.URBANISM_ARCHITECTURE,
                StudyField.VETERINARY_MEDICINE };
        for (int i = 0; i < fields.length; i++) {
            System.out.println(Integer.toString(i + 1) + ". " + fields[i]);
        }
        int option = safeSelect(fields.length - 1);
        StudyField field = fields[option - 1];
        this.faculties.add(new Faculty(name, shortName, field));
        System.out.println("---------------------------");
        System.out.println("Faculty added successfuly.");
        System.out.println("---------------------------");
    }

    private void editFaculty() {
        if (faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record.");
            return;
        } else {
            System.out.println("Which one of the Faculties do you want to edit?");
            for (int i = 0; i < this.faculties.size(); i++) {
                System.out.println(Integer.toString(i+1) + ". " + this.faculties.get(i).getName());
            }
            int option = safeSelect(this.faculties.size());
            Faculty chosenFaculty = this.faculties.get(option - 1);
            FacultyEditMenu facEditMenu = new FacultyEditMenu(chosenFaculty, scanner,this);
            facEditMenu.switchOption();
        }
    }

    private void printFaculties() {
        if (faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record");
        } else {
            for (Faculty faculty : faculties) {
                System.out.println(faculty.getName() + ", " + "Shortname: " + faculty.getGroupNaming() + ", "
                        + "Study Field: " + faculty.getStudyField());
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
