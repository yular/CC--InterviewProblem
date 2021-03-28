/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int numDifferentIntegers(string word) {
        if(word.size() == 0) {
            return 0;
        }
        
        int ans = 0;
        unordered_set<string> st;
        for(int i = 0; i < word.size(); ++ i) {
            string digit = "";
            while(i < word.size() && (word[i] >= '0' && word[i] <= '9')) {
                digit += word[i];
                ++ i;
            }
            if(digit.size() == 0) {
                continue;
            }
            int idx = 0;
            for(; idx < digit.size() && digit[idx] == '0'; ++ idx) {}
            if(idx < digit.size()) {
                digit = digit.substr(idx);
            } else {
                digit = "0";
            }
            
            if(st.count(digit) == 0) {
                st.insert(digit);
                ++ ans;
            }
        }
        return ans;
    }
};
