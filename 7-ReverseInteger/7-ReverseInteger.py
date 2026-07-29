# Last updated: 7/29/2026, 11:40:56 AM
class Solution(object):

    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        INT_MIN = -(2**31)
        INT_MAX = 2**31 - 1

        sign = -1 if x < 0 else 1
        x = abs(x)
        res = 0

        while x != 0:
            digit = x % 10
            x //= 10

            # Overflow check before updating res
            if res > (INT_MAX - digit) // 10:
                return 0

            res = res * 10 + digit

        return res * sign