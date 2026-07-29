# Last updated: 7/29/2026, 11:40:54 AM
class Solution(object):
    def hasCycle(self, head):
        slow = head
        fast = head
        
        while fast and fast.next:
            slow = slow.next          # Move 1 step
            fast = fast.next.next     # Move 2 steps
            
            if slow == fast:
                return True
                
        return False