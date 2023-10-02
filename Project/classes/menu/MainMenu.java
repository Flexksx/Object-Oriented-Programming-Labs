package Project.classes.menu;

import java.util.Scanner;

public class MainMenu implements MenuInterface {
    public void displayMenu() {
        System.out.println("1. Faculty Menu.");
        System.out.println("2. Student Groups Menu");
        System.out.println("3. Students Menu.");
    }

    public void handleCommand() {
        try (Scanner scanner = new Scanner(System.in)) {
            int command = scanner.nextInt();
            switch(command){
                case 1:

            }
        }
    }
}
