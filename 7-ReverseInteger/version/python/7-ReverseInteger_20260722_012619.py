# Last updated: 7/22/2026, 1:26:19 AM
'''
Reverse Integer using digit extraction and overflow check.

• Approach: 
  1. Store the sign of `x` and process `abs(x)`.
  2. Extract the last digit using modulo (`x % 10`) and truncate `x` (`x // 10`).
  3. Prevent 32-bit signed integer overflow before updating `res` by checking if `res > (INT_MAX - digit) // 10`.
  4. Multiply the result by the original sign before returning.

• Time Complexity: O(log10(|x|)) — proportional to the number of digits.
• Space Complexity: O(1) — constant extra space.
'''

1class Solution(object):
2
3    def reverse(self, x):
4        """
5        :type x: int
6        :rtype: int
7        """
8        INT_MIN = -(2**31)
9        INT_MAX = 2**31 - 1
10
11        sign = -1 if x < 0 else 1
12        x = abs(x)
13        res = 0
14
15        while x != 0:
16            digit = x % 10
17            x //= 10
18
19            # Overflow check before updating res
20            if res > (INT_MAX - digit) // 10:
21                return 0
22
23            res = res * 10 + digit
24
25        return res * sign