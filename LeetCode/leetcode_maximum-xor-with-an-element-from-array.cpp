/*
*
* Tag: Trie
* Time: O(qn)
* Space: O(n)
*/

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    
    TrieNode(bool end=false) {
        isEnd=end;
        children.resize(2);
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }

    // Inserts a number into the trie.
    void insert(int n) {
        TrieNode* node = root;
        int i;
        for(int i = 30; i >= 0; -- i) {
            int idx = ((n>>i)&1);
            if(node->children[idx] == NULL) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    // Returns if the number is in the trie, otherwise -1
    int search(int x, int m, int val, int idx, TrieNode* node) {
        if(val > m) {
            return -1;
        }
        
        if(idx < 0) {
            return val;
        }
        
        int curBit = (x >>idx) & 1, pos = curBit^1;
        if(node->children[pos] != NULL) {
            int res = search(x, m, val | (pos << idx), idx - 1, node->children[pos]);
            if(res >= 0) return res;
        }
        if(node->children[curBit] != NULL) {
            return search(x, m, val | (curBit << idx), idx - 1, node->children[curBit]);
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        for(auto x : nums) {
            trie.insert(x);
        }
        
        int n = queries.size(), idx = 0;
        vector<int> ans(n, -1);
        for(vector<int> &q : queries) {
            int x = q[0], m = q[1];
            int res = trie.search(x, m, 0, 30, trie.root);
            if(res >= 0) {
                ans[idx] = (res ^ x);
            }
            ++ idx;
        }
        return ans;
    }
};
