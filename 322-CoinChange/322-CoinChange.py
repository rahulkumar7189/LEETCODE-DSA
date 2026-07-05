# Last updated: 7/5/2026, 11:04:14 PM
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        # Initialize the dp array with a large number (infinity)
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0  # Base case: 0 coins are needed to make amount 0
        
        # Iterate through each coin
        for coin in coins:
            for i in range(coin, amount + 1):
                dp[i] = min(dp[i], dp[i - coin] + 1)
        
        # If dp[amount] is still infinity, return -1
        return dp[amount] if dp[amount] != float('inf') else -1
