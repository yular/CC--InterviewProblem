/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() < 2) {
            return true;
        }
        
        int n = nums.size();
        for(int i = 0; i < n; ++ i) {
            bool isValid = true;
            for(int j = 1; j < n; ++ j) {
                int u = nums[(i + j + n - 1)%n], v = nums[(i + j)%n];
                if(u > v) {
                    isValid = false;
                    break;
                }
            }
            if(isValid) {
                return true;
            }
        }
        return false;
    }
};
