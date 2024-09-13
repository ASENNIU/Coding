import java.util.*;

public class Solution1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        
        int[][] grid = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }
        
        System.out.println(maxPriceValue(grid));
    }
    
    public static int maxPriceValue(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] dp = new int[m][n];

        for (int[] row : dp) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }

        if (grid[0][0] != -1) {
            dp[0][0] = grid[0][0];
        }

        for (int j = 1; j < n; j++) {
            if (grid[0][j] != -1 && dp[0][j - 1] != Integer.MIN_VALUE) {
                dp[0][j] = dp[0][j - 1] + grid[0][j];
            }
        }

        for (int i = 1; i < m; i++) {
            if (grid[i][0] != -1 && dp[i - 1][0] != Integer.MIN_VALUE) {
                dp[i][0] = dp[i - 1][0] + grid[i][0];
            }
        }
        

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] != -1) {
                    if (dp[i - 1][j] != Integer.MIN_VALUE) {
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] + grid[i][j]);
                    }
                    if (dp[i][j - 1] != Integer.MIN_VALUE) {
                        dp[i][j] = Math.max(dp[i][j], dp[i][j - 1] + grid[i][j]);
                    }
                }
            }
        }
        
        return dp[m - 1][n - 1] == Integer.MIN_VALUE ? -1 : dp[m - 1][n - 1];
    }
}
