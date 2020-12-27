/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string maximumBinaryString(string binary) {
        if(binary.size() < 2) {
            return binary;
        }
        
        string ans = binary;
        int startIdx = 0, n = binary.size();
        for(; binary[startIdx] == '1' && startIdx < n; ++ startIdx) ;
        if(startIdx >= binary.size() - 1) {
            return ans;
        }
        
        int cnt1 = 0;
        for(int i = startIdx + 1; i < n; ++ i) {
            cnt1 += (ans[i] - '0');
            ans[i] = '0';
        }
        
        for(int i = n - 1; i > startIdx && cnt1 > 0; -- i, -- cnt1) {
            ans[i] = '1';
        }
        
        for(int i = startIdx; i < n - 1 && ans[i + 1] == '0'; ++ i) {
            ans[i] = '1';
        }
        return ans;
    }
};
