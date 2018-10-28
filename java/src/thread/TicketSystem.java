package thread;

import java.lang.Thread;

public class TicketSystem {
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
            try {
                sleep(100);
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }

    private void sell() {
        synchronized (locker) {
            if (TicketNumber <= 0) {
                System.out.println(getName() + " - all tickets are sold out.");
                return;
            }

            System.out.println(getName() + " - sold out ticket #" + TicketNumber + ".");
            TicketNumber--;
        }
    }
}