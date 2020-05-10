/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        map<int,int> numCnt;
        int ans = 0;
        for(int num : nums) {
            numCnt[num] += num;
            ans = max(ans, numCnt[num]);
        }
        
        for(auto i : numCnt) {
            int maxVal = i.second;
            for(auto j : numCnt) {
                if(j.first + 1 >= i.first) {
                    break;
                }
                
                if(i.second + j.second > maxVal) {
                    maxVal = i.second + j.second;
                }
            }
            ans = max(ans, maxVal);
            numCnt[i.first] = max(i.second, maxVal);
        }
        return ans;
    }
};
