/*
*
* Tag: Data Structure (Dequeue)
* Time: O(n)
* Space: O(n)
*/

class MRUQueue {
private:
    deque<int> q;
    int length;
public:
    MRUQueue(int n) {
        length = n;
        for(int i = 1; i <= n; ++ i) {
            q.push_back(i);
        }
    }
    
    int fetch(int k) {
        int v = q.at(k - 1);
        q.erase(q.begin() + k - 1);
        q.push_back(v);
        return v;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
