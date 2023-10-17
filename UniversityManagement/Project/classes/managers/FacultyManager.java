package UniversityManagement.Project.classes.managers;

import java.io.Serializable;
import java.util.ArrayList;

import UniversityManagement.Project.classes.mainclasses.Faculty;
import UniversityManagement.Project.classes.mainclasses.StudentGroup;
import UniversityManagement.Project.classes.mainclasses.enums.StudyField;
import UniversityManagement.Project.classes.utility.Reader;

public class FacultyManager implements ManagerInterface,Serializable {
    private ArrayList<Faculty> faculties;
    private Faculty faculty = null;

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
        if (this.faculty == null) {
            return;
        } else {
            System.out.println("What is the number of the New Group?");
            String number = Reader.readln();
            if (this.faculty.getGroups().isEmpty()) {
                this.faculty.addNewGroup(number);
                System.out.println("..........................................");
                System.out.println("Student group added successfully.");
                return;
            } else {
                String groupName = this.faculty.getGroupNaming() + "-" + number;
                for (StudentGroup group : this.faculty.getGroups()) {
                    if (group.getName().equals(groupName)) {
                        System.out.println("..........................................");
                        System.err.println("Group " + groupName + " already exists in this Faculty.");
                        return;
                    }
                }
                this.faculty.addNewGroup(number);
                System.out.println("..........................................");
                System.out.println("Student group added successfully.");
            }
        }
    }

    @Override
    public void printAllSubordinates() {
        if (this.faculty.getGroups().isEmpty()) {
            System.err.println("This Faculty has no Student Groups.");
        } else {
            System.out.println("Student Groups in " + this.faculty.getName() + ":");
            for (StudentGroup group : this.faculty.getGroups()) {
                System.out.println(group.getName());
            }
        }
    }

    public void selectOne() {
        if (faculties.isEmpty()) {
            System.err.println("There are no Faculties in the record.");
            return;
        } else {
            System.out.println("Which one of the Faculties do you want to select?");
            for (int i = 0; i < this.faculties.size(); i++) {
                System.out.println(Integer.toString(i + 1) + ". " + this.faculties.get(i).getName());
            }
            int option = Reader.safeSelect(this.faculties.size());
            this.faculty = this.faculties.get(option - 1);
        }
    }

    public Faculty getFaculty() {
        return this.faculty;
    }

    @Override
    public void selectSubordinate() {
        if (this.faculty.getGroups().isEmpty()) {
            System.err.println("This Faculty has no Student Groups");
            return;
        }
        for (StudentGroup group : this.faculty.getGroups()) {

        }
    }
}
