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
// O(n) time / O(1) space

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode dummy(0);
        dummy.next = head;

        ListNode* left = &dummy;
        ListNode* right = &dummy;

        // Create a gap of n nodes (move right by n nodes)
        for(int i = 0; i < n; i++) {
            right = right->next;
        }

        // Move together until right reaches the last node
        while(right->next != nullptr) {
            left  = left->next;
            right = right->next;
        }

        // NOW left is one node before the node we want to remove
        // Remove the target node
        left->next = left->next->next;

        return dummy.next;
    }
};
