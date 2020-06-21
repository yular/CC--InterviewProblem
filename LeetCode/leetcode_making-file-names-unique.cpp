/*
*
* Tag: Hash + Implementation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        if(names.size() == 0) {
            return {};
        }
        
        int maxCnt = names.size() + 5;
        vector<string> ans = names;
        unordered_map<string,int> fileMaxCnt;
        for(int i = 0; i < names.size(); ++ i) {
            string name = names[i];
            if(fileMaxCnt.count(name) == 0) {
                fileMaxCnt[name] = 1;
                continue;
            }
            
            for(int k = fileMaxCnt[name]; k <= maxCnt; ++ k) {
                string newFileName = name + "(" + to_string(k) + ")";
                if(fileMaxCnt.count(newFileName) == 0) {
                    fileMaxCnt[newFileName] = 1;
                    ans[i] = newFileName;
                    fileMaxCnt[name] = k + 1;
                    break;
                }
            }
        }
        return ans;
    }
};
