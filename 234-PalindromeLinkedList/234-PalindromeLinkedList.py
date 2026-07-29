# Last updated: 7/29/2026, 11:40:46 AM
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: bool
        """
        rev = None
        slow = fast = head

        # Step 1: Find midpoint while reversing the first half in-place
        while fast and fast.next:
            fast = fast.next.next
            
            # Reverse slow pointer's node
            temp = slow.next
            slow.next = rev
            rev = slow
            slow = temp

        # Step 2: Handle odd-length list (skip the exact middle element)
        if fast:
            slow = slow.next

        # Step 3: Compare reversed first half with the second half
        while rev and rev.val == slow.val:
            rev = rev.next
            slow = slow.next

        # If rev is None, all values matched
        return not rev