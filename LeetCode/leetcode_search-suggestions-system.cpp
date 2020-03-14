/*
*
* Tag: Trie, Data Structure
* Time: O(nmlgm), O(knm) where n is the dictionary size, m is the average length of dictionary word and k is the search word length.
* Space: O(knm)
*/

class Solution {
private:
    struct Node {
        bool isEnd;
        //vector<Node *> children;
        map<char,Node *> children;
        Node() {
            isEnd = false;
            //children.resize(26);
        }
    };
    Node *root;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        if(products.size() == 0 || searchWord.size() == 0) {
            return ans;
        }
        
        root = new Node();
        for(string product : products) {
            addWord(product);
        }
        
        string w = "";
        for(char c : searchWord) {
            w += c;
            ans.push_back(getMatchedWords(w));
        }
        return ans;
    }
    
    void addWord(string &word) {
        Node *p = root;
        for(char w : word) {
            if(p->children.count(w) == 0){
                p->children[w] = new Node();
            }
            
            p = p->children[w];
        }
        p->isEnd = true;
    }
    
    vector<string> getMatchedWords(string &w){
        vector<string> ans;
        Node *p = root;
        for(char c : w) {
            if(p->children.count(c) == 0) {
                return ans;
            }
            p = p->children[c];
        }
        dfs(p, w, ans);
        return ans;
    }
    
    void dfs(Node *p, string &w, vector<string> &ans) {
        if(ans.size() >= 3) {
            return ;
        }
        if(p->isEnd) {
            ans.push_back(w);
        }
        
        if(p->children.size() == 0) {
            return ;
        }
        
        for(auto it = p->children.begin(); it != p->children.end(); ++ it) {
            string cur = w + it->first;
            dfs(it->second, cur, ans);
            if(ans.size() >= 3) {
                return ;
            }
        }
        return ;
    }
};
