package Project.classes.managers;

import java.util.ArrayList;

import Project.classes.mainclasses.Faculty;
import Project.classes.mainclasses.Student;
import Project.classes.mainclasses.StudentGroup;
import Project.classes.mainclasses.enums.Status;
import Project.classes.utility.Reader;

public class StudentGroupManager implements ManagerInterface {
    private StudentGroup studentGroup;
    private Faculty faculty;
    private ArrayList<Faculty> faculties;
    private Student selectedStudent;

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
            FacultyManager facultyManager = new FacultyManager(faculties);
            facultyManager.selectOne();
            Faculty chosenFaculty = facultyManager.getFaculty();
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
                    if ((chosenFaculty.getGroupNaming() + "-" + number).equals(group.getName())) {
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
            Status[] statuses = { Status.ACTIVE, Status.ENROLLED, Status.EXCHANGE,
                    Status.EXPELLED, Status.GRADUATED };
            for (int i = 0; i < statuses.length; i++) {
                System.out.println(Integer.toString(i + 1) + ". " + statuses[i]);
            }
            int option = Reader.safeSelect(statuses.length);
            Status status = statuses[option - 1];
            Student newStudent = new Student(name, dob, this.faculty, status,
                    dateOfEnrollment);
            this.studentGroup.addStudent(newStudent);
            System.out.println("..........................................");
            System.out.println("Student added Successfully!");
        }

    }

    @Override
    public void printAllSubordinates() {
        if (this.studentGroup.getStudents().isEmpty()) {
            System.err.println("There are no Students in this Group.");
        }
        for (Student student : this.studentGroup.getStudents()) {
            System.out.println(
                    student.getName() + ", ID: " + student.getStudentID() + ", Status: " + student.getStatus());
        }
    }

    @Override
    public void selectOne() {
        if (this.faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record.");
            return;
        } else if (this.faculty == null) {
            FacultyManager facultyManager = new FacultyManager(this.faculties);
            facultyManager.selectOne();
            this.faculty = facultyManager.getFaculty();
        }
        if (this.faculty.getGroups().isEmpty()) {
            System.err.println("There are no Student Groups in this Faculty.");
            return;
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

    @Override
    public void selectSubordinate() {
        if (this.studentGroup.getStudents().isEmpty()) {
            System.err.println("There are no Students in this Group.");
            return;
        }

        System.out.println("Please choose a Student by index:");
        for (int i = 0; i < this.studentGroup.getStudents().size(); i++) {
            Student student = this.studentGroup.getStudents().get(i);
            System.out.println(Integer.toString(i + 1) + ". " + student.getName() + ", ID: " + student.getStudentID());
        }

        int option = Reader.safeSelect(this.studentGroup.getStudents().size());
        this.selectedStudent = this.studentGroup.getStudents().get(option - 1);
    }

    public void moveStudentToAnotherGroup() {
        if (this.studentGroup.getStudents().isEmpty()) {
            System.err.println("There are no Students in this Group.");
            return;
        }

        System.out.println("Please choose a Student to move by index:");
        for (int i = 0; i < this.studentGroup.getStudents().size(); i++) {
            Student student = this.studentGroup.getStudents().get(i);
            System.out.println(Integer.toString(i + 1) + ". " + student.getName() + ", ID: " + student.getStudentID());
        }

        int studentIndex = Reader.safeSelect(this.studentGroup.getStudents().size());
        Student studentToMove = this.studentGroup.getStudents().get(studentIndex - 1);

        System.out.println("Please choose a target Student Group by index:");
        for (int i = 0; i < this.faculty.getGroups().size(); i++) {
            StudentGroup targetGroup = this.faculty.getGroups().get(i);
            System.out.println(Integer.toString(i + 1) + ". " + targetGroup.getName());
        }

        int groupIndex = Reader.safeSelect(this.faculty.getGroups().size());
        StudentGroup targetGroup = this.faculty.getGroups().get(groupIndex - 1);

        if (targetGroup.getStudents().contains(studentToMove)) {
            System.err.println("The student is already in the target group.");
            return;
        }

        boolean removed = this.studentGroup.removeStudent(studentToMove);
        if (removed) {
            targetGroup.addStudent(studentToMove);
            System.out.println("Student moved successfully to the target group.");
        } else {
            System.err.println("Failed to move the student to the target group.");
        }
    }

    public void setStudentGroup(StudentGroup studentGroup) {
        this.studentGroup = studentGroup;
    }

    public Faculty getFaculty() {
        return faculty;
    }

    public void setFaculty(Faculty faculty) {
        this.faculty = faculty;
    }

    public ArrayList<Faculty> getFaculties() {
        return faculties;
    }

    public void setFaculties(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
    }

    public Student getSelectedStudent() {
        return selectedStudent;
    }

    public void setSelectedStudent(Student selectedStudent) {
        this.selectedStudent = selectedStudent;
    }

    public StudentGroup getGroup() {
        return this.studentGroup;
    }

}
