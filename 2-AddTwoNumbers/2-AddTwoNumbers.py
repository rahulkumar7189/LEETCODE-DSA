# Last updated: 7/5/2026, 11:04:20 PM
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        # Create a dummy head to simplify building the new list
        dummy = ListNode(0)
        current = dummy
        carry = 0
        
        # Continue as long as there are nodes to process or a carry exists
        while l1 or l2 or carry:
            # Get values from nodes, or 0 if the list has ended
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            
            # Calculate the sum and the new carry
            total = val1 + val2 + carry
            carry = total // 10
            new_val = total % 10
            
            # Create the new node and move the pointer forward
            current.next = ListNode(new_val)
            current = current.next
            
            # Move to the next nodes in the input lists if they exist
            if l1: l1 = l1.next
            if l2: l2 = l2.next
            
        return dummy.next