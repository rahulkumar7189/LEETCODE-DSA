// Last updated: 7/5/2026, 11:03:33 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        // Find the maximum cost to size our frequency array
        int max_cost = *std::max_element(costs.begin(), costs.end());
        
        // frequency array to store the count of each cost
        std::vector<int> freq(max_cost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }
        
        int iceCreamCount = 0;
        
        // Iterate through all possible costs starting from the cheapest (1)
        for (int cost = 1; cost <= max_cost; ++cost) {
            if (freq[cost] == 0) continue;
            
            // If we can't even afford one bar at this price, we are done
            if (coins < cost) break;
            
            // Calculate how many bars at this price we want vs how many we can afford
            int demand = freq[cost];
            int affordable = coins / cost;
            int take = std::min(demand, affordable);
            
            // Update our totals
            iceCreamCount += take;
            coins -= take * cost;
            
            // If we couldn't buy all available at this price, it means we ran out of coins
            if (take < demand) break;
        }
        
        return iceCreamCount;
    }
};