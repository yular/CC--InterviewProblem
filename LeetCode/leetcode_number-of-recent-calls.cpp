/*
*
* Tag: Data Structure (Queue)
* Time: O(n)
* Space: O(n)
*/

class RecentCounter {
private:
    queue<int> requestQueue;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!requestQueue.empty()){
            int oldestTime = requestQueue.front();
            if(oldestTime + 3000 < t) {
                requestQueue.pop();
            } else {
                break;
            }
        }
        requestQueue.push(t);
        return requestQueue.size();
    }
};
