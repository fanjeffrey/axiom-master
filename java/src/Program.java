
import java.io.*;
import java.lang.Thread;

public class Program {
    public static void main(String[] args) {
        runTicketSystem();
    }

    private static void runTicketSystem() {
        Station sta1 = new Station("Station #1");
        Station sta2 = new Station("Station #2");
        Station sta3 = new Station("Station #3");
        sta1.start();
        sta2.start();
        sta3.start();
    }

    private static String reverseString(String stringToReverse) {
        if (stringToReverse == null)
            return null;

        int length = stringToReverse.length();
        if (length == 0)
            return "";

        char[] chars = new char[length];

        for (int index = 0; index < length; index++)
            chars[length - index - 1] = stringToReverse.charAt(index);

        return new String(chars);
    }

    void runFactory() {
        Factory f = new Factory();
        Producer w = new Producer(f);
        w.start();
        Consumer r = new Consumer(f);
        r.start();
    }
}

class Station extends Thread {
    private static int TicketNumber = 20;
    private static Object locker = "locker";

    public Station(String name) {
        super(name);
    }

    public void run() {
        while (TicketNumber > 0) {
            sell();
            try{sleep(100);}
            catch(InterruptedException ex){
                ex.printStackTrace();
            }
        }
    }

    private void sell()    {
        if (TicketNumber <= 0)
            System.out.println(getName() + " - all tickets are sold out.");

        synchronized (locker) {
            System.out.println(getName() + " - sold out ticket #" + TicketNumber + ".");
            TicketNumber--;
        }
    }
}

abstract class Animal {
    abstract void move();

    public void eat() {
    }
}

interface Flyable {
    void fly();
}

class Bird implements Flyable {
    private boolean _isFlying;

    public void fly() {
        _isFlying = true;
    }
}

class Factory {
    private int _count = 0;

    public int getCount() {
        return _count;
    }

    public void produce() {
        synchronized (this) {
            System.out.println("Before producing - " + getCount());
            _count++;
            System.out.println("After producing - " + getCount());
            if (getCount() > 0)
                notify();
        }
    }

    public void consume() {
        synchronized (this) {
            try {
                System.out.println("Before consuming - " + getCount());

                if (getCount() <= 0) {
                    wait();
                }

                _count--;

                System.out.println("After consuming - " + getCount());

            } catch (InterruptedException ex) {
                System.out.println("Interrupted - " + ex.getMessage());
            }
        }
    }
}

class Producer extends Thread {
    private Factory _factory;

    public Producer(Factory factory) {
        _factory = factory;
    }

    public void run() {
        while (true) {
            _factory.produce();
        }
    }
}

class Consumer extends Thread {
    private Factory _factory;

    public Consumer(Factory factory) {
        _factory = factory;
    }

    public void run() {
        while (true) {
            _factory.consume();
        }
    }
}

class Echo {
    public void run() {
        System.out.println("Hello, Jeffrey.");
        System.out.println("This is an ECHO program.");

        try {
            BufferedWriter logger = new BufferedWriter(new FileWriter("session.log"));
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String input = reader.readLine();
            while (!input.contains("exit")) {
                System.out.println(input);
                logger.append(input);
                input = reader.readLine();
            }
            logger.flush();
            logger.close();
        } catch (IOException ex) {
            System.out.println("Error: " + ex.getMessage());
        }

        System.out.println("Exit...");
    }
}
