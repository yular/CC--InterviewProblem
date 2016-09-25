/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans;
        int c = 0, add = 1, sum = 0;
        for(int i = digits.size() - 1; i >= 0; i --){
            sum = digits[i] + c + add;
            add = 0;
            if(sum >= 10)
                c = 1;
            else
                c = 0;
            sum %= 10;
            digits[i] = sum;
        }
        if(c)
            digits.insert(digits.begin(), 1);
        ans = digits;
        return ans;
    }
};
