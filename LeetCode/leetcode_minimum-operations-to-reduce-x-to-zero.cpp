/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(x <= 0) {
            return -1;
        }
        
        unordered_map<long long,int> costDict;
        int n = nums.size(), ans = INT_MAX;
        long long sum = 0, minVal = INT_MAX;
        for(int cost = 1, i = n - 1; i >= 0; -- i, ++ cost) {
            sum += nums[i];
            costDict[sum] = cost;
            if(sum == x) {
                ans = min(ans, cost);
            }
            minVal = min(minVal, (long long)nums[i]);
        }
        if(sum < x || x < minVal) {
            return -1;
        }
        
        long long lSum = 0;
        for(int i = 0, cost = 1; i < n; ++ i, ++ cost) {
            lSum += nums[i];
            long long key = x - lSum;
            if(costDict.count(key) > 0) {
                ans = min(ans, cost + costDict[key]);
            }
            if(lSum == x) {
                ans = min(ans, cost);
            }
            sum -= nums[i];
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
