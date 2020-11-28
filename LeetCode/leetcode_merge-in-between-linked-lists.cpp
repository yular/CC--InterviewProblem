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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(list1 == NULL || list2 == NULL) {
            return list1;
        }
        
        ListNode *p = list1;
        
        int i = 0;
        for(; i < a - 1 && p != NULL; p = p->next, ++ i) ;
        
        ListNode *q = p->next;
        for(; i < b && q != NULL; q = q->next, ++ i) ;
        
        p->next = list2; 
        for(; p->next != NULL; p = p->next) ;
        p->next = q;
        
        return list1;
    }
};
