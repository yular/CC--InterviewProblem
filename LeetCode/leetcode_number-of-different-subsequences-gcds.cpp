/*
*
* Tag: Math
* Time: O(m(lgm)^2)
* Space: O(m)
* Credit: https://leetcode.com/problems/number-of-different-subsequences-gcds/discuss/1143292/C%2B%2B-Solution
*/

class Solution {
private:
    int SIZE = 200010;
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int maxVal = 0;
        vector<bool> vis(SIZE, false);
        for(int i = 0; i < nums.size(); ++ i){
            vis[nums[i]] = true;
            maxVal = max(nums[i], maxVal);
        }
        ++ maxVal;
        
        for(int i = 1; i < maxVal; ++ i) {
            if(vis[i]) {
                continue;
            }
            
            int v = 0;
            for(int j = i*2; j < maxVal; j += i) {
                if(!vis[j]) {
                    continue;
                }
                
                v = gcd(j, v);
                vis[v] = true;
                if(v == i) {
                    break;
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i < maxVal; ++ i) {
            if(vis[i]) {
                ++ ans;
            }
        }
        return ans;
    }
};
