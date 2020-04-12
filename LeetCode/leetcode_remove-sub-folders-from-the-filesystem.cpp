/*
*
* Tag: Hash
* Time: O(nlgn + nm)
* Space: O(n^2)
*/

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        if(folder.size() == 0) {
            return {};
        }
        
        sort(folder.begin(), folder.end());
        
        unordered_set<string> pathDict;
        for(string path : folder) {
            if(pathDict.count(path) != 0) {
                continue;
            }
            
            string curPath = "";
            bool isValid = true;
            for(int i = 0; i < path.size() - 1; ++ i) {
                char c = path[i];
                curPath += c;
                if(path[i + 1] == '/') {
                    if(pathDict.count(curPath) != 0) {
                        isValid = false;
                        break;
                    }
                }
            }
            
            if(isValid) {
                pathDict.insert(path);
            }
        }
        
        vector<string> ans(pathDict.size());
        int idx = 0;
        for(string path : pathDict) {
            ans[idx ++] = path;
        }
        return ans;
    }
};
