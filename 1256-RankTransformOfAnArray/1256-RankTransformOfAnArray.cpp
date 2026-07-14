// Last updated: 7/14/2026, 2:32:25 PM
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        // 1. Create a copy and sort it
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());
        
        // 2. Assign ranks to unique elements
        std::unordered_map<int, int> ranks;
        int currentRank = 1;
        for (int num : sortedArr) {
            if (ranks.find(num) == ranks.end()) {
                ranks[num] = currentRank++;
            }
        }
        
        // 3. Transform the original array
        std::vector<int> result;
        result.reserve(arr.size());
        for (int num : arr) {
            result.push_back(ranks[num]);
        }
        
        return result;
    }
};