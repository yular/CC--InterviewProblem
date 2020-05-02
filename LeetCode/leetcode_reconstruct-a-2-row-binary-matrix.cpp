/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    vector<vector<int>> emptyRes;
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<int> sum = {upper, lower};
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));
        bool isValid = true;
        for(int i = 0; i < colsum.size(); ++ i) {
            int v = colsum[i];
            switch(v) {
                case 0:
                    break;
                case 1:
                    if(upper >= lower) {
                        -- upper;
                        ans[0][i] = 1;
                    } else {
                        -- lower;
                        ans[1][i] = 1;
                    }
                    break;
                case 2:
                    -- upper, -- lower;
                    ans[0][i] = ans[1][i] = 1;
                    break;
                default:
                    isValid = false;
            }
            
            if(upper < 0 || lower < 0) {
                isValid = false;
                break;
            }
        }
        if(upper > 0 || lower > 0) {
            isValid = false;
        }
        return isValid ? ans: emptyRes;
    }
};
