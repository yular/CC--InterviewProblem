/*
*
* Tag: Greedy, Sliding Window
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int ans = 0, posCnt = 0, totCnt = 0, val = 1, firstNeg = -1;
        for(int i = 0; i < nums.size(); ++ i){
            int num = nums[i];
            ++ totCnt;
            if(num > 0) {
                val *= 1;
                ++ posCnt;
            } else if(num < 0) {
                val *= -1;
                posCnt = 0;
                if(firstNeg == -1) {
                    firstNeg = i;
                }
            } else {
                val = 0;
            }
            
            ans = max(ans, posCnt);
            if(val > 0) {
                ans = max(ans, totCnt);
            } else if(val < 0) {
                ans = max(ans, i - firstNeg);
            } else {
                if(firstNeg != -1) {
                    ans = max(ans, i - firstNeg - 1);
                }
                
                val = 1;
                posCnt = totCnt = 0;
                firstNeg = -1;
            }
        }
        return ans;
    }
};
