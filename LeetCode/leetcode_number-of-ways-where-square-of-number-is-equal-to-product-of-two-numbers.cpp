/*
*
* Tag: Hash
* Time: O(nm)
* Space: O(n+m)
*/

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {        
        unordered_map<int,int> numCnt1, numCnt2;
        for(int num : nums1){
            ++ numCnt1[num];
        }
        for(int num : nums2){
            ++ numCnt2[num];
        }
        
        int ans = 0;
        for(long long num : nums1){
            long long v = num*num;
            ans += getTripleCnt(v, nums2, numCnt2);
        }
        
        for(long long num : nums2){
            long long v = num*num;
            ans += getTripleCnt(v, nums1, numCnt1);
        }
        return ans;
    }
private:
    int getTripleCnt(long long v, vector<int>& nums, unordered_map<int,int> &numCnt) {
        int res = 0;
        unordered_map<int,int> copyCnt = numCnt;
        for(int i = 0; i < nums.size(); ++ i) {
            if(v%nums[i] != 0) {
                continue;
            }
            
            long long div = v/nums[i];
            if(copyCnt.count(div) > 0) {
                if(nums[i] != div) {
                    res += copyCnt[div];
                    -- copyCnt[nums[i]];
                } else if(copyCnt[div] > 1) {
                    res += (copyCnt[div] - 1);
                    -- copyCnt[div];
                }
            }
        }
        return res;
    }
};
