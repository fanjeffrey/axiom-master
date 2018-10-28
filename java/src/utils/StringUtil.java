package utils;

public class StringUtil {
    public static String reverseString(String stringToReverse) {
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
}