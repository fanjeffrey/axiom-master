package string;

public class Program {
    public static void main(String[] args) {
        String oldValue = "Old Value";
        changeString(oldValue);
        System.out.println("after changing - " + oldValue);
    }

    private static void changeString(String strToChange) {
        System.out.println("before changing - " + strToChange);
        strToChange = new String("New Value");
    }
}