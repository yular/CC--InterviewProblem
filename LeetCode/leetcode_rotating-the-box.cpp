/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(nm) or O(1)
*/

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        if(box.size() == 0) {
            return {};
        }
        
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n, 0));
        for(int i = n - 1; i >= 0; -- i){
            int nxtLv = m - 1;
            for(int j = m - 1; j >= 0; -- j) {
                if(box[i][j] == '.') {
                    nxtLv = max(nxtLv, j);
                    ans[j][n - 1 - i] = '.';
                } else if(box[i][j] == '*') {
                    nxtLv = j - 1;
                    ans[j][n - 1 - i] = '*';
                } else {
                    if(nxtLv > j) {
                        ans[nxtLv][n - 1 - i] = '#';
                        ans[j][n - 1 - i] = '.';
                        nxtLv = max(nxtLv - 1, j);
                    } else {
                        nxtLv = j - 1;
                        ans[j][n - 1 - i] = box[i][j];
                    }
                }
            }
        }
        return ans;
    }
};
