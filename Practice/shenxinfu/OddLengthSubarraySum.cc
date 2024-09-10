#include <iostream>
#include <vector>

int sumOddLengthSubarrays(const std::vector<int>& arr) {
    int n = arr.size();
    int totalSum = 0;

    for (int i = 0; i < n; ++i) {
        int endCount = n - i;
        int startCount = i + 1;
        int totalSubarrays = startCount * endCount;
        int oddSubarrays = (totalSubarrays + 1) / 2; // Only odd-length subarrays

        totalSum += arr[i] * oddSubarrays;
    }

    return totalSum;
}

int main() {
    std::vector<int> arr = {1, 4, 2, 5, 3};
    int result = sumOddLengthSubarrays(arr);
    std::cout << result << std::endl; // Output: 58
    return 0;
}
