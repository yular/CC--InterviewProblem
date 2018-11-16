/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *ans = head, *p = head;
        while(p != NULL && p->next != NULL) {
            p = p->next;
            ans = ans->next;
            p = p->next;
        }
        return ans;
    }
};
