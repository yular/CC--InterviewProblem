/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> ans;
        if(A.size() == 0 || B.size() == 0){
            return ans;
        }
        
        for(int i = 0, j = 0; i < A.size() && j < B.size();){
            Interval intersectedInterval(-1,-1);
            if(isIntersected(A[i], B[j])) {
                intersectedInterval.start = max(A[i].start, B[j].start);
                intersectedInterval.end = min(A[i].end, B[j].end);
                ans.push_back(intersectedInterval);
            }
            
            if(A[i].end <= B[j].end){
                ++ i;
            } else {
                ++ j;
            }
        }
        return ans;
    }
private:
    bool isIntersected(Interval &a, Interval &b){
        return (a.end >= b.start && a.end <= b.end) || (b.end >= a.start && b.end <= a.end);
    }
};
