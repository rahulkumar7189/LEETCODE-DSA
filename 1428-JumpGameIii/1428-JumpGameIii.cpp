// Last updated: 7/5/2026, 11:03:50 PM
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // 1. Check bounds and if we've already visited this index
        if (start < 0 || start >= arr.size() || arr[start] < 0) {
            return false;
        }
        
        // 2. Base case: we found the target!
        if (arr[start] == 0) {
            return true;
        }
        
        // 3. Store the jump and mark the current index as visited
        int jump = arr[start];
        arr[start] = -arr[start]; 
        
        // 4. Short-circuit return: if the left path is true, the right path is never evaluated
        return canReach(arr, start - jump) || canReach(arr, start + jump);
    }
};