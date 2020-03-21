/*
*
* Tag: stack
* Time: O(k), O(1), O(1)
* Space: O(n)
*/

class CustomStack {
private:
    vector<int> stk;
    int maxSize, top;
public:
    CustomStack(int max_size) {
        maxSize = max_size;
        top = 0;
        stk.resize(max_size + 1);
    }
    
    void push(int x) {
        if(top >= maxSize) {
            return ;
        }
        
        stk[top ++] = x;
    }
    
    int pop() {
        if(top == 0) {
            return -1;
        }
        
        return stk[-- top];
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, top); ++ i) {
            stk[i] += val;
        }
        
        return ;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
