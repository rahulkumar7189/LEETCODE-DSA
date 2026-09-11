# Last updated: 9/11/2026, 11:33:23 PM
class Solution(object):

  def uniqueXorTriplets(self, nums):
    """

    :type nums: List[int]

    :rtype: int

    """
    n = len(nums)

    # Base cases for n = 1 and n = 2
    if n <= 2:
      return n

    # For n >= 3, all numbers from 0 to (2^k - 1) can be formed
    return 1 << n.bit_length()