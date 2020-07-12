/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        vector<int> numCnt(1000, 0);
        for(int num : nums) {
            ans += numCnt[num];
            ++ numCnt[num];
        }
        return ans;
    }
};
