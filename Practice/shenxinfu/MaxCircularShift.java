import java.util.Scanner;

public class MaxCircularShift {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine().trim();
        
        String maxNumber = findMaxCircularShift(input);
        System.out.println(maxNumber);
    }

    private static String findMaxCircularShift(String number) {
        String maxNumber = number;
        String current = number;

        for (int i = 0; i < number.length(); i++) {
            current = shiftRight(current);
            if (current.compareTo(maxNumber) > 0) {
                maxNumber = current;
            }
        }
        
        return maxNumber;
    }

    private static String shiftRight(String number) {
        int length = number.length();
        return number.charAt(length - 1) + number.substring(0, length - 1);
    }
}
