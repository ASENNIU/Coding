
import java.util.Scanner;

public class Test3 {
    static int count = 0;
  
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int k = scanner.nextInt();
        

        int[] digits = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            digits[i] = i;
        }

        generateNumbers(digits, m, 0, 0, k, new boolean[n + 1], n);
        
        System.out.println(count);
    }
    

    public static void generateNumbers(int[] digits, int m, int length, long currentNumber, int k, boolean[] used, int n) {

        if (length == m) {
            if (currentNumber > k) {
                count++;
            }
            return;
        }
        

        if (currentNumber > k) {

            count += factorial(n - length) / factorial(n - m);
            return;
        }
        for (int i = 0; i < digits.length; i++) {

            if (!used[i] && (length > 0 || digits[i] != 0)) {
                used[i] = true;

                generateNumbers(digits, m, length + 1, currentNumber * 10 + digits[i], k, used, n);
                used[i] = false;
            }
        }
    }
    

    public static int factorial(int num) {
        int result = 1;
        for (int i = 1; i <= num; i++) {
            result *= i;
        }
        return result;
    }
}
