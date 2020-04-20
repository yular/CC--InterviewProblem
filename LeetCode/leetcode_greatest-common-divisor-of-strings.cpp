/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) {
            return "";
        }
        
        int len = gcd(str1.size(), str2.size());
        return str1.substr(0, len);
    }
private:
    int gcd(int a, int b) {
        return b == 0? a : gcd(b, a%b);
    }
};
