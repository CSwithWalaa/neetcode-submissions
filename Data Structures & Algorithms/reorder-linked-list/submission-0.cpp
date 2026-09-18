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

    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return;
        
        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Split the list
        ListNode* second = slow->next;
        slow->next = nullptr;

        // 3. Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = second;

        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        second = prev;

        // 4. Merge alternately
        ListNode* first = head;

        while(second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
