/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string toLowerCase(string str) {
        transform(str.begin(),str.end(),str.begin(),::tolower);
        return str;
    }
};
