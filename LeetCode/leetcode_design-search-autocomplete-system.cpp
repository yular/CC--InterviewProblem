/*
*
* Tag: Trie
* Time: O(m) where m is the average length of words
* Space: O(n*m) 
*/
class AutocompleteSystem {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd;
    };
    TrieNode *root;
    
    unordered_map<string, int> searchCnt;
public:
    string curPrefix;
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        
        for(int i = 0; i < sentences.size(); ++ i) {
            string sentence = sentences[i];
            addNewSentence(sentence);
            searchCnt[sentence] = times[i];
        }
        
        curPrefix = "";
    }
    
    vector<string> input(char c) {
        vector<string> ans;
        if(c == '#') {
            updateAutoComplete();
            return ans;
        }
        
        curPrefix += c;
        ans = searchHotKeywords();
        return ans;
    }
    
private:
    void updateAutoComplete() {
        if(searchCnt.count(curPrefix) == 0){
            searchCnt[curPrefix] = 0;
            addNewSentence(curPrefix);
        }
        
        ++ searchCnt[curPrefix];
        curPrefix = "";
    }
    
    void addNewSentence(string sentence) {
        TrieNode *p = root;
        for(char c : sentence){
            if(p->children.count(c) == 0) {
                p->children[c] = new TrieNode();
            }
            p = p->children[c];
        }
        p->isEnd = true;
        
        return ;
    }
    
    vector<string> searchHotKeywords() {
        vector<string> ans;
        
        TrieNode *p = root;
        for(char c : curPrefix) {
            if(p->children.count(c) == 0){
                return ans;
            }
            p = p->children[c];
            
        }
        
        vector<pair<string,int>> wordList(3, make_pair("", -1));
        generateWordList(p, curPrefix, wordList);
                
        for(int i = 0; i < 3; ++ i){
            if(wordList[i].second == -1) {
                break;
            }
            ans.push_back(wordList[i].first);
        }
        return ans;
    }
    
    void generateWordList(TrieNode *root, string word, vector<pair<string,int>> &wordList){
        if(root->isEnd) {
            pair<string,int> cur = make_pair(word, searchCnt[word]);
            for(int i = 0; i < 3; ++ i){
                if(cur.second > wordList[i].second || (cur.second == wordList[i].second && cur.first < wordList[i].first) ) {
                    for(int j = 2; j > i; -- j){
                        
                        wordList[j] = wordList[j - 1];
                    }
                    
                    wordList[i] = cur;
                    break;
                }
            }
        }
        
        for(pair<char,TrieNode *> kv : root->children){
            generateWordList(kv.second, word + kv.first, wordList);
        }
        
        return;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
