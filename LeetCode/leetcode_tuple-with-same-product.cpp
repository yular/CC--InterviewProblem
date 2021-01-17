/*
*
* Tag: Hash
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        if(nums.size() < 4) {
            return 0;
        }
        
        unordered_map<int,int> dict;
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            for(int j = i + 1; j < n; ++ j){
                ++ dict[nums[i]*nums[j]];
            }
        }
        
        int ans = 0;
        for(auto it = dict.begin(); it != dict.end(); it ++) {
            int m = it->second;
            if(m >= 2) {
                ans += 4*m*(m - 1);
            }
        }
        return ans;
    }
};
