// Last updated: 7/9/2026, 8:48:38 PM
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // component[i] will store the group ID for node i
        vector<int> component(n, 0);
        int currentGroup = 0;
        
        // Step 1: Preprocess and find connected components
        for (int i = 1; i < n; ++i) {
            // If the gap between adjacent elements exceeds maxDiff, 
            // it starts a new connected component.
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentGroup++;
            }
            component[i] = currentGroup;
        }
        
        // Step 2: Answer each query in O(1) time
        vector<bool> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            
            // If both nodes belong to the same continuous segment, a path exists.
            answer.push_back(component[u] == component[v]);
        }
        
        return answer;
    }
};