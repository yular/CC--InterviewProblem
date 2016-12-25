/*
*
* Tag: DP + Data Structure or DFS + Data Structure
* Time: O(n^2)
* Space: O(nm) where m is the average length of given words
*/
class TrieNode {
public:
    char content;
    bool isEnd;
    unordered_map<char, TrieNode *> branches;
    
    TrieNode(char c=0, bool end=false){
        content = c;
        isEnd = end;
    }
};

class Trie{
private:
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string s){
        TrieNode *node = root;
        int i;
        for(i = 0; i < s.size(); ++ i){
            if(node->branches.find(s[i]) != node->branches.end()){
                node = node->branches[s[i]];
                if(i == s.size() - 1)
                    node->isEnd = true;
            }else
                break;
        }
        for(; i < s.size(); ++ i){
            TrieNode *tmp = new TrieNode(s[i], i == s.size()-1?true:false);
            node->branches[s[i]] = tmp;
            node = tmp;
        }
    }
    
    void search(string &s, int start, vector<int> &dp){
        TrieNode *node = root;
        for(int i = start; i < s.size(); ++ i){
            if(node->branches.find(s[i]) != node->branches.end()){
                node = node->branches[s[i]];
                if(node->isEnd){
                    dp[i] = (start == 0? 1 : max(dp[i], dp[start - 1] + 1));
                }
            }else
                break;
        }
    }
};

class Solution {

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        if(words.size() == 0)
            return ans;
        Trie tree;
        int maxlen = 0;
        for(int i = 0; i < words.size(); ++ i){
            tree.insert(words[i]);
            maxlen = max(maxlen, (int)words[i].size());
        }
        vector<int> dp(maxlen + 1);
        for(int i = 0; i < words.size(); ++ i){
            
            for(int j = 0; j < words[i].size(); ++ j)
                dp[j] = 0;
            
            for(int j = 0; j < words[i].size(); ++ j){
                if(j == 0 || dp[j - 1] > 0)
                    tree.search(words[i], j, dp);
                if(dp[words[i].size() - 1] > 1){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
