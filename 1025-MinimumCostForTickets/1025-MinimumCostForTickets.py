# Last updated: 7/5/2026, 11:03:57 PM
class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        # Create a dp array with size of days + 1
        dp = [0] * (len(days) + 1)
        
        # Iterate through each day in the days array
        for i in range(1, len(days) + 1):
            # Current day
            current_day = days[i - 1]
            
            # Cost for 1-day pass
            dp[i] = dp[i - 1] + costs[0]
            
            # Cost for 7-day pass
            j = i
            while j > 0 and days[j - 1] >= current_day - 7 + 1:
                j -= 1
            dp[i] = min(dp[i], dp[j] + costs[1])
            
            # Cost for 30-day pass
            j = i
            while j > 0 and days[j - 1] >= current_day - 30 + 1:
                j -= 1
            dp[i] = min(dp[i], dp[j] + costs[2])
        
        # The last element in dp array will be the answer
        return dp[len(days)]