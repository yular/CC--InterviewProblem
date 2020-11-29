/*
*
* Tag: Greedy + Data Structure
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if(k == 0 || nums.size() == 0 || nums.size() == k) {
            return nums;
        }
        
        map<int,int> numCnt;
        int r = 0, n = nums.size();
        for(; r < n && r + k - 1< n; ++ r) {
            ++ numCnt[nums[r]];
        }
        
        vector<int> ans(k, 0);
        for(int l = 0, i = 0; i < k; ++ r) {
            auto it = numCnt.begin();
            int v = it->first;
            ans[i ++] = v;
            if(i >= k) {
                break;
            }
            
            for(; l < r; ++ l) {
                -- numCnt[nums[l]];
                if(numCnt[nums[l]] == 0) {
                    numCnt.erase(nums[l]);
                }
                if(nums[l] == v) {
                    ++ l;
                    break;
                }
            }
            ++ numCnt[nums[r]];
        }
        return ans;
    }
};
