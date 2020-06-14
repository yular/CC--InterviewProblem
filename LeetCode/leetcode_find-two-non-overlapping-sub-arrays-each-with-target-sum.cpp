/*
*
* Tag: Sliding Window + Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        if(arr.size() < 2) {
            return -1;
        }
        
        unordered_map<int,int> sumDic;
        sumDic[0] = -1;
        
        int ans = INT_MAX;
        int sum = 0, n = arr.size(), minVal = INT_MAX;
        vector<int> minLen(n, minVal);
        for(int i = 0; i < n; ++ i) {
            sum += arr[i];
            sumDic[sum] = i;
            if(sum < target) {
                continue;
            }
            
            int v = sum - target;
            minLen[i] = minVal;
            if(sumDic.count(v) == 0) {
                continue;
            }
            
            int idx = sumDic[v], len = i - idx;
            if(idx >= 1 && minLen[idx] < INT_MAX) {
                ans = min(ans, minLen[idx] + len);
            }
            
            minVal = min(minVal, len);
            minLen[i] = minVal;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
