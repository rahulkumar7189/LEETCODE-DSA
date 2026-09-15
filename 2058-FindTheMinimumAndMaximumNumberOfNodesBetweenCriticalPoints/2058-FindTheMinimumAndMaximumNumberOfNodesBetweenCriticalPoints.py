# Last updated: 9/15/2026, 11:54:55 PM
class Solution:
    def nodesBetweenCriticalPoints(self, head):
        prev = head
        curr = head.next
        idx = 2

        first = -1
        last = -1
        prev_critical = -1
        min_dist = float('inf')

        while curr.next:
            nxt = curr.next
            if (curr.val > prev.val and curr.val > nxt.val) or (curr.val < prev.val and curr.val < nxt.val):
                if first == -1:
                    first = idx
                else:
                    min_dist = min(min_dist, idx - prev_critical)
                prev_critical = idx
                last = idx

            prev = curr
            curr = nxt
            idx += 1

        if first == -1 or first == last:
            return [-1, -1]

        return [min_dist, last - first]