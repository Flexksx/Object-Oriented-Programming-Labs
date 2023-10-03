package Project;

import java.util.ArrayList;
import java.util.Scanner;

import Project.classes.*;
import Project.classes.menu.*;
public class StudentManagerMain {
    static ArrayList<Faculty> faculties = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Hello, this is a University Manager project made by Cretu Cristian as a OOP project");
        MainMenu menu = new MainMenu(faculties,scanner);
        menu.handleOption();
        scanner.close();
    }

}