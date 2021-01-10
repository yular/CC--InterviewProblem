/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL) {
            return head;
        }
        
        int len = 0;
        ListNode *p = head, *kNode = NULL;
        for(int i = 1; p != NULL; p = p->next, ++ i, ++ len) {
            if(i == k) {
                kNode = p;
            }
        }
        if(len < k) {
            return head;
        }
        
        ListNode *lastkNode = head;
        for(; len > k; -- len) {
            lastkNode = lastkNode->next;
        }
        swap(kNode->val, lastkNode->val);
        return head;
    }
};
