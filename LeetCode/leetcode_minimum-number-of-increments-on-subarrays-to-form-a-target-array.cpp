/*
*
* Tag: Stack
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        if(target.size() == 0) {
            return 0;
        }
        
        int n = target.size(), top = 0, ans = 0;
        vector<int> stk(n, 0);
        for(int i = 0; i < n; ++ i) {
            if(top > 0 && stk[top - 1] >= target[i]) {
                ans += (stk[top - 1] - target[i]);
            }
            while(top > 0 && stk[top - 1] >= target[i]) {
                -- top;
            }
            stk[top ++] = target[i];
        }
        if(top > 0) {
            ans += stk[top - 1];
        }
        return ans;
    }
};
