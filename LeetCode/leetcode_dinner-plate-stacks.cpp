/*
*
* Tag: Data Structure, HashMap + TreeMap
* Time: O(lgn)
* Space: O(n)
*/

class DinnerPlates {
private:
    unordered_map<int,stack<int>> stkDict;
    set<int> nonFullStkDict, nonEmptyStkDict;
    int numOfPlates, cap, numOfStack;
public:
    DinnerPlates(int capacity) {
        numOfPlates = numOfStack = 0;
        cap = capacity;
        
        stkDict.clear();
        nonFullStkDict.clear();
        nonEmptyStkDict.clear();
    }
    
    void push(int val) {
        if(nonFullStkDict.size() == 0) {
            nonFullStkDict.insert(numOfStack ++);
        }
        
        auto it = nonFullStkDict.begin();
        int idx = *it;
        stkDict[idx].push(val);
        nonEmptyStkDict.insert(idx);
        
        if(stkDict[idx].size() == cap) {
            nonFullStkDict.erase(idx);
        }
        ++ numOfPlates;
        return;
    }
    
    int pop() {
        if(numOfPlates == 0 || nonEmptyStkDict.size() == 0) {
            return -1;
        }
        
        auto it = nonEmptyStkDict.rbegin();
        return popAtStack(*it);
    }
    
    int popAtStack(int index) {
        if(numOfPlates == 0 || nonEmptyStkDict.count(index) == 0) {
            return -1;
        }
        
        int ans = stkDict[index].top();
        stkDict[index].pop();
        if(stkDict[index].empty()) {
            nonEmptyStkDict.erase(index);
        }
        nonFullStkDict.insert(index);
        -- numOfPlates;
        return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
