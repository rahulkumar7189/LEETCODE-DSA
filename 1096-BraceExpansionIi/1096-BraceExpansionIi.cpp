// Last updated: 9/28/2026, 11:01:31 PM
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <set>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        queue<string> q;
        q.push(expression);
        
        unordered_set<string> visited;
        visited.insert(expression);
        
        // A set automatically sorts the results and ensures uniqueness
        set<string> res;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // Find the first closing brace
            int right = curr.find('}');
            
            // If there are no braces left, this is a fully expanded word
            if (right == string::npos) {
                res.insert(curr);
                continue;
            }

            // Find the closest opening brace to its left
            int left = curr.rfind('{', right);

            // Extract the strings before, inside, and after the brace pair
            string before = curr.substr(0, left);
            string after = curr.substr(right + 1);
            string mid = curr.substr(left + 1, right - left - 1);

            // The 'mid' string has no nested braces, so we just split it by commas
            stringstream ss(mid);
            string part;
            while (getline(ss, part, ',')) {
                // Construct the new string with one of the options
                string nextStr = before + part + after;
                
                // If we haven't seen this string combination yet, add it to the queue
                if (visited.find(nextStr) == visited.end()) {
                    visited.insert(nextStr);
                    q.push(nextStr);
                }
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};