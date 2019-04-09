/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int ans = S.size(), n = S.size();
        if(n == 0){
            return 0;
        }
        
        vector<int> numOfZerosFromLeft(S.size(), 0), numOfZerosFromRight(S.size(), 0);
        for(int i = 0; i < n; ++ i){
            if(S[i] == '0') {
                numOfZerosFromLeft[i] = i == 0 ? 1 : 1 + numOfZerosFromLeft[i - 1];
            } else {
                numOfZerosFromLeft[i] = i == 0 ? 0 : numOfZerosFromLeft[i - 1];
            }
        }
        for(int i = n - 1; i >= 0; -- i){
            if(S[i] == '0') {
                numOfZerosFromRight[i] = i == n - 1 ? 1 : 1 + numOfZerosFromRight[i + 1];
            } else {
                numOfZerosFromRight[i] = i == n - 1 ? 0 : numOfZerosFromRight[i + 1];
            }
        }
        
        ans = min(ans, numOfZerosFromRight[0]);
        ans = min(ans, n - numOfZerosFromLeft[n - 1]);
        for(int i = 1; i < n; ++ i){
            ans = min(ans, i - numOfZerosFromLeft[i - 1] + numOfZerosFromRight[i]);
        }
        return ans;
    }
};
