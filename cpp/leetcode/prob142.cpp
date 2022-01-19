//
// Created by Dongmin on 2022/01/19.
//

class Solution {
public:
    set<ListNode*> isPassed;
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        if (isPassed.find(head) != isPassed.end()){
            return head;
        }

        isPassed.insert(head);
        return detectCycle(head->next);
    }
};