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
// k - number of lists / n - total number of nodes
// each node enters and leaves the heap once / heap size at most k
// O(n log k) time / O(log k) space

public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > minHeap;

        // Put the first from every non-empty list
        for(ListNode* head : lists) {
            if(head != nullptr) 
                minHeap.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!minHeap.empty()) {

            // Smallest current node 
            ListNode* node = minHeap.top();
            minHeap.pop();

            // Add it to result (merged sorted list)
            tail->next = node;
            tail = tail->next;

            // Add next node from same list to the heap
            if(node->next != nullptr) {
                minHeap.push(node->next);
            }
        }

        return dummy.next;
    }
};
