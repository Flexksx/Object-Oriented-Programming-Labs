package Project.classes.menu.FacultyMenus;

import java.util.ArrayList;
import Project.classes.mainclasses.Faculty;
import Project.classes.managers.Faculty.FacultyManager;
import Project.classes.menu.MenuInterface;
import Project.classes.utility.Reader;

public class FacultyEditMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;

    public FacultyEditMenu(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
    }

    @Override
    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("What do you want to do with this Faculty?");
        System.out.println("1. Print its' Students by Name.");
        System.out.println("2. Print its' Students by ID.");
        System.out.println("3. Print existing Student Groups.");
        System.out.println("4. Add new Student Group.");
        System.out.println("5. Select Student Group.");
        System.out.println("0. Go back to the Previous Menu.");
        System.out.println("==========================================");
    }

    @Override
    public void mainLoop() {
        FacultyManager facultyManager = new FacultyManager(this.faculties);
        facultyManager.selectFaculty();
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = Reader.safeSelect(6);
            switch (option) {
                case 1:
                    facultyManager.getFaculty().printStudentsbyName();
                    break;
                case 2:
                    facultyManager.getFaculty().printStudentsbyID();
                    break;
                case 3:
                    facultyManager.printAllSubordinates();
                    break;
                case 4:
                    facultyManager.addNewSubordinate();
                    break;
                case 5:
                    facultyManager.selectStudentGroup();
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }
}

// public void addNewStudent() {
// if (this.faculty.getGroups().isEmpty()) {
// System.err.println("There are no Groups to assign this student to.");
// return;
// } else {
// System.out.println("Choose a Group to add this student to:");
// for (int i = 0; i < this.faculty.getGroups().size(); i++) {
// System.out.println(Integer.toString(i + 1) + ". " +
// this.faculty.getGroups().get(i).getName());
// }
// int options = this.faculty.getGroups().size();
// int option = Reader.safeSelect(options);
// StudentGroup choseStudentGroup = this.faculty.getGroups().get(option - 1);
// System.out.println("Student's Name: ");
// String name = Reader.readln();
// System.out.println("Student's Date of Birth: ");
// String dob = Reader.readln();
// System.out.println("Student's Date of Enrollment: ");
// String dateOfEnrollment = Reader.readln();
// Status[] statuses = { Status.ACTIVE, Status.ENROLLED, Status.ERASMUS,
// Status.EXPELLED, Status.GRADUATED };
// for (int i = 0; i < statuses.length; i++) {
// System.out.println(Integer.toString(i + 1) + ". " + statuses[i]);
// }
// options = statuses.length;
// option = Reader.safeSelect(options);
// Status status = statuses[option - 1];
// Student newStudent = new Student(name, dob, this.faculty, status,
// dateOfEnrollment);
// choseStudentGroup.addStudent(newStudent);
// System.out.println("..........................................");
// System.out.println("Student added Successfully!");
// }
// }
// }
