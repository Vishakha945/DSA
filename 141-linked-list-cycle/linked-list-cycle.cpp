/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false; // empty or single node without cycle
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;          // move slow by 1
            fast = fast->next->next;    // move fast by 2
            
            if (slow == fast) {         // cycle detected
                return true;
            }
        }
        
        return false; // no cycle
    }
};
