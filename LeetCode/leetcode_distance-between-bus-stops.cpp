/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start == destination) {
            return 0;
        }
        if(start > destination) {
            swap(start, destination);
        }
        
        int sum = 0, dis = 0;
        for(int i = 0; i < distance.size(); ++ i) {
            sum += distance[i];
            if(i >= start && i < destination) {
                dis += distance[i];
            }
        }
        return min(dis, sum - dis);
    }
};
