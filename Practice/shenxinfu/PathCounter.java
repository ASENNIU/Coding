import java.util.Scanner;

public class PathCounter {
    private static int m, n, k;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        k = scanner.nextInt();
        m = scanner.nextInt();
        n = scanner.nextInt();

        int result = countPaths(m, n, k);
        System.out.println(result);
    }

    private static int countPaths(int m, int n, int k) {
        if (m + n > k) {
            return 0; 
        }

        int[][] dp = new int[m + 1][n + 1];
        dp[0][0] = 1;

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) continue;
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
}
