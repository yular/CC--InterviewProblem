/*
*
* Tag: Data Structure:
* Time: O(nlgm)
* Space: O(m)
*/
kk

class Solution {
private:
    vector<int> fenTree;
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(capacity == 0) {
            return false;
        }

        init(trips);

        for(vector<int> trip : trips){
            updateTotalPassengers(trip);
            if(getTotalPassengers(trip[1] + 1) > capacity){
                return false;
            }
        }
        return true;
    }
private:
    struct comparator{
        bool operator() (const vector<int> &a, const vector<int> &b){
            return a[1] == b[1] ? a[2] < b[2] : a[1] < b[1];
        }
    }cmp;

    void init(vector<vector<int>>& trips) {
        fenTree.resize(1100);

        sort(trips.begin(), trips.end(), cmp);
    }

    int getTotalPassengers(int startIdx) {
        int sum = 0;
        for(int i = startIdx; i > 0; i -= lowbit(i)) {
            sum += fenTree[i];
        }
        return sum;
    }

    void updateTotalPassengers(vector<int> trip){
        for(int i = trip[1] + 1; i < fenTree.size(); i += lowbit(i)) {
            fenTree[i] += trip[0];
        }
        for(int i = trip[2] + 1; i < fenTree.size(); i += lowbit(i)) {
            fenTree[i] += -trip[0];
        }
    }

    int lowbit(int x) {
        return (x&(-x));
    }
};
