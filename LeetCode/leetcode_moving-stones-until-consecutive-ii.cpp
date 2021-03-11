/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        if(stones.size() == 0) {
            return {};
        }
        
        sort(stones.begin(), stones.end());
        
        int n = stones.size();
        vector<int> ans = {n, INT_MIN};
        for(int l = 0, r = 0; r < n; ) {
            int w = stones[r] - stones[l] + 1, cnt = r - l + 1;
            if(w > n) {
                ++ l;
                continue;
            }
            if(w == n - 1 && cnt == n - 1){
                ans[0] = min(ans[0], 2);
            } else {
                ans[0] = min(ans[0], n - cnt);
            }
            ++ r;
        }
        
        if(stones[1] == stones[0] + 1 || stones[n - 1] == stones[n - 2] + 1) {
            ans[1] = stones[n - 1] - stones[0] - n + 1;
        } else {
            ans[1] = max((stones[n - 1] - stones[1]) - (n - 1) + 1, (stones[n - 2] - stones[0]) - (n - 1) + 1);
        }
        return ans;
    }
};
