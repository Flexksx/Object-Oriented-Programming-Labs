package UniversityManagement.Project.classes.utility;

import java.util.Scanner;

public class Reader {
    private static Scanner scanner = new Scanner(System.in);
    public static void close(){
        scanner.close();
    }
    public static String readln(){
        return scanner.nextLine();
    }
    public static int safeSelect(int options) {
        int optionInt = -1;
        while (optionInt < 0 || optionInt > options) {
            String option = scanner.nextLine();
            try {
                optionInt = Integer.parseInt(option);
            } catch (NumberFormatException e) {
                System.err.println("Invalid input. Please enter a valid integer.");
            }
            if (optionInt < 0 || optionInt > options) {
                System.err.println("Invalid option. Please choose a valid option.");
            }
        }
        return optionInt;
    }
}
