/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        if(n == 0){
            return ans;
        }
        
        int idx = 0;
        for(int i = 1; i <= (n>>1); ++ i, idx += 2){
            ans[idx] = i;
            ans[idx + 1] = -i;
        }
        if((n&1) > 0){
            ans[n - 1] = 0;
        }
        
        return ans;
    }
};
