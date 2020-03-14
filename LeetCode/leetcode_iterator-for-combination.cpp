/*
*
* Tag: DFS
* Time: O(n!)
* Space: O(n!)
*/

class CombinationIterator {
private:
    vector<string> resSet;
    int curIdx;
public:
    CombinationIterator(string characters, int combinationLength) {
        string ans = "";
        dfs(ans, 0, 0, combinationLength, characters);
        curIdx = 0;
    }
    
    string next() {
        return resSet[curIdx ++];
    }
    
    bool hasNext() {
        return curIdx < resSet.size();
    }
    
private:
    void dfs(string &ans, int idx, int curLen, int totLen, string &characters) {
        if(curLen >= totLen) {
            resSet.push_back(ans);
            return ;
        }
        
        for(int i = idx; i < characters.size(); ++ i) {
            string cur = ans + characters[i];
            dfs(cur, i + 1, curLen + 1, totLen, characters);
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
