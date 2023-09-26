package Project.Classes;

import java.util.ArrayList;

public class Faculty {
    private String Name;
    private String ShortName;
    private ArrayList<Speciality> Specialties = new ArrayList<Speciality>();
    public Faculty(String name, String shortname, ArrayList<Speciality> specialties){
        this.Name=name;
        this.ShortName=shortname;
        this.Specialties=specialties;
    }
    public Faculty(String name, String shortname){
        this.Name=name;
        this.ShortName=shortname;
    }

    public void addSpeciality(Speciality spec){
        this.Specialties.add(spec);
    }

    public void addNewSpeciality(String name, String shortname){
        this.Specialties.add(new Speciality(name, shortname));
    }
    public void addNewSpeciality(String name, String shortname, ArrayList<StudentGroup> groups){
        this.Specialties.add(new Speciality(name, shortname, groups));
    }
    public String getName() {
        return Name;
    }
    public String getShortName() {
        return ShortName;
    }
    public ArrayList<Speciality> getSpecialties() {
        return Specialties;
    }
    public void setName(String name) {
        Name = name;
    }
    public void setShortName(String shortName) {
        ShortName = shortName;
    }
    public void setSpecialties(ArrayList<Speciality> specialties) {
        Specialties = specialties;
    }
}
