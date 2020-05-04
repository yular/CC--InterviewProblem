/*
*
* Tag: Stack
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        if(expression.size() == 1) {
            return getVal(expression[0]);
        }
        
        bool ans = true;
        int n = expression.size(), top = 0;
        vector<char> opStk(n, 0);
        for(char c : expression) {
            if(c != ')') {
                if(c != ',') {
                    opStk[top ++] = c;
                }
                continue;
            }
            
            vector<bool> isFound(2, 0);
            while(top > 0 && opStk[top - 1] != '(') {
                char c = opStk[-- top];
                if(getVal(c)) {
                    isFound[1] = true;
                } else {
                    isFound[0] = true;
                }
            }
            -- top;
            char res = getExpResult(opStk[top - 1], isFound);
            opStk[top - 1] = res;
        }
        return getVal(opStk[0]);
    }
    
private:
    bool getVal(char c) {
        return c == 't' ? true : false;
    }
    
    char getExp(bool v) {
        return v? 't' : 'f';
    }
    
    char getExpResult(char op, vector<bool> &isFound) {
        char res = 't';
        switch(op){
            case '!':
                if(isFound[1]) {
                    res = 'f';
                }
                break;
            case '&':
                if(isFound[0]) {
                    res = 'f';
                }
                break;
            case '|':
                if(!isFound[1]) {
                    res = 'f';
                }
        }
        return res;
    }
};
