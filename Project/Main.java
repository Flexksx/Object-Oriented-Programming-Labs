package Project;

import java.util.ArrayList;
import Project.classes.mainclasses.Faculty;
import Project.classes.menu.*;

public class Main {
    static ArrayList<Faculty> faculties = new ArrayList<>();

    public static void main(String[] args) {
        System.out.println("Hello, this is a University Manager project made by Cretu Cristian as a OOP project");
        MainMenu menu = new MainMenu(faculties);
        menu.mainLoop();
    }
}