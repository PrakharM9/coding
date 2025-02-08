#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            bool isGood = false;  // Tracks if the number is a "good" number
            int num = i;
            while (num > 0) {
                int digit = num % 10;
                if (digit == 3 || digit == 4 || digit == 7) {
                    isGood = false;  // Invalid digit found
                    break;
                }
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    isGood = true;  // At least one valid rotation
                }
                num /= 10;  // Reduce number for next iteration
            }
            if (isGood) {
                count++;  // Increment count for good numbers
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    cout << sol.rotatedDigits(10);  // Example test case
    return 0;
}
