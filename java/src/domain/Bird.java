package domain;

import java.io.*;
import java.util.UUID;

public class Bird extends Animal implements Flyable, Serializable {
    protected boolean isFlying;

    Bird() {
        this("unnamed");
    }

    public Bird(String name) {
        super(name);
        isFlying = false;
    }

    Bird(UUID id, String name, boolean isFlying) {
        super(id, name);
        this.isFlying = isFlying;
    }

    public void fly() {
        isFlying = true;
    }

    public void move() {
        System.out.println("moving...");
    }

    public void eat() {
        System.out.println("eating...");
    }

    public String toString() {
        return "{id: " + id + ", name: '" + name + "', isFlying: " + isFlying + "}";
    }
}