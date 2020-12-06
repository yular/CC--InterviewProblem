/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if(nums.size() < 2 || k <= 0) {
            return 0;
        }
        
        unordered_map<int,int> dict;
        for(int num : nums) {
            ++ dict[num];
        }
        
        int ans = 0;
        for(auto it = dict.begin(); it != dict.end(); ++ it) {
            int u = it->first, v = k - it->first;
            if(dict.count(v) == 0) {
                continue;
            }
            if(u == v) {
                ans += it->second/2;
            } else {
                ans += min(dict[u], dict[v]);
            }
            dict[u] = dict[v] = 0;
        }
        return ans;
    }
};
