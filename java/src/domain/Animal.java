package domain;

import java.io.*;
import java.util.UUID;

public abstract class Animal implements Serializable {
    protected UUID id;
    protected String name;

    Animal(String name) {
        this(UUID.randomUUID(), name);
    }

    Animal(UUID id, String name) {
        this.id = id;
        this.name = name;
    }

    public abstract void move();

    public abstract void eat();
}