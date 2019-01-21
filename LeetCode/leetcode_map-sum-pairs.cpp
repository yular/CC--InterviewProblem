/*
*
* Tag: Trie
* Time: O(n) n is the number of words
* Space: O(26^l) l is the average length of words
*/
class Trie {
private:
    class Node {
        public:
            char val;
            bool isEnd;
            int num;
            unordered_map<char, Node*> children;
        
            Node() {}
        
            Node(char v) {
                val = v;
                isEnd = false;
            }
    };
    
    Node *root;
public:
    Trie(){
        root = new Node();
    }
    
    void insertKeyword(string kw, int num){
        if(kw.size() == 0){
            return ;
        }
        
        Node *p = root;
        for(int i = 0; i < kw.size(); ++ i){
            if(p->children.count(kw[i]) == 0){
                Node *node = new Node(kw[i]);
                p->children[kw[i]] = node;
            }
            p = p->children[kw[i]];
        }
        p->isEnd = true;
        p->num = num;
    }
    
    int getPrefixSum(string prefix) {
        int ans = 0;
        
        Node *p = root;
        for(int i = 0; i < prefix.size(); ++ i){
            if(p->children.count(prefix[i]) == 0){
                return ans;
            }
            
            p = p->children[prefix[i]];
        }
        
        return calculateAllCommonPrefixKeywordsSum(p);
    }

private:
    int calculateAllCommonPrefixKeywordsSum(Node* root){
        int ans = 0;
        if(root->isEnd){
            ans += root->num;
        }
        
        for(auto it = root->children.begin(); it != root->children.end(); ++ it){
            ans += calculateAllCommonPrefixKeywordsSum(it->second);
        }
        return ans;
    }
};
