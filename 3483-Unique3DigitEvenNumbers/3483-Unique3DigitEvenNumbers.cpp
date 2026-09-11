// Last updated: 9/11/2026, 11:33:44 PM
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Array to store the frequency of each available digit (0-9)
        vector<int> count(10, 0);
        for (int digit : digits) {
            count[digit]++;
        }
        
        int total = 0;
        
        // Iterate through all possible 3-digit even numbers
        for (int i = 100; i < 1000; i += 2) {
            vector<int> currentCount(10, 0);
            int temp = i;
            
            // Extract each digit from the current number and increment its required count
            while (temp > 0) {
                currentCount[temp % 10]++;
                temp /= 10;
            }
            
            // Check if we have enough of each digit to form this number
            bool canForm = true;
            for (int j = 0; j < 10; j++) {
                if (currentCount[j] > count[j]) {
                    canForm = false;
                    break;
                }
            }
            
            // If we have the required digits, increment the total
            if (canForm) {
                total++;
            }
        }
        
        return total;
    }
};