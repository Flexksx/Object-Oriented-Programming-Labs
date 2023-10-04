package Project;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.*;
import Project.classes.mainclasses.Faculty;
import Project.classes.menu.*;
import Project.classes.utility.Reader;

public class StudentManagerMain {
    static ArrayList<Faculty> faculties = new ArrayList<>();

    public static void main(String[] args) {
        Reader reader = new Reader();
        System.out.println("Hello, this is a University Manager project made by Cretu Cristian as a OOP project");
        MainMenu menu = new MainMenu(faculties);
        menu.mainLoop();
        reader.close();
    }
}