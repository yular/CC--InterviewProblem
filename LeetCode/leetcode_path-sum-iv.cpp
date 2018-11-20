/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int pathSum(vector<int>& nums) {
        int ans = 0;
        if(nums.size() == 0){
            return ans;
        }
        
        vector<int> treeVal(20, -1);
        int maxPos = 0;
        for(int i = 0; i < nums.size(); ++ i){
            int pos = (1<<(nums[i]/100-1)) + (nums[i]/10)%10-1;
            treeVal[pos] = nums[i]%10;
            maxPos = max(maxPos, pos);
        }
        
        for(int i = 0; i < 4; ++ i){
            int start = (1<<i);
            int end = start + (1<<i);
            for(int j = start; j < end; ++ j){
                int leftChildPos = (j<<1), rightChildPos = (j<<1)+1;
                if(leftChildPos >= maxPos || (treeVal[leftChildPos] < 0 && treeVal[rightChildPos] < 0)){
                    ans += treeVal[j] >= 0 ? treeVal[j] : 0;
                    continue;
                }
                if(treeVal[leftChildPos] >= 0) {
                    treeVal[leftChildPos] += treeVal[j];
                }
                if(treeVal[rightChildPos] >= 0) {
                    treeVal[rightChildPos] += treeVal[j];
                }
            }
        }
        return ans;
    }
};
