/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int bnd = n>>1;
        int ans_i = 1, ans_j = n - 1;
        for(; ans_i <= bnd; ++ ans_i){
            ans_j = n - ans_i;
            if(isValid(ans_i) && isValid(ans_j)) {
                break;
            }
        }
        
        vector<int> ans = {ans_i, ans_j};
        return ans;
    }
private:
    bool isValid(int v) {
        string str = to_string(v);
        for(char s : str) {
            if(s == '0') {
                return false;
            }
        }
        return true;
    }
};
