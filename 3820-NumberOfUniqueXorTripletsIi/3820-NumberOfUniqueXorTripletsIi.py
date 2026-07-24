# Last updated: 7/24/2026, 1:29:34 PM
class Solution(object):

  def uniqueXorTriplets(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    # 1. Deduplicate nums
    unique_nums = list(set(nums))
    n = len(unique_nums)

    # 2. Compute all unique pair XOR values
    pair_xors = set()
    for i in range(n):
      for j in range(i, n):
        pair_xors.add(unique_nums[i] ^ unique_nums[j])

    # 3. Combine pair XORs with single values to get triplet XORs
    triplet_xors = set()
    for p in pair_xors:
      for x in unique_nums:
        triplet_xors.add(p ^ x)

    return len(triplet_xors)