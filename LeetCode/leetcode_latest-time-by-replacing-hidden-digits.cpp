/*
*
* Tag: Greedy
* Time: O(1)
* Space: O(1)
*/

class Solution {
public:
    string maximumTime(string time) {
        if(time.size() == 0) {
            return time;
        }
        
        for(int i = 0; i < 5; ++ i) {
            if(time[i] != '?') {
                continue;
            }
            if(i == 0) {
                if(time[1] == '?' || time[1] <= '3') {
                    time[i] = '2';
                } else {
                    time[i] = '1';
                }
            } else if(i == 1) {
                if(time[0] == '2') {
                    time[i] = '3';
                } else {
                    time[i] = '9';
                }
            }else if(i == 3) {
                time[i] = '5';
            } else if(i == 4) {
                time[i] = '9';
            }
        }
        return time;
    }
};
