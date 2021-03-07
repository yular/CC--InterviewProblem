/*
*
* Tag: Greedy
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for(int num : nums) {
            sum += num;
        }
        if(sum == goal) {
            return 0;
        }
        int cnt = 0;
        while(sum != goal) {
            long long diff = goal - sum;
            if(abs(diff) <= limit) {
                ++ cnt;
                sum = goal;
            } else {
                cnt += abs(diff)/limit;
                sum += (diff/limit)*limit;
            }
        }
        return cnt;
    }
};
