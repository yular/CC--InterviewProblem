/*
*
* Tag: DFS + Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res = "";
        if(root == NULL) {
            return res;
        }
        
        dfs(root, res, true);
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data == "") {
            return NULL;
        }
        
        Node* ans = NULL;
        if(data[0] >= '0' && data[0] <= '9') {
            ans = new Node(stoi(data));
            return ans;
        }
        
        vector<Node*> nodeStk(data.size());
        vector<char> charStk(data.size());
        int nodeTop = 0, charTop = 0;
        for(int i = 0; i < data.size(); ++ i) {
            char c = data[i];
            if(c == '[') {
                charStk[charTop ++] = c;
            } else if(c >= '0' && c <= '9') {
                int v = 0;
                while(i < data.size() && data[i] >= '0' && data[i] <= '9') {
                    v = v*10 + (data[i] - '0');
                    ++ i;
                }
                charStk[charTop ++] = '*';
                
                Node* node = new Node(v);
                nodeStk[nodeTop ++] = node;
            } else if(c == ']') {
                vector<Node*> children;
                int cnt = 0;
                while(charTop > 0 && charStk[charTop - 1] == '*') {
                    children.push_back(nodeStk[nodeTop - 1]);
                    -- charTop;
                    -- nodeTop;
                    ++ cnt;
                }
                -- charTop;
                
                if(nodeTop == 0) {
                    ans = children[0];
                    continue;
                }
                
                Node* root = nodeStk[nodeTop - 1];
                for(int j = 0; j < cnt; ++ j) {
                    root->children.push_back(children[cnt - 1 - j]);
                }
                
            }
        }
        return ans;
    }
    
private:
    void dfs(Node* root, string &res, bool useQuote) {
        if(root->children.size() == 0) {
            res += to_string(root->val) + " ";
            return ;
        }
        
        if(useQuote){
            res += "[";
        }
        res += to_string(root->val) + " ["; 
        
        bool addQuote = true;
        for(Node* child : root->children) {
            if(child == NULL) {
                continue;
            }
            
            string childRes = "";
            dfs(child, childRes, addQuote);
            
            res += childRes;
            addQuote = false;
        }
        
        if(useQuote){
            res += "]";
        }
        res += "] ";
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
