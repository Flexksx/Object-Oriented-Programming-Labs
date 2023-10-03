package Project.classes.menu;

import java.util.Scanner;

public interface MenuInterface {
    void displayMenu();

    void switchOption();

    int safeSelect(int options);
}
