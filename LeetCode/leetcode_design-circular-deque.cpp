/*
*
* Tag: Data Structure (Queue)
* Time: O(1) for all operations
* Space: O(1) for all operations
*/
class MyCircularDeque {
private:
    vector<int> que;
    int headpnt, tailpnt, quesize, quevolume;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        que.resize(k + 1);
        headpnt = quesize = 0;
        tailpnt = 1;
        quevolume = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(quesize == quevolume){
            return false;
        }
        que[headpnt] = value;
        headpnt = (headpnt + que.size() - 1)%que.size();
        ++ quesize;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(quesize == quevolume){
            return false;
        }
        que[tailpnt] = value;
        tailpnt = (tailpnt + 1)%que.size();
        ++ quesize;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(quesize == 0){
            return false;
        }
        headpnt = (headpnt + 1)%que.size();
        -- quesize;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(quesize == 0){
            return false;
        }
        tailpnt = (tailpnt + que.size() - 1)%que.size();
        -- quesize;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty()? -1 : que[(headpnt + 1)%que.size()];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty()? -1 : que[(tailpnt + que.size() - 1)%que.size()];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return quesize == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return quesize == quevolume;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
