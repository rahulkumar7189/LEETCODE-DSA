// Last updated: 7/12/2026, 9:33:49 PM
1#include <vector>
2#include <algorithm>
3#include <unordered_map>
4
5class Solution {
6public:
7    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
8        // 1. Create a copy and sort it
9        std::vector<int> sortedArr = arr;
10        std::sort(sortedArr.begin(), sortedArr.end());
11        
12        // 2. Assign ranks to unique elements
13        std::unordered_map<int, int> ranks;
14        int currentRank = 1;
15        for (int num : sortedArr) {
16            if (ranks.find(num) == ranks.end()) {
17                ranks[num] = currentRank++;
18            }
19        }
20        
21        // 3. Transform the original array
22        std::vector<int> result;
23        result.reserve(arr.size());
24        for (int num : arr) {
25            result.push_back(ranks[num]);
26        }
27        
28        return result;
29    }
30};