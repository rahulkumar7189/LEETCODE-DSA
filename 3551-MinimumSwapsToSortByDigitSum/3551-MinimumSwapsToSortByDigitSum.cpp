// Last updated: 10/17/2026, 9:57:40 PM
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Structure to hold the value, its digit sum, and original index
        struct Element {
            int val;
            int sum;
            int idx;
        };
        
        vector<Element> arr(n);
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            int s = 0;
            int temp = v;
            
            // Calculate digit sum
            while (temp > 0) {
                s += temp % 10;
                temp /= 10;
            }
            arr[i] = {v, s, i};
        }
        
        // Sort based on digit sum, breaking ties with the value itself
        sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
            if (a.sum != b.sum) return a.sum < b.sum;
            return a.val < b.val;
        });
        
        int swaps = 0;
        vector<bool> visited(n, false);
        
        // Find cycles to calculate minimum swaps
        for (int i = 0; i < n; ++i) {
            // If already visited or already in the correct position
            if (visited[i] || arr[i].idx == i) {
                continue;
            }
            
            int j = i;
            int cycle_size = 0;
            
            // Traverse the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].idx;
                cycle_size++;
            }
            
            // If a cycle has more than 1 element, it takes (size - 1) swaps
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};