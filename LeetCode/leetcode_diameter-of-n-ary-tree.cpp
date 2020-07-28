/*
*
* Tag: DFS
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
    int diameter(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        int ans = 0, dep = 0;
        dfs(root, ans, dep);
        return ans;
    }
private:
    void dfs(Node* root, int &ans, int &dep) {
        int firstDep = -1, secondDep = -1;
        for(Node * c : root->children) {
            int nextDep = 0;
            dfs(c, ans, nextDep);
            ++ nextDep;
            if(nextDep > firstDep) {
                secondDep = firstDep;
                firstDep = nextDep;
            } else if(nextDep == firstDep) {
                secondDep = firstDep;
            } else if(nextDep > secondDep) {
                secondDep = nextDep;
            }
        }
        
        dep = max(dep, max(firstDep, secondDep));
        ans = max(ans, firstDep);
        if(secondDep >= 0) {
            ans = max(ans, firstDep + secondDep);
        }
        return ;
    }
};
