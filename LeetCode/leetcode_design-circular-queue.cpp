/*
*
* Tag: Data Structure
* Time: O(1) for all operations
* Space: O(n)
*/
class MyCircularQueue {
private:
    vector<int> que;
    int headpnt, tailpnt, quesize;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        que.resize(k);
        headpnt = tailpnt = quesize = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(quesize == que.size()){
            return false;
        }
        que[tailpnt] = value;
        tailpnt = (tailpnt + 1)%que.size();
        ++ quesize;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(quesize == 0){
            return false;
        }
        headpnt = (headpnt + 1)%que.size();
        -- quesize;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty()? -1 : que[headpnt];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty()? -1 : que[(tailpnt + que.size() - 1)%que.size()];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return quesize == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return quesize == que.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
