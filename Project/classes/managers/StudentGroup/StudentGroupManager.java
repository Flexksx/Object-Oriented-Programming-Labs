package Project.classes.managers.StudentGroup;

import java.util.ArrayList;

import Project.classes.mainclasses.Faculty;
import Project.classes.mainclasses.StudentGroup;
import Project.classes.managers.ManagerInterface;
import Project.classes.utility.Reader;

public class StudentGroupManager implements ManagerInterface {
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
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'addNewSubordinate'");
    }

    @Override
    public void printAllSubordinates() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'printAllSubordinates'");
    }

}
