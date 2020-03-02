/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        if(nums.size() == 0){
            return ans;
        }
        
        map<int,int> numCnt;
        for(int num : nums){
            ++ numCnt[num];
        }
        
        unordered_map<int,int> smallerCnt;
        int cnt = 0;
        for(auto it = numCnt.begin(); it != numCnt.end(); ++ it){
            smallerCnt[it->first] = cnt;
            cnt += it->second;
        }
        
        for(int i = 0; i < nums.size(); ++ i){
            ans[i] = smallerCnt[nums[i]];
        }
        return ans;
    }
};
