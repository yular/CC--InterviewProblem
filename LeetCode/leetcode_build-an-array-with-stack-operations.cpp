/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        if(target.size() == 0 || n == 0) {
            return {};
        }
        
        vector<string> ans;
        for(int i = 1, j = 0; i <= n && j < target.size(); ++ i) {
            ans.push_back("Push");
            if(i == target[j]) {
                ++ j;
                continue;
            }
            ans.push_back("Pop");
        }
        return ans;
    }
};
