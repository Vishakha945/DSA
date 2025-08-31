/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        // Find length
        int len = 1;
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
            len++;
        }

        // Connect last node to head (make circular)
        temp->next = head;

        // New head position
        k = k % len;
        int steps = len - k;
        while (steps--) {
            temp = temp->next;
        }

        // Break circle
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
