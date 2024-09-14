package Practice.BILIBILI;

import java.util.ArrayList;
import java.util.List;

public class AdditiveNumber {

    public static int[] findAdditiveSequence(String num) {
        List<Integer> result = new ArrayList<>();
        if (backtrack(num, result, 0)) {
            return result.stream().mapToInt(i -> i).toArray();
        }
        return new int[0];
    }

    private static boolean backtrack(String num, List<Integer> result, int index) {
        if (index == num.length() && result.size() >= 3) {
            return true;
        }

        for (int i = index; i < num.length(); i++) {
            if (num.charAt(index) == '0' && i > index) {
                break;
            }

            long number = Long.parseLong(num.substring(index, i + 1));
            if (number > Integer.MAX_VALUE) {
                break;
            }

            int size = result.size();
            if (size >= 2 && number != result.get(size - 1) + result.get(size - 2)) {
                continue;
            }

            result.add((int) number);
            if (backtrack(num, result, i + 1)) {
                return true;
            }
            result.remove(result.size() - 1);
        }
        return false;
    }

    public static void main(String[] args) {
        int[] result1 = findAdditiveSequence("12358");
        for (int num : result1) {
            System.out.print(num + " ");
        }
        System.out.println();

        int[] result2 = findAdditiveSequence("1234");
        for (int num : result2) {
            System.out.print(num + " ");
        }

        int[] result3 = findAdditiveSequence("1202141");
        for (int num : result3) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
