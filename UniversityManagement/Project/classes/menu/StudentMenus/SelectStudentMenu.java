package UniversityManagement.Project.classes.menu.StudentMenus;

import java.io.Serializable;

import UniversityManagement.Project.classes.mainclasses.Student;
import UniversityManagement.Project.classes.mainclasses.enums.Status;
import UniversityManagement.Project.classes.menu.MenuInterface;
import UniversityManagement.Project.classes.utility.Reader;

public class SelectStudentMenu implements MenuInterface,Serializable {
    private Student student;
    public SelectStudentMenu(Student student) {
        this.student = student;
    }
    @Override
    public void displayMenu() {
        System.out.println("==========================================");
        System.out.println("1. Graduate Student.");
        System.out.println("2. Expel Student.");
        System.out.println("3. Change Student Status to Active.");
        System.out.println("4. Change Student Status to Exchange.");
        System.out.println("5. Change Student Status to Enrolled.");
        System.out.println("0. Go back to the previous Menu.");
        System.out.println("==========================================");
    }

    @Override
    public void mainLoop() {
        int option = -1;
        while (!(option == 0)) {
            displayMenu();
            option = Reader.safeSelect(4);
            switch (option) {
                case 1:
                    this.student.setStatus(Status.GRADUATED);
                    break;
                case 2:
                    this.student.setStatus(Status.EXPELLED);
                    break;
                case 3:
                    this.student.setStatus(Status.ACTIVE);
                    break;
                case 4:
                    this.student.setStatus(Status.EXCHANGE);
                    break;
                case 5:
                    this.student.setStatus(Status.ENROLLED);
                    break;
                case 0:
                    return;
                default:
                    System.err.println("Invalid option. Please choose a valid option.");
            }
        }
    }

}
