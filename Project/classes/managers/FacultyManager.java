package Project.classes.managers;

import java.util.ArrayList;
import Project.classes.mainclasses.Faculty;
import Project.classes.mainclasses.StudentGroup;
import Project.classes.mainclasses.StudyField;
import Project.classes.utility.Reader;

public class FacultyManager implements ManagerAbstractClass {
    private ArrayList<Faculty> faculties;

    public FacultyManager(ArrayList<Faculty> faculties) {
        this.faculties = faculties;
    }

    @Override
    public void addNew() {
        System.out.println("Enter the Faculty full name: ");
        String name = Reader.readln();
        System.out.println("Enter the Group Naming for this Faculty (example Mechanical Engineering - ME): ");
        String shortName = Reader.readln();
        System.out.println("Choose the Study Field: ");
        StudyField[] fields = { StudyField.FOOD_TECHNOLOGY,
                StudyField.MECHANICAL_ENGINEERING,
                StudyField.SOFTWARE_ENGINEERING,
                StudyField.URBANISM_ARCHITECTURE,
                StudyField.VETERINARY_MEDICINE };
        for (int i = 0; i < fields.length; i++) {
            System.out.println(Integer.toString(i + 1) + ". " + fields[i]);
        }
        int option = Reader.safeSelect(fields.length - 1);
        StudyField field = fields[option - 1];
        this.faculties.add(new Faculty(name, shortName, field));
        System.out.println("..........................................");
        System.out.println("Faculty added successfuly.");
    }

    @Override
    public void printAll() {
        if (faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record");
        } else {
            for (Faculty faculty : faculties) {
                System.out.println(faculty.getName() + ", " + "Shortname: " + faculty.getGroupNaming() + ", "
                        + "Study Field: " + faculty.getStudyField());
            }
        }
    }

    @Override
    public void addNewSubordinate() {
        System.out.println("What is the number of the New Group?");
        String number = Reader.readln();
        if (faculty.getGroups().isEmpty()) {
            faculty.addNewGroup(number);
            System.out.println("..........................................");
            System.out.println("Student group added successfully.");
            return;
        } else {
            String groupName = faculty.getGroupNaming() + "-" + number;
            for (StudentGroup group : faculty.getGroups()) {
                if (group.getName().equals(groupName)) {
                    System.out.println("..........................................");
                    System.err.println("Group " + groupName + " already exists in this Faculty.");
                    return;
                }
            }
            faculty.addNewGroup(number);
            System.out.println("..........................................");
            System.out.println("Student group added successfully.");
        }
    }

    @Override
    public void printAllSubordinates() {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'printAllSubordinates'");
    }
}
