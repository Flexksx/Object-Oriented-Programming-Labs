package Project.classes.mainclasses.enums;

public enum Status {
    ACTIVE("Active"),
    ENROLLED("Enrolled"),
    EXPELLED("Expelled"),
    GRADUATED("Graduated"),
    EXCHANGE("On Exchange Programme");

    private String statString;

    private Status(String statString) {
        this.statString = statString;
    }
}
