package Practice.VIVO;

import java.util.*;

public class Solution3 {
    public static void main(String[] args) {
        int[] prices = {5, 4, 1, 3, 2, 3, 2};
        int k = 4;
        System.out.println(canEqualDistribution(prices, k));
    }

    public static boolean canEqualDistribution(int[] prices, int k) {
        int totalSum = Arrays.stream(prices).sum();
        
        if (totalSum % k != 0) {
            return false;
        }
        
        int target = totalSum / k;
        Arrays.sort(prices);
        int[] buckets = new int[k];
        
        return canPartition(prices, buckets, prices.length - 1, target);
    }

    private static boolean canPartition(int[] prices, int[] buckets, int index, int target) {
        if (index < 0) {
            for (int bucket : buckets) {
                if (bucket != target) {
                    return false;
                }
            }
            return true;
        }
        
        int currentPrice = prices[index];
        for (int i = 0; i < buckets.length; i++) {
            if (buckets[i] + currentPrice <= target) {
                buckets[i] += currentPrice;
                if (canPartition(prices, buckets, index - 1, target)) {
                    return true;
                }
                buckets[i] -= currentPrice;
            }
            
            if (buckets[i] == 0) {
                break;
            }
        }
        
        return false;
    }
}
