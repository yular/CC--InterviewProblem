/*
*
* Tag: Sliding Window + Math
* Time: O(n)
* Space: O(n)
* Credit: https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/discuss/987347/JavaC%2B%2BPython-Solution
*/

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<long long> arr, sum(1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                arr.push_back(i);
            }
        }
        long long n = arr.size(), res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            sum.push_back(sum[i] + arr[i]);
        }
        for (int i = 0; i < n - k + 1; ++i) {
            res = min(res, sum[i + k] - sum[k / 2 + i] - sum[(k + 1) / 2 + i] + sum[i]);
        }
        res -= (k / 2) * ((k + 1) / 2);
        return res;
    }
};
