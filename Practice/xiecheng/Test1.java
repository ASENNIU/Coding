import java.util.Scanner;

public class Test1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] p = new int[n + 1];

        for (int i = 1; i <=  k - 1; i++) {
            p[i] = i;
        }
  
        for (int i = k; i <= n; i++) {
            p[i] = n - (i - k);
        }
        

        for (int i = 1; i <= n; i++) {
            System.out.print(p[i] + " ");
        }
    }
}
