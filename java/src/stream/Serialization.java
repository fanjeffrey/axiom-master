package stream;

import java.io.*;
import domain.*;

public class Serialization {
    public static void main(String[] args) {
        serializeBird();
        deserializeBird();
    }

    private static void deserializeBird() {
        Bird bird;
        try {
            FileInputStream fis = new FileInputStream("birds.log");
            ObjectInputStream ois = new ObjectInputStream(fis);
            bird = (Bird) ois.readObject();
            System.out.println(bird.toString());
            ois.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    private static void serializeBird() {
        Bird bird = new Bird("twitter");
        try {
            FileOutputStream fos = new FileOutputStream("birds.log");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(bird);
            oos.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}