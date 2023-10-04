package Project.classes.managers.StudentGroup;

import java.util.ArrayList;

import Project.classes.mainclasses.Faculty;
import Project.classes.mainclasses.Status;
import Project.classes.mainclasses.Student;
import Project.classes.mainclasses.StudentGroup;
import Project.classes.managers.ManagerInterface;
import Project.classes.managers.Faculty.FacultyManager;
import Project.classes.utility.Reader;

public class StudentGroupManager implements ManagerInterface {
    private StudentGroup studentGroup;
    private Faculty faculty;
    private ArrayList<Faculty> faculties;

    public StudentGroupManager(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
    }

    public StudentGroupManager(ArrayList<Faculty> faculties, Faculty faculty) {
        this.faculties = faculties;
        this.faculty = faculty;
    }

    @Override
    public void addNew() {
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
            int option = Reader.safeSelect(options);
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

    @Override
    public void printAll() {
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

    @Override
    public void addNewSubordinate() {
        if (this.faculty.getGroups().isEmpty()) {
            System.err.println("There are no Groups to assign this student to.");
            return;
        } else {

            System.out.println("Student's Name: ");
            String name = Reader.readln();
            System.out.println("Student's Date of Birth: ");
            String dob = Reader.readln();
            System.out.println("Student's Date of Enrollment: ");
            String dateOfEnrollment = Reader.readln();
            Status[] statuses = { Status.ACTIVE, Status.ENROLLED, Status.ERASMUS,
                    Status.EXPELLED, Status.GRADUATED };
            for (int i = 0; i < statuses.length; i++) {
                System.out.println(Integer.toString(i + 1) + ". " + statuses[i]);
            }
            int option = Reader.safeSelect(statuses.length);
            Status status = statuses[option - 1];
            Student newStudent = new Student(name, dob, this.faculty, status,
                    dateOfEnrollment);
            choseStudentGroup.addStudent(newStudent);
            System.out.println("..........................................");
            System.out.println("Student added Successfully!");
        }

    }

    @Override
    public void printAllSubordinates() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'printAllSubordinates'");
    }

    public void selectStudentGroup() {
        if (this.faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record.");
        } else if (this.faculty == null) {
            FacultyManager facultyManager = new FacultyManager(this.faculties);
            facultyManager.selectFaculty();
            this.faculty = facultyManager.getFaculty();
        }
        if (this.faculty.getGroups().isEmpty()) {
            System.err.println("There are no Student Groups in this Faculty.");
        } else {
            System.out.println("Please choose a Student Group by index.");
            for (int i = 0; i < this.faculty.getGroups().size(); i++) {
                System.out.println(Integer.toString(i + 1) + ". " + this.faculty.getGroups().get(i).getName());
            }
            int option = Reader.safeSelect(this.faculty.getGroups().size());
            this.studentGroup = this.faculty.getGroups().get(option - 1);
        }
    }

    public StudentGroup getStudentGroup() {
        return this.studentGroup;
    }
}
