import java.util.*;

public class Solution2 {
    public int maxPoints(int n, int[] points, int[][] dependencies, int k) {
      
        List<Integer>[] graph = new ArrayList[n];
        int[] inDegree = new int[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] dep : dependencies) {
            graph[dep[1]].add(dep[0]);
            inDegree[dep[0]]++;
        }

    
        List<Integer> topoOrder = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        while (!queue.isEmpty()) {
            int cur = queue.poll();
            topoOrder.add(cur);
            for (int next : graph[cur]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    queue.offer(next);
                }
            }
        }

       
        int[][] dp = new int[n + 1][k + 1];  


        for (int cur : topoOrder) {
            for (int j = k; j >= 1; j--) {
                for (int prev = j - 1; prev >= 0; prev--) {
                    dp[cur + 1][j] = Math.max(dp[cur + 1][j], dp[cur][prev] + points[cur]);
                }
            }

            for (int next : graph[cur]) {
                for (int j = k; j >= 1; j--) {
                    dp[next + 1][j] = Math.max(dp[next + 1][j], dp[cur + 1][j]);
                }
            }
        }

        int maxScore = 0;
        for (int i = 1; i <= n; i++) {
            maxScore = Math.max(maxScore, dp[i][k]);
        }

        return maxScore;
    }

    public static void main(String[] args) {
        Solution2 solution = new Solution2();
   
        int n = 6;
        int[] points = {8, 3, 7, 5, 6, 2};
        int[][] dependencies = {{1, 0}, {2, 1}, {3, 1}, {4, 2}};
        int k = 3;

        int result = solution.maxPoints(n, points, dependencies, k);
        System.out.println(result);  
    }
}
