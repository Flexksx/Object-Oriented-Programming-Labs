package Project.classes.serialization;

import Project.classes.menu.MainMenu;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class DataSerializer {
    public static void serialize(MainMenu manager) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("manager.ser"))) {
            oos.writeObject(manager);
            System.out.println("Supervisor object serialized successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
