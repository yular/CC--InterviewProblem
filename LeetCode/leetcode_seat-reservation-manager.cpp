/*
*
* Tag: Data Structure Heap
* Time: O(nlgn), O(1), O(lgn)
* Space: O(n)
*/

class SeatManager {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    SeatManager(int n) {
        for(int i = 1; i <= n; ++ i) {
            pq.push(i);
        }
    }
    
    int reserve() {
        if(pq.empty()) {
            return -1;
        }
        
        int ans = pq.top();
        pq.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
