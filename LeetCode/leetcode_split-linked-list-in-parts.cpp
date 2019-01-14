/*
*
* Tag: Implementation
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans(k);
        if(root == NULL || k == 0){
            return ans;
        }
        
        int len = 0;
        ListNode *p = root;
        while(p != NULL){
            p = p->next;
            ++ len;
        }
        
        int extraNodesListLen = len%k, avgListLen = len/k;
        p = root;
        for(int i = 0; i < k && p != NULL; ++ i){
            int curLinkedListLen = avgListLen;
            if(i < extraNodesListLen){
                ++ curLinkedListLen;
            }
            
            ListNode *curp = p;
            ans[i] = curp;
            for(int j = 1; j < curLinkedListLen; ++ j){
                curp = curp->next;
            }
            p = curp->next;
            curp->next = NULL;
        }
        return ans;
    }
};
