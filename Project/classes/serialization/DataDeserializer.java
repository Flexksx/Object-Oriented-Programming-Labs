package Project.classes.serialization;

import Project.classes.menu.MainMenu;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.Arrays;

public class DataDeserializer {
    public static MainMenu deserialize() {
        File serializedFile = new File("manager.ser");
        MainMenu manager = new MainMenu();
        if (serializedFile.exists()) {
            try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(serializedFile))) {
                manager = (MainMenu) ois.readObject();
                System.out.println("Supervisor object deserialized successfully.");
            } catch (ClassNotFoundException | IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Serialized file 'manager.ser' does not exist.");
        }
        return manager;
    }
}
