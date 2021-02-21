/*
*
* Tag: Greedy
* Time: O(nm)
* Space: O(1)
*/

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        if(groups.size() == 0) {
            return true;
        }
        if(nums.size() == 0) {
            return false;
        }
        
        int n = groups.size(), idx = 0;
        for(int i = 0; i < n; ++ i){
            int cnt = 0;
            idx = isFound(groups[i], nums, idx);
            if(idx == -1) {
                return false;
            }
            idx += groups[i].size();
        }
        return true;
    }
private:
    int isFound(vector<int>& group, vector<int>& nums, int startIdx) {
        int n = group.size(), m = nums.size();
        for(int i = startIdx; i + n <= m; ++ i) {
            bool isFound = true;
            for(int j = i, k = 0; k < n && j < m; ++ j, ++ k) {
                if(nums[j] != group[k]) {
                    isFound = false;
                    break;
                }
            }
            if(isFound) {
                return i;
            }
        }
        return -1;
    }
};
