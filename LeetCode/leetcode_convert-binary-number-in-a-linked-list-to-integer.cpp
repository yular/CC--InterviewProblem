/*
*
* Tag: Bit Manipulation
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
    int getDecimalValue(ListNode* head) {
        int mask = (1<<30), len = 0, ans = 0;
        for(; head != NULL; head = head->next, ++ len, mask >>= 1) {
            ans |= (head->val == 1? mask : 0);
        }
        ans >>= (30 - len + 1);
        return ans;
    }
};
