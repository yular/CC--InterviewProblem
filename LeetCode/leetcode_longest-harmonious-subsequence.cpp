/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> numCnt;
        for(int num : nums){
            ++ numCnt[num];
        }
        
        int ans = 0;
        for(int num : nums){
            ans = max(ans, numCnt.count(num + 1) ? (numCnt[num] + numCnt[num + 1]) : 0);
        }
        return ans;
    }
};
