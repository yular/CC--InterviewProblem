/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        if(S.size() == 0){
            return S;
        }
        
        int totalShifts = 0;
        for(int i = shifts.size() - 1; i >= 0; -- i){
            int val = (S[i] - 'a');
            totalShifts = (totalShifts + shifts[i])%26;
            val = (val + totalShifts)%26;
            S[i] = (val + 'a');
        }
        return S;
    }
};
