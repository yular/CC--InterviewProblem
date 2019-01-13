/*
*
* Tag: Sort + Math
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if(points.size() <= K){
            return points;
        }
        
        sort(points.begin(), points.end(), cmp);
        vector<vector<int>> ans(points.begin(), points.begin() + K);
        return ans;
    }
    
private:
    struct pointComparator{
        bool operator() (vector<int> &a, vector<int> &b){
            int disA = a[0]*a[0] + a[1]*a[1], disB = b[0]*b[0] + b[1]*b[1];
            return disA < disB;
        }
    }cmp;

};
