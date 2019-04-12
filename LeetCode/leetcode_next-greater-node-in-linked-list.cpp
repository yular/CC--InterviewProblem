/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        if(head == NULL) {
            return ans;
        }
        
        stack<int> stk;
        vector<int> arr;
        int idx = 0;
        for(ListNode* p = head; p != NULL; p = p->next, ++ idx){
            ans.push_back(0);
            while(!stk.empty() && arr[stk.top()] < p->val) {
                ans[stk.top()] = p->val;
                stk.pop();
            }
            stk.push(idx);
            arr.push_back(p->val);
        }
        return ans;
    }
};
