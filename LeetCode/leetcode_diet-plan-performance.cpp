/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int sum = 0, ans = 0;
        for(int l = 0,  r = 0; r < calories.size(); ++ r) {
            sum += calories[r];
            if(r < k - 1) {
                continue;
            }
            if(r >= k) {
                sum -= calories[l];
                ++ l;
            }
            
            if(sum < lower) {
                -- ans;
            } else if(sum > upper) {
                ++ ans;
            }
        }
        return ans;
    }
};
