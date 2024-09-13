package Practice.VIVO;

import java.util.*;

public class Solution1 {
    public static void main(String[] args) {
        int[] staff = new int[]{1, 0, 0, 0, 1};
        System.out.println(minimumGroups(staff));
    }

    public static int minimumGroups(int[] staff) {
        List<Integer> oldEmployees = new ArrayList<>();
        List<Integer> newEmployees = new ArrayList<>();

        // Separate old and new employees
        for (int person : staff) {
            if (person == 1) {
                oldEmployees.add(person);
            } else {
                newEmployees.add(person);
            }
        }

        int groupCount = 0;
        int oldIndex = 0;
        int newIndex = 0;

        // Pair each old employee with a new employee if possible
        while (oldIndex < oldEmployees.size()) {
            groupCount++;
            oldIndex++;
            if (newIndex < newEmployees.size()) {
                newIndex++;
            }
        }

        // Group remaining new employees
        while (newIndex < newEmployees.size()) {
            groupCount++;
            newIndex += Math.min(3, newEmployees.size() - newIndex);
        }

        return groupCount;
    }
}
