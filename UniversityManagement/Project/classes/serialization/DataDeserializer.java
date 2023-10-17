package UniversityManagement.Project.classes.serialization;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

import UniversityManagement.Project.classes.menu.MainMenu;

public class DataDeserializer {
    public static MainMenu deserialize() {
        File serializedFile = new File("Manager.ser");
        MainMenu manager = new MainMenu();
        if (serializedFile.exists()) {
            try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(serializedFile))) {
                manager = (MainMenu) ois.readObject();
                System.out.println("Object deserialized successfully.");
            } catch (ClassNotFoundException | IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Serialized file 'Manager.ser' does not exist.");
        }
        return manager;
    }
}
