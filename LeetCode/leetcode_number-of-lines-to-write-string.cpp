/*
*
* Tag: String
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> ans(2, 0);
        if(S == ""){
            return ans;
        }
        int curLineNumber = 1, curLineWidth = 0;
        for(int i = 0; i < S.size(); ++ i){
            int width = widths[S[i] - 'a'];
            if(curLineWidth + width > 100){
                ++ curLineNumber;
                curLineWidth = 0;
            }
            curLineWidth += width;
        }
        ans[0] = curLineNumber, ans[1] = curLineWidth;
        return ans;
    }
};
