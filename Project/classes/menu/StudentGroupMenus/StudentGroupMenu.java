package Project.classes.menu.StudentGroupMenus;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.mainclasses.Faculty;
import Project.classes.mainclasses.StudentGroup;
import Project.classes.menu.MenuInterface;
import Project.classes.utility.Reader;

public class StudentGroupMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;

    public StudentGroupMenu(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
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
                    addNewGroup();
                    break;
                case 2:
                    EditStudentGroupMenu editStudentGroupMenu = new EditStudentGroupMenu(faculties, scanner);
                    break;
                case 3:
                    printStudentGroups();
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

    private void addNewGroup() {
        if (this.faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record to add a Group.");
            System.err.println("Please go to the Faculty Menu and add one.");
        } else {
            for (Faculty faculty : this.faculties) {
                System.out.println("Choose a Faculty to add this group to: ");
                System.out.println((this.faculties.indexOf(faculty) + 1) + faculty.getName() + ", " + "Shortname: "
                        + faculty.getGroupNaming() + ", "
                        + "Study Field: " + faculty.getStudyField());
            }
            int options = this.faculties.size();
            int option = safeSelect(options);
            Faculty chosenFaculty = this.faculties.get(option - 1);
            if (chosenFaculty.getGroups().isEmpty()) {
                System.out.println("Please give the group number: ");
                String number = Reader.readln();
                chosenFaculty.addNewGroup(number);
                System.out.println("..........................................");
                System.out.println("Student group added successfully.");
            } else {
                System.out.println("Please give the group number: ");
                String number = Reader.readln();
                for (StudentGroup group : chosenFaculty.getGroups()) {
                    if (chosenFaculty.getGroupNaming() + "-" + number == group.getName()) {
                        System.err.println("This group already exists in this Faculty.");
                        return;
                    }
                }
                chosenFaculty.addNewGroup(number);
                System.out.println("..........................................");
                System.out.println("Student group added successfully.");
            }
        }
    }

    public void printStudentGroups() {
        if (this.faculties.isEmpty()) {
            System.out.println("There are no Faculties or Student Groups.");
        } else {
            for (Faculty faculty : this.faculties) {
                System.out.println("..........................................");
                System.out.println("Faculty " + faculty.getName());
                if (faculty.getGroups().isEmpty()) {
                    System.out.print(" has no groups.");
                } else {
                    System.out.println(". . . . . . . . . . . . . . . . . . . . . ");
                    for (StudentGroup studentGroup : faculty.getGroups()) {
                        System.out.println(studentGroup.getName());
                    }
                }

            }
        }
    }
}
