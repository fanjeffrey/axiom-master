package stream;

import java.io.*;

public class Echo {
    public static void main(String[] args) {
        System.out.println("Hello, Jeffrey.");
        System.out.println("This is an ECHO program.");

        try {
            BufferedWriter logger = new BufferedWriter(new FileWriter("session.log"));
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String input = reader.readLine();
            while (!input.startsWith(":exit")) {
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