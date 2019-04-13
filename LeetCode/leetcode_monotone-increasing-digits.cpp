/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        int ans = 0;
        if(N == 0){
            return ans;
        }
        if(N < 10) {
            return N;
        }
        
        string s = to_string(N);
        int decIdx = -1;
        for(int i = 1; i < s.size() && decIdx == -1; ++ i) {
            if(s[i] >= s[i - 1]) {
                continue;
            }
            decIdx = i - 1;
            for(int j = i; j < s.size(); ++ j){
                s[j] = '9';
            }
        }
        if(decIdx == -1){
            return N;
        }
        
        for(int i = decIdx; i >= 0; -- i){
            -- s[i];
            if(i != 0 && s[i] < s[i - 1]) {
                s[i] = '9';
            } else {
                break;
            }
        }
        return stoi(s);
    }
};
