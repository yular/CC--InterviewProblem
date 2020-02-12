/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int num : nums){
            if((to_string(num).size()&1) == 0) {
                ++ cnt;
            }
        }
        
        return cnt;
    }
};
