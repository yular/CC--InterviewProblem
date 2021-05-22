/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int ans = 0;
        for(int i = 0; i < nums.size(); ++ i) {
            dfs(nums, i, ans, nums[i]);
        }
        return ans;
    }
private:
    void dfs(vector<int>& nums, int idx, int &ans, int v) {
        ans += v;
        for(int i = idx + 1; i < nums.size(); ++ i) {
            v ^= nums[i];
            dfs(nums, i, ans, v);
            v ^= nums[i];
        }
        return;
    }
};
