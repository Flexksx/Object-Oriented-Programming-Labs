package Project.classes.menu.FacultyMenus;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.mainclasses.Faculty;
import Project.classes.mainclasses.Status;
import Project.classes.mainclasses.Student;
import Project.classes.mainclasses.StudentGroup;
import Project.classes.menu.MenuInterface;
import Project.classes.utility.Reader;

public class FacultyEditMenu implements MenuInterface {
    private Faculty faculty;

    public FacultyEditMenu(Faculty faculty) {
        this.faculty = faculty;
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
                    addNewStudent();
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

    public void addNewStudentGroup() {

    }

    public void addNewStudent() {
        if (this.faculty.getGroups().isEmpty()) {
            System.err.println("There are no Groups to assign this student to.");
            return;
        } else {
            System.out.println("Choose a Group to add this student to:");
            for (int i = 0; i < this.faculty.getGroups().size(); i++) {
                System.out.println(Integer.toString(i + 1) + ". " + this.faculty.getGroups().get(i).getName());
            }
            int options = this.faculty.getGroups().size();
            int option = safeSelect(options);
            StudentGroup choseStudentGroup = this.faculty.getGroups().get(option - 1);
            System.out.println("Student's Name: ");
            String name = Reader.readln();
            System.out.println("Student's Date of Birth: ");
            String dob = Reader.readln();
            System.out.println("Student's Date of Enrollment: ");
            String dateOfEnrollment = Reader.readln();
            Status[] statuses = { Status.ACTIVE, Status.ENROLLED, Status.ERASMUS, Status.EXPELLED, Status.GRADUATED };
            for (int i = 0; i < statuses.length; i++) {
                System.out.println(Integer.toString(i + 1) + ". " + statuses[i]);
            }
            options = statuses.length;
            option = safeSelect(options);
            Status status = statuses[option - 1];
            Student newStudent = new Student(name, dob, this.faculty, status, dateOfEnrollment);
            choseStudentGroup.addStudent(newStudent);
            System.out.println("..........................................");
            System.out.println("Student added Successfully!");
        }
    }
}
