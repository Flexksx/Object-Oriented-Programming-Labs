package Project.classes.menu.FacultyMenus;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.Faculty;
import Project.classes.Student;
import Project.classes.StudentGroup;
import Project.classes.menu.MenuInterface;

public class FacultyEditMenu implements MenuInterface {
    private Faculty faculty;
    private Scanner scanner;

    public FacultyEditMenu(Faculty faculty, Scanner scanner) {
        this.faculty = faculty;
        this.scanner = scanner;
    }

    @Override
    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("What do you want to do with this Faculty?");
        System.out.println("1. Print its' Students by Name.");
        System.out.println("2. Print its' Students by ID.");
        System.out.println("3. Print existing Student Groups.");
        System.out.println("4. Add new Student Group.");
        System.out.println("5. Add new Student.");
        System.out.println("0. Go back to the Previous Menu.");
        System.out.println("==========================================");
    }

    @Override
    public void mainLoop() {
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = safeSelect(6);
            switch (option) {
                case 1:
                    this.faculty.printStudentsbyName();
                    break;
                case 2:
                    this.faculty.printStudentsbyID();
                    break;
                case 3:
                    this.faculty.printStudentGroups();
                    break;
                case 4:
                    addNewStudentGroup();
                    break;
                case 5:
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

    public void addNewStudentGroup() {
        System.out.println("What is the number of the New Group?");
        String number = this.scanner.nextLine();
        if (this.faculty.getGroups().isEmpty()) {
            this.faculty.addNewGroup(number);
            System.out.println(".................................");
            System.out.println("Student group added successfully.");
            return;
        } else {
            String groupName = this.faculty.getGroupNaming() + "-" + number;
            for (StudentGroup group : this.faculty.getGroups()){
                if(group.getName().equals(groupName)){
                    System.err.println("...................................................");
                    System.err.println("Group "+groupName+" already exists in this Faculty.");
                    return;
                }
            }
            this.faculty.addNewGroup(number);
            System.out.println(".................................");
            System.out.println("Student group added successfully.");
        }
    }
}
