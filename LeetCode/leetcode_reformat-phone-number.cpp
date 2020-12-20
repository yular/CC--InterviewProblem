/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string reformatNumber(string number) {
        if(number.size() == 0) {
            return number;
        }
        
        string tmp = "";
        for(int i = 0; i < number.size(); ++ i) {
            if(number[i] >= '0' && number[i] <= '9') {
                tmp += number[i];
            }
        }
        
        int n = tmp.size();
        string ans = "";
        for(int i = 0; i < n; ++ i) {
            if(n - i > 4) {
                ans += tmp.substr(i,3) + '-';
                i += 2;
                continue;
            }
            
            if(n - i <= 3) {
                ans += tmp.substr(i);
            } else {
                ans += tmp.substr(i,2) + '-' + tmp.substr(i + 2);
            }
            i = n - 1;
        }
        return ans;
    }
};
