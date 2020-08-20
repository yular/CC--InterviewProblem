/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(n^2)
*/

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        if(dict.size() == 0) {
            return false;
        }
        
        unordered_set<string> vis;
        for(int i = 0; i < dict.size(); ++ i) {
            string s = dict[i];
            for(int j = 0; j < s.size(); ++ j){
                char tmp = s[j];
                s[j] = '*';
                if(vis.count(s) > 0) {
                    return true;
                }
                
                vis.insert(s);
                s[j] = tmp;
            }
        }
        return false;
    }
};
