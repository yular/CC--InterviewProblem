/*
*
* Tag: Binary Search Tree
* Time: O(n^2)
* Space: O(n)
*/
class MyCalendarThree {
private:
    map<int, int> timeScheduler;
public:
    MyCalendarThree() {
        timeScheduler.clear();
    }
    
    int book(int start, int end) {
        timeScheduler[start] = timeScheduler.count(start) == 0? 1 : timeScheduler[start] + 1;
        timeScheduler[end] = timeScheduler.count(end) == 0? -1 : timeScheduler[end] - 1;
        
        int delta = 0, ans = 0;
        for(auto it = timeScheduler.begin(); it != timeScheduler.end(); ++ it){
            delta += it->second;
            ans = max(ans, delta);
        }
                
        return ans;
    }
};
