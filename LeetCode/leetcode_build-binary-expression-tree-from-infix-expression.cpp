/*
*
* Tag: Stack
* Time: O(n)
* Space: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    Node* expTree(string s) {
        if(s.size() == 0) {
            return NULL;
        }
        
        string exp = "(" + s + ")";
        stack<char> opStk;
        stack<Node *> ndStk;
        char prevOp;
        for(int i = 0; i < exp.size(); ++ i) {
            char c = exp[i];
            if(c >= '0' && c <= '9') {
                Node *nd = new Node(c);
                ndStk.push(nd);
                continue;
            }
            
            if(c == '+' || c == '-') {
                while(!opStk.empty() && opStk.top() != '('){
                    prevOp = opStk.top();
                    opStk.pop();

                    Node *b = ndStk.top();
                    ndStk.pop();
                    Node *a = ndStk.top();
                    ndStk.pop();
                    Node *nd = new Node(prevOp, a, b);

                    ndStk.push(nd);
                }
                
                opStk.push(c);
            } else if(c == '*' || c== '/') {
                while(!opStk.empty() && opStk.top() != '(' && opStk.top() != '+' && opStk.top() != '-'){
                    prevOp = opStk.top();
                    opStk.pop();

                    Node *b = ndStk.top();
                    ndStk.pop();
                    Node *a = ndStk.top();
                    ndStk.pop();
                    Node *nd = new Node(prevOp, a, b);

                    ndStk.push(nd);
                }

                opStk.push(c);
            } else if(c == '(') {
                opStk.push(c);
            } else if(c == ')'){
                int numOfOp = 0;
                vector<char> opVec;
                while(!opStk.empty() && opStk.top() != '(') {
                    opVec.push_back(opStk.top());
                    opStk.pop();
                    ++ numOfOp;
                }
                reverse(opVec.begin(), opVec.end());

                int numOfNum = numOfOp + 1;
                vector<Node *> nodeVec;
                while(!ndStk.empty() && numOfNum > 0) {
                    nodeVec.push_back(ndStk.top());
                    ndStk.pop();
                    -- numOfNum;
                }
                reverse(nodeVec.begin(), nodeVec.end());

                Node *nd = NULL;
                if(numOfOp == 0){
                    nd = nodeVec[0];
                }else if(numOfOp == 1){
                    nd = new Node(opVec[0], nodeVec[0], nodeVec[1]);
                } else {
                    Node *nxtNd = new Node(opVec[1], nodeVec[1], nodeVec[2]);
                    nd = new Node(opVec[0], nodeVec[0], nxtNd);
                }

                if(!opStk.empty() && opStk.top() == '('){
                    opStk.pop();
                }

                ndStk.push(nd);
            }
        }
        return ndStk.top();
    }
};
