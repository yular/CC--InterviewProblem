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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *p = head;
        int cnt = 1;
        while(p != NULL) {
            while(p != NULL && cnt < m) {
                p = p->next;
                ++ cnt;
            }
            
            cnt = 0;
            while(p != NULL && p->next != NULL && cnt < n) {
                p->next = p->next->next;
                ++ cnt;
            }
            cnt = 0;
        }
        return head;
    }
};
