package Project.classes.menu.FacultyMenus;

import java.util.ArrayList;
import Project.classes.mainclasses.Faculty;
import Project.classes.managers.FacultyManager;
import Project.classes.managers.StudentGroupManager;
import Project.classes.menu.MenuInterface;
import Project.classes.menu.StudentGroupMenus.SelectStudentGroupMenu;
import Project.classes.utility.Reader;

public class SelectFacultyMenu implements MenuInterface {
    private ArrayList<Faculty> faculties;
    private Faculty faculty;

    public SelectFacultyMenu(ArrayList<Faculty> faculties) {
        this.faculties = faculties;

    }

    @Override
    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("What do you want to do with this Faculty?");
        System.out.println("1. Print Students.");
        System.out.println("2. Print existing Student Groups.");
        System.out.println("3. Add new Student Group.");
        System.out.println("4. Select Student Group.");
        System.out.println("0. Go back to the Previous Menu.");
        System.out.println("==========================================");
    }

    @Override
    public void mainLoop() {
        FacultyManager facultyManager = new FacultyManager(this.faculties);
        facultyManager.selectOne();
        this.faculty = facultyManager.getFaculty();
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = Reader.safeSelect(6);
            switch (option) {
                case 1:
                    this.faculty.printStudentsbyName();
                    break;
                case 2:
                    facultyManager.printAllSubordinates();
                    break;
                case 3:
                    facultyManager.addNewSubordinate();
                    break;
                case 4:
                    navigateToStudentGroup();
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

    private void navigateToStudentGroup() {
        StudentGroupManager studentGroupManager = new StudentGroupManager(this.faculties, this.faculty);
        SelectStudentGroupMenu selectStudentGroupMenu = new SelectStudentGroupMenu(this.faculties, studentGroupManager);
        selectStudentGroupMenu.mainLoop();
    }
}