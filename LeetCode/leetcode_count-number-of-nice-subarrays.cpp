/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        if(k == 0 || nums.size() == 0){
            return ans;
        }
        
        int numOfOdd = 0;
        for(int l = 0, r = 0; r < nums.size(); ++ r){
            if((nums[r]&1) == 1) {
                ++ numOfOdd;
            }
            if(numOfOdd < k) {
                continue;
            }
            
            int leftLen = 1, rightLen = 1;
            while(l < r && (nums[l]&1) != 1 ) {
                ++ leftLen;
                ++ l;
            }
            
            ++ r;
            while(r < nums.size() && (nums[r]&1) != 1) {
                ++ rightLen;
                ++ r;
            }
            
            ans += leftLen*rightLen;
            -- numOfOdd;
            ++ l;
            -- r;
        }
        return ans;
    }
};
