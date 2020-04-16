/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        unordered_map<int,int> numDeg;
        int deg = 0;
        for(int num : nums) {
            ++ numDeg[num];
            deg = max(deg, numDeg[num]);
        }
        if(deg == 1) {
            return 1;
        }
        
        numDeg.clear();
        int curDeg = 0, degNum = 0, ans = nums.size();
        for(int l = 0, r = 0; r < nums.size(); ++ r) {
            ++ numDeg[nums[r]];
            curDeg = max(curDeg, numDeg[nums[r]]);
            if(curDeg < deg) {
                continue;
            }
            
            degNum = nums[r];
            while(l < r && nums[l] != nums[r]) {
                -- numDeg[nums[l]];
                ++ l;
            }
            ans = min(ans, r - l + 1);
            -- curDeg;
            ++ l;
        }
        return ans;
    }
};
