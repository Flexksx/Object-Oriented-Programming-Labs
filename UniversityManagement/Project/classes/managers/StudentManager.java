package UniversityManagement.Project.classes.managers;

import java.io.Serializable;
import java.util.ArrayList;

import UniversityManagement.Project.classes.mainclasses.Faculty;
import UniversityManagement.Project.classes.mainclasses.Student;
import UniversityManagement.Project.classes.mainclasses.StudentGroup;
import UniversityManagement.Project.classes.utility.Reader;

public class StudentManager implements ManagerInterface, Serializable {
    private ArrayList<Faculty> faculties;
    private Faculty faculty = null;
    private ArrayList<StudentGroup> groups;
    private StudentGroup group = null;
    private Student student = null;
    private FacultyManager facultyManager;
    private StudentGroupManager studentGroupManager;

    public StudentManager(ArrayList<Faculty> faculties, FacultyManager facultyManager,
            StudentGroupManager studentGroupManager) {
        this.faculties = faculties;
        this.facultyManager = facultyManager;
        this.studentGroupManager = studentGroupManager;
    }

    public StudentManager(ArrayList<Faculty> faculties2, Faculty faculty2, StudentGroup studentGroup) {
        this.faculties= faculties2;
        this.faculty=faculty2;
        this.group=studentGroup;
	}

	@Override
    public void addNew() {
        facultyManager.selectOne();
        this.faculty = this.facultyManager.getFaculty();
        studentGroupManager.setFaculty(this.faculty);
        studentGroupManager.selectOne();
        studentGroupManager.addNewSubordinate();
    }

    @Override
    public void printAll() {
        if (faculties.isEmpty()) {
            System.out.println("There are no faculties.");
            return;
        }
        for (Faculty faculty : faculties) {
            System.out.println("------------------------------------------");
            System.out.println("Faculty: " + faculty.getName());
            if (faculty.getGroups().isEmpty()) {
                continue;
            }
            for (StudentGroup group : faculty.getGroups()) {
                if (group.getStudents().isEmpty()) {
                    continue;
                } else {
                    System.out.println("Group: " + group.getName());
                    System.out.println("..........................................");
                    for (Student student : group.getStudents()) {
                        System.out.println(student.getName() + ", ID: " + student.getStudentID() + ", Status: "
                                + student.getStatus());
                    }
                }
            }
        }
    }

    @Override
    public void addNewSubordinate() {
        throw new UnsupportedOperationException("Unimplemented method 'addNewSubordinate'");
    }

    @Override
    public void printAllSubordinates() {
        throw new UnsupportedOperationException("Unimplemented method 'printAllSubordinates'");
    }

    @Override
    public void selectSubordinate() {
        throw new UnsupportedOperationException("Unimplemented method 'selectSubordinate'");
    }

    @Override
    public void selectOne() {
        if (this.faculty == null) {
            facultyManager.selectOne();
            this.faculty = this.facultyManager.getFaculty();
        }
        if (this.group == null) {
            studentGroupManager.setFaculty(this.faculty);
            studentGroupManager.selectOne();
            this.group = studentGroupManager.getStudentGroup();
        }
        studentGroupManager.selectSubordinate();
        this.student = studentGroupManager.getSelectedStudent();
    }

    public void findStudentById() {
        System.out.println("Please Input Student ID: ");
        String id = Reader.readln();
        int idint = Integer.parseInt(id);
        if (faculties.isEmpty()) {
            System.out.println("There are no faculties.");
            return;
        }
        for (Faculty faculty : this.faculties) {
            if (faculty.getGroups().isEmpty()) {
                continue;
            }
            for (StudentGroup group : faculty.getGroups()) {
                if (group.getStudents().isEmpty()) {
                    continue;
                } else {
                    for (Student student : group.getStudents()) {
                        if (student.getStudentID() == idint) {
                            System.out.println(student.getName() + ", ID: " + student.getStudentID() + ", Status: "
                                    + student.getStatus() + ", Faculty: " + faculty.getName() + ", Group: "
                                    + group.getName());
                            return;
                        }
                    }
                    System.out.println("Student not found.");
                }
            }
        }
    }

    public void findStudentByName() {
        System.out.println("Please Input Student Name: ");
        String name = Reader.readln();
        if (faculties.isEmpty()) {
            System.out.println("There are no faculties.");
            return;
        }
        for (Faculty faculty : this.faculties) {
            if (faculty.getGroups().isEmpty()) {
                continue;
            }
            for (StudentGroup group : faculty.getGroups()) {
                if (group.getStudents().isEmpty()) {
                    continue;
                } else {
                    for (Student student : group.getStudents()) {
                        if (student.getName().equals(name)) {
                            System.out.println(student.getName() + ", ID: " + student.getStudentID() + ", Status: "
                                    + student.getStatus() + ", Faculty: " + faculty.getName() + ", Group: "
                                    + group.getName());
                        }
                    }
                    System.out.println("Student not found.");
                }

            }
        }
    }

    public Student getStudent() {
        return student;
    }
}
