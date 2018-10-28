package thread;

import java.lang.Thread;

public class Factory {
    public static void main(String[] args) {
        runProductLine();
    }

    static void runProductLine() {
        ProductLine pl = new ProductLine();
        Producer w = new Producer(pl);
        w.start();
        Consumer r = new Consumer(pl);
        r.start();
    }
}

class ProductLine {
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
    private ProductLine _productLine;

    public Producer(ProductLine productLine) {
        _productLine = productLine;
    }

    public void run() {
        while (true) {
            _productLine.produce();
        }
    }
}

class Consumer extends Thread {
    private ProductLine _productLine;

    public Consumer(ProductLine productLine) {
        _productLine = productLine;
    }

    public void run() {
        while (true) {
            _productLine.consume();
        }
    }
}