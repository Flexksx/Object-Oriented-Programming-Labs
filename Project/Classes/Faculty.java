package Project.Classes;

import java.util.ArrayList;

public class Faculty {
    private String name;
    private String shortName;
    // TODO lowercase
    private ArrayList<Speciality> specialities = new ArrayList<>();

    // TODO
//    private FieldStudy fieldStudy;

    public Faculty(String name, String shortname, ArrayList<Speciality> specialties){
        this.name =name;
        this.shortName =shortname;
        this.specialities =specialties;
    }
    public Faculty(String name, String shortname){
        this.name =name;
        this.shortName =shortname;
    }

    public void addSpeciality(Speciality spec){
        this.specialities.add(spec);
    }

    public void addNewSpeciality(String name, String shortname){
        this.specialities.add(new Speciality(name, shortname));
    }
    public void addNewSpeciality(String name, String shortname, ArrayList<StudentGroup> groups){
        this.specialities.add(new Speciality(name, shortname, groups));
    }
    public String getName() {
        return name;
    }
    public String getShortName() {
        return shortName;
    }
    public ArrayList<Speciality> getSpecialities() {
        return specialities;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setShortName(String shortName) {
        this.shortName = shortName;
    }
    public void setSpecialities(ArrayList<Speciality> specialities) {
        this.specialities = specialities;
    }

    public Speciality getSpecialityByShortName(String shname){
        for (Speciality specialty : this.specialities) {
            if (shname.equals(specialty.getGroupNaming())) {
                return specialty;
            }
        }
        return null;
    }
}
