
import java.io.*;
import java.lang.Thread;

public class Program {
    public static void main(String[] args) {
        // new Echo().run();
        Factory f = new Factory();
        Producer w = new Producer(f);
        w.start();
        Consumer r = new Consumer(f);
        r.start();
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
