
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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Step 1: Insert the head of every non-empty list
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        // Step 2: Create dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // Step 3: Process smallest node
        while (!pq.empty()) {

            ListNode* curr = pq.top();
            pq.pop();

            // Attach smallest node to result
            tail->next = curr;
            tail = tail->next;

            // Insert next node from the same list
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};
