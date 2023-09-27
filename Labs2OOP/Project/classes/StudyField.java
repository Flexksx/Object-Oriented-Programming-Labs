package Project.classes;

public enum StudyField {
    MECHANICAL_ENGINEERING("Mechanical Engineering"),
    SOFTWARE_ENGINEERING("Software Engineering"),
    FOOD_TECHNOLOGY("Food Technology"),
    URBANISM_ARCHITECTURE("Urbanism and Architecture"),
    VETERINARY_MEDICINE("Veterinary Medicine");

    private final String name;

    StudyField(String name){
        this.name=name;
    }
}
