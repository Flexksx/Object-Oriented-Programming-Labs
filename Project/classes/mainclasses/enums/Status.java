package Project.classes.mainclasses.enums;

public enum Status {
    ACTIVE("Active"),
    ENROLLED("Enrolled"),
    EXPELLED("Expelled"),
    GRADUATED("Graduated"),
    ERASMUS("On Erasmus Programme");

    private String statString;

    private Status(String statString) {
        this.statString = statString;
    }
}
