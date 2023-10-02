package Project.classes.menu;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.Faculty;
import Project.classes.StudyField;

public class FacultyMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;
    private Scanner scanner;

    public FacultyMenu(ArrayList<Faculty> faculties, Scanner scanner) {
        this.faculties = faculties;
        this.scanner = scanner;
    }

    public void displayMenu() {
        System.out.println("1. Add new Faculty.");
        System.out.println("2. Edit existing Faculty.");
        System.out.println("3. Print existing Faculties.");
        handleCommand();
    }

    public void handleCommand() {
        String command = this.scanner.nextLine();
        switch (command) {
            case "1":
                addNewFaculty();
                displayMenu();
                break;
            case "3":
                printFaculties();
                displayMenu();

        }
    }

    private void addNewFaculty() {
        System.out.println("Enter the Faculty full name: ");
        String name = this.scanner.nextLine();
        System.out.println("Enter the Group Naming for this Faculty (example Mechanical Engineering - ME): ");
        String shortName = this.scanner.nextLine();
        System.out.println("Choose the Study Field: ");
        StudyField[] fields = { StudyField.FOOD_TECHNOLOGY, StudyField.MECHANICAL_ENGINEERING,
                StudyField.SOFTWARE_ENGINEERING, StudyField.URBANISM_ARCHITECTURE, StudyField.VETERINARY_MEDICINE };
        for (int i = 0; i < fields.length; i++) {
            System.out.println(Integer.toString(i + 1) + ". " + fields[i]);
        }
        int option = this.scanner.nextInt();
        StudyField field = fields[option - 1];
        faculties.add(new Faculty(name, shortName, field));
        System.out.println("Faculty added successfuly.");
    }

    private void editFaculty() {
        if (faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record.");
            return;
        } else {
            System.out.println("Which one of the Faculties do you want to edit?");
            for (int i = 0; i < this.faculties.size(); i++) {
                System.out.println(Integer.toString(i) + ". " + this.faculties.get(i).getName());
            }
            int option = this.scanner.nextInt();
            if (option - 1 > this.faculties.size()) {
                System.err.println(
                        "There is no such Faculty in the list. Please choose a valid one or press q to return.");
            } else {
                Faculty chosenFaculty = this.faculties.get(option - 1);

            }
        }
    }

    private void printFaculties() {
        if (faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record");
        } else {
            for (Faculty faculty : faculties) {
                System.out.println(faculty.getName() + ", " + "Shortname: " + faculty.getGroupNaming()+", "+"Study Field: "+faculty.getStudyField());
            }
        }

    }
}
