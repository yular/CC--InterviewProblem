/*
*
* Tag: Trie
* Time: O(n)
* Space: O(n)
*/

class StreamChecker {
private:
    struct Node {
        bool isEnd;
        Node *children[26];
        
        Node() {
            isEnd = false;
            memset(children,0,sizeof(children));
        }
    };
    
    struct Trie {
        Node *root;
        
        Trie() {
            root = new Node();
        }
        
        void addReversedWord(string &word) {
            Node *cur = root;
            for(int i = word.size() - 1; i >= 0; -- i) {
                int w = word[i] - 'a';
                if(cur->children[w] == NULL){
                    Node *newNode = new Node();
                    cur->children[w] = newNode;
                }
                cur = cur->children[w];
            }
            cur->isEnd = true;
            
            return;
        }
        
        // 0 -> not found, 1 -> prefix, 2 -> complete word
        bool canFindReversedWord(string &word) {
            Node *cur = root;
            for(int i = word.size() - 1; i >= 0; -- i) {
                int w = word[i] - 'a';
                if(cur->children[w] == NULL){
                    return false;
                }
                cur = cur->children[w];
                if(cur->isEnd) {
                    return true;
                }
            }
            
            return false;
        }
    };
    
    Trie *dict;
    string curWord;
public:
    StreamChecker(vector<string>& words) {
        dict = new Trie();
        curWord = "";
        for(string word : words) {
            dict->addReversedWord(word);
        }
        
        return;
    }
    
    bool query(char letter) {
        curWord += letter;
        return dict->canFindReversedWord(curWord);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
