/*
*
* Tag: Data Structure
* Time: O(1)
* Space: O(n)
*/

class FrontMiddleBackQueue {
private:
    deque<int> fq,bq;
    int tot;
public:
    FrontMiddleBackQueue() {
        fq.resize(0);
        bq.resize(0);
        tot = 0;
    }
    
    void pushFront(int val) {
        if(fq.empty()) {
            bq.push_front(val);
        } else {
            fq.push_front(val);
        }
        updateQueue();
        ++ tot;
        return ;
    }
    
    void pushMiddle(int val) {
        if((tot&1) == 0) {
            bq.push_front(val);
        } else {
            fq.push_back(val);
        }
        updateQueue();
        ++ tot;
        return ;
    }
    
    void pushBack(int val) {
        bq.push_back(val);
        updateQueue();
        ++ tot;
        return ;
    }
    
    int popFront() {
        int v = -1;
        if(tot < 1) {
            return v;
        }
        if(!fq.empty()) {
            v = fq.front();
            fq.pop_front();
        } else {
            v = bq.front();
            bq.pop_front();
        }
        updateQueue();
        -- tot;
        return v;
    }
    
    int popMiddle() {
        int v = -1;
        if(tot < 1) {
            return v;
        }
        if((tot&1) == 0) {
            v = fq.back();
            fq.pop_back();
        } else {
            v = bq.front();
            bq.pop_front();
        }
        updateQueue();
        -- tot;
        return v;
    }
    
    int popBack() {
        int v = -1;
        if(tot < 1) {
            return v;
        }
        v = bq.back();
        bq.pop_back();
        updateQueue();
        -- tot;
        return v;
    }
private:
    void updateQueue() {
        if((int)bq.size() - (int)fq.size() > 1) {
            int v = bq.front();
            bq.pop_front();
            fq.push_back(v);
        } else if(fq.size() > bq.size()) {
            int v = fq.back();
            fq.pop_back();
            bq.push_front(v);
        }
        return ;
    }
};
