/*
*
* Tag: string
* Time: O(nm)
* Space: O(n)
*/
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(), false);
        if(queries.size() == 0){
            return ans;
        }
        
        for(int i = 0; i < queries.size(); ++ i){
            ans[i] = isMatchToPattern(queries[i], pattern);
        }
        return ans;
    }
    
private:
    bool isMatchToPattern(string query, string pattern){
        if(pattern.size() > query.size()) {
            return false;
        }
        
        int queryIdx = 0, patternIdx = 0;
        for(; queryIdx < query.size() || patternIdx < pattern.size(); ++ queryIdx) {
            if(islower(query[queryIdx])) {
                if(patternIdx < pattern.size() && islower(pattern[patternIdx]) && pattern[patternIdx] == query[queryIdx]) {
                    ++ patternIdx;
                }
                continue;
            }
            if(patternIdx >= pattern.size() || pattern[patternIdx] != query[queryIdx]){
                return false;
            }
            ++ patternIdx;
        }
        return true;
    }
};
