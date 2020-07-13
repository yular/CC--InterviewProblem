/*
*
* Tag: Hash
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

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        if(tree.size() == 0) {
            return NULL;
        }
        
        int n = tree.size();
        Node *ans;
        unordered_map<Node *,int> inDegCnt;
        for(Node *r : tree) {
            for(Node *c : r->children) {
                ++ inDegCnt[c];
            }
            if(inDegCnt.count(r) == 0) {
                inDegCnt[r] = 0;
            }
        }
        
        for(auto it : inDegCnt) {
            if(it.second == 0) {
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};


/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
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

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        if(tree.size() == 0) {
            return NULL;
        }
        
        long long res = 0;
        for(Node *r : tree) {
            res ^= r->val;
            for(Node *c : r->children) {
                res ^= c->val;
            }
        }
        
        Node *ans;
        for(Node *r : tree) {
            if(r->val == res) {
                ans = r;
                break;
            }
        }
        return ans;
    }
};
