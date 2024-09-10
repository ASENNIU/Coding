import java.util.Scanner;

public class OddLengthSubarraySum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter array elements separated by commas: ");
        String input = scanner.nextLine();
        String[] inputArray = input.split(",");
        int[] arr = new int[inputArray.length];
        
        for (int i = 0; i < inputArray.length; i++) {
            arr[i] = Integer.parseInt(inputArray[i].trim());
        }
        
        int totalSum = calculateOddLengthSubarraySum(arr);
        System.out.println("Total sum of all odd-length subarrays: " + totalSum);
    }
    
    private static int calculateOddLengthSubarraySum(int[] arr) {
        int totalSum = 0;
        
        for (int start = 0; start < arr.length; start++) {
            int sum = 0;
            for (int end = start; end < arr.length; end++) {
                sum += arr[end];
                if ((end - start + 1) % 2 != 0) {
                    totalSum += sum;
                }
            }
        }
        
        return totalSum;
    }
}
