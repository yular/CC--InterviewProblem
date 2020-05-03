/*
*
* Tag: Data Structure, TreeMap
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if(nums.size() < 2) {
            return nums.size();
        }
        
        map<int,int> window;
        int ans = 0;
        for(int l = 0, r = 0; r < nums.size(); ++ r) {
            ++ window[nums[r]];
            auto minIt = window.begin();
            auto maxIt = window.rbegin();
            while(l <= r && maxIt->first - minIt->first > limit) {
                -- window[nums[l]];
                if(window[nums[l]] == 0) {
                    window.erase(nums[l]);
                }
                ++ l;
                minIt = window.begin(), maxIt = window.rbegin();
            }
            
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
