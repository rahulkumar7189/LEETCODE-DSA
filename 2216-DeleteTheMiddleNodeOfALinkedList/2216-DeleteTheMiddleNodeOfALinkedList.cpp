// Last updated: 7/5/2026, 11:03:26 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Fast I/O optimization block to achieve 0ms execution time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // Edge case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        // Single pass pointer traversal
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Unlink the middle node
        prev->next = slow->next;
        
        // Free memory safely
        delete slow;
        
        return head;
    }
};