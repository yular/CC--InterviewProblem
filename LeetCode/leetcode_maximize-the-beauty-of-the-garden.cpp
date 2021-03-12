/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        if(flowers.size() < 2) {
            return 0;
        }
        
        int n = flowers.size(), sum = 0;
        bool hasPositive = false;
        vector<int> prefixSum(n, 0);
        unordered_map<int,vector<int>> dict;
        for(int i = 0; i < n; ++ i) {
            if(flowers[i] > 0) {
                sum += flowers[i];
                
            }
            prefixSum[i] = sum;
            if(dict.count(flowers[i]) == 0) {
                dict[flowers[i]] = {i, i};
            }
            dict[flowers[i]][0] = min(dict[flowers[i]][0], i);
            dict[flowers[i]][1] = max(dict[flowers[i]][1], i);
            if(dict[flowers[i]][0] != dict[flowers[i]][1]) {
                hasPositive = true;
            }
        }
        
        int ans = INT_MIN;
        for(auto it = dict.begin(); it !=  dict.end(); it ++) {
            int l = it->second[0], r = it->second[1];
            if(l == r) {
                continue;
            }
            int sum = 2*(it->first);
            if(l > 0) {
                sum -= prefixSum[l - 1];
            }
            sum += prefixSum[r - 1];
            if(it->first > 0) {
                sum -= it->first;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
