/*
* 
* Tag: Stack (Data Structure)
* Time: O(n)
* Space: O(n)
*/

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    
    Node(int val) : val(val) {};
    Node(char ch, Node *left, Node *right) : op(ch), left(left), right(right) {};
    virtual int evaluate() {
        if(op == 0) {
            return val;
        }
        
        int lRes = left->evaluate(), rRes = right->evaluate(), res = 0;
        switch(op) {
            case '+':
                return lRes + rRes;
            case '-':
                return lRes - rRes;
            case '*':
                return lRes * rRes;
            case '/':
                return lRes / rRes;
        }
        return res;
    }
protected:
    Node *left = nullptr, *right = nullptr;
    int val = 0, op = 0;
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        if(postfix.size() == 0) {
            return NULL;
        }
        
        stack<Node *> stk;
        for(string str : postfix) {
            if(str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/') {
                Node *rChild = stk.top();
                stk.pop();
                Node *lChild = stk.top();
                stk.pop();
                
                Node *root = new Node(str[0], lChild, rChild);
                stk.push(root);
                continue;
            }
            
            int v = stoi(str);
            Node* nd = new Node(v);
            stk.push(nd);
        }
        return stk.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
