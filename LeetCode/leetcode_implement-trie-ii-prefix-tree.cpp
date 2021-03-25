/*
*
* Tag: Trie (Data Structure)
* Time: O(n)
* Space: O(n + m)
*/

class TrieNode {
public:
    TrieNode(char c=0, bool end=false) {
        content = c;
        isEnd = end;
        cnt = 0;
    }
    char content;
    int cnt;
    bool isEnd;
    map<char, TrieNode*> branches;
};


class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        int i;
        for(i=0;i<word.size();i++) {
            if(node->branches.find(word[i]) != node->branches.end()) { 
                node=node->branches[word[i]];
                if(i==word.size()-1) {
                    node->isEnd=true;
                    ++ node->cnt;
                }
            }else
                break;
        }
        for(;i<word.size();i++) {
            TrieNode* tmp= new TrieNode(word[i],i==word.size()-1?true:false);
            node->branches[word[i]] = tmp;
            node=tmp;
            if(i==word.size()-1) {
                ++ node->cnt;
            }
        }
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++) {
            if(node->branches.find(word[i]) != node->branches.end()) { 
                node=node->branches[word[i]];
            }else{
                return 0;
            }
        }
        if(node->isEnd)
            return node->cnt;
        return 0;
    }
    
    int countWordsStartingWith(string prefix) {
        int ans = 0;
        TrieNode* node=root;
        for(int i=0;i<prefix.size();i++) {
            if(node->branches.find(prefix[i]) != node->branches.end()) { 
                node=node->branches[prefix[i]];
            }else{
                return 0;
            }
        }
        dfs(node, ans);
        return ans;
    }
    
    void erase(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++) {
            if(node->branches.find(word[i]) != node->branches.end()) { 
                node=node->branches[word[i]];
            }else{
                return ;
            }
        }
        if(node->isEnd && node->cnt > 0) {
            -- node->cnt;
        }
        return ;
    }
private:
    void dfs(TrieNode* root, int &ans) {
        if(root->isEnd) {
            ans += root->cnt;
        }
        
        for(auto it : root->branches) {
            dfs(it.second, ans);
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
