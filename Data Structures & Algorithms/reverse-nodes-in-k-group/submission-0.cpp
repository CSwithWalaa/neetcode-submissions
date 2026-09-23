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

// O(n) time / O(1) space
class Solution {
private:
    ListNode* getKth(ListNode* current, int k) 
    {
        while(current != nullptr && k > 0) {
            current = current->next;
            k--;
        }
        return current;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while(true) {

            // Find the kth node
            ListNode* kth = getKth(groupPrev, k);
            
            // Not enough nodes for another group
            if(kth == nullptr) break;

            // Save the beginning of the next group
            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Save old first node
            // Now the last node of the reversed group
            ListNode* groupStart = groupPrev->next;

            // Connect previous group to the reversed group
            groupPrev->next = kth; 

            // Move to the end of the reversed group
            groupPrev = groupStart;
        }

        return dummy.next;
    }
};
