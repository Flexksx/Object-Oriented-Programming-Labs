package Labs2OOP.Project.classes.mainclasses.enums;

import java.io.Serializable;

public enum Status implements Serializable{
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
