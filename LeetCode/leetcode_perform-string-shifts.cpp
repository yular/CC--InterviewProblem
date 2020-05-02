/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shifts) {
        if(shifts.size() == 0) {
            return s;
        }
        
        int step = 0;
        int n = s.size();
        for(vector<int> shift : shifts) {
            if(shift[0] == 0) {
                step = (step - shift[1] + n)%n;
            } else {
                step = (step + shift[1])%n;
            }
        }
        
        string ans = s;
        for(int i = 0; i < n; ++ i){
            int idx = (i + step + n)%n;
            ans[idx] = s[i];
        }
        return ans;
    }
};
