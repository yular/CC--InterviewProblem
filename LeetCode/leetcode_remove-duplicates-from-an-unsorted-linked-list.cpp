/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(n)
*/

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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        
        unordered_map<int,int> numCnt;
        for(ListNode *p = head; p != NULL; p = p->next) {
            ++ numCnt[p->val];
        }
        
        ListNode dummy(-1);
        ListNode *p = &dummy;
        for(ListNode *q = head; q != NULL; q = q->next){
            if(numCnt[q->val] > 1) {
                continue;
            }
            p->next = q;
            p = p->next;
        }
        p->next = NULL;
        return dummy.next;
    }
};
