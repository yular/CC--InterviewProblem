/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        if(s.size() != indices.size() || s.size() == 0) {
            return "";
        }
        
        string ans = s;
        for(int i = 0; i < indices.size(); ++ i) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};
