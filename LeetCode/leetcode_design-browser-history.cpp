/*
*
* Tag: Stack
* Time: O(1)
* Space: O(n)
*/

class BrowserHistory {
private:
    vector<string> history;
    int top, cur;
public:
    BrowserHistory(string homepage) {
        history.resize(10100);
        top = 0, cur = 1;
        history[top ++] = homepage;
    }
    
    void visit(string url) {
        history[cur ++] = url;
        top = cur;
    }
    
    string back(int steps) {
        if(steps >= cur) {
            cur = 1;
        } else {
            cur -=  steps;
        }
        
        return history[cur - 1];
    }
    
    string forward(int steps) {
        if(cur + steps >= top) {
            cur = top;
        } else {
            cur += steps;
        }
        
        return history[cur - 1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
