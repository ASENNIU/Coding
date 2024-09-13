package Practice.VIVO;

import java.util.*;

public class Solution2 {
    public static void main(String[] args) {
        int[] memoryUsage = {80, 100, 70, 90, 60, 85, 75, 95, 110};
        int k = 4;
        int[] result = calculateFluctuations(memoryUsage, k);
        for (int i = 0; i < result.length; ++i ) {
            System.out.print(result[i] + " ");
        }
        
    }

    public static int[] calculateFluctuations(int[] memoryUsage, int k) {
        List<Integer> fluctuations = new ArrayList<>();
        
        for (int i = 0; i <= memoryUsage.length - k; i++) {
            int max = Integer.MIN_VALUE;
            int min = Integer.MAX_VALUE;
            
            for (int j = i; j < i + k; j++) {
                if (memoryUsage[j] > max) {
                    max = memoryUsage[j];
                }
                if (memoryUsage[j] < min) {
                    min = memoryUsage[j];
                }
            }
            
            fluctuations.add(max - min);
        }
        int[] array = new int[fluctuations.size()];
        for (int i = 0; i < fluctuations.size(); i++) {
            array[i] = fluctuations.get(i);
        }
        return array;
    }
}
