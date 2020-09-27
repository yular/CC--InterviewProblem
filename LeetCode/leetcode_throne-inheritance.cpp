/*
*
* Tag: Hash + Design
* Time: O(n)
* Space: O(n)
*/

class ThroneInheritance {
private:
    unordered_map<string,vector<string>> parentTree;
    unordered_set<string> deathNote;
    string king;
    int tot;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
        parentTree.clear();
        tot = 1;
    }
    
    void birth(string parentName, string childName) {
        if(deathNote.count(parentName) > 0){
            return ;
        }
        
        parentTree[parentName].push_back(childName);
        ++ tot;
    }
    
    void death(string name) {
        deathNote.insert(name);
        -- tot;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans(tot);
        int idx = 0;
        dfs(king, ans, idx);
        return ans;
    }
private:
    void dfs(string &name, vector<string> &ans, int &idx) {
        if(deathNote.count(name) == 0) {
            ans[idx ++] = name;
        }
        if(parentTree.count(name) == 0 || parentTree[name].size() == 0) {
            return ;
        }
        
        for(string c : parentTree[name]) {
            dfs(c, ans, idx);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
