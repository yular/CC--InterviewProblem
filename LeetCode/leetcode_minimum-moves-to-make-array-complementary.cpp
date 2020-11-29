/*
*
* Tag: Greedy
* Time: O(max(n, limit))
* Space: O(limit)
* Credit: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/discuss/952773/PythonJava-simple-O(max(n-k))-method
*/

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        if(nums.size() < 3) {
            return 0;
        }
        
        vector<int> sumDelta(2*limit + 2, 0);
        int n = nums.size();
        for(int i = 0; i < n/2; ++ i) {
            int a = nums[i], b = nums[n - 1 - i];
            sumDelta[2] += 2;
            -- sumDelta[min(a, b) + 1];
            -- sumDelta[a + b];
            ++ sumDelta[a + b + 1];
            ++ sumDelta[max(a, b) + limit + 1];
        }
        
        int ans = 2*n, cur = 0;
        for(int i = 2; i <= 2*limit; ++ i){
            cur += sumDelta[i];
            ans = min(ans, cur);
        }
        return ans;
    }
};
