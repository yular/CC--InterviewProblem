/*
*
* Tag: Geometry
* Time: O(n^2*lgn)
* Space: O(n)
*/

class Solution {
private:    
    struct Angle{
        double data;
        int is;
        bool operator < (const Angle& rhs) const {
            return data != rhs.data ? data < rhs.data : rhs.is < is;
        }
    }angle[51000];
    
public:
    int numPoints(vector<vector<int>>& points, int r) {
        if(points.size() == 0) {
            return 0;
        }
        
        int n = points.size(), res = 1;
        for(int i = 0; i < n; ++ i){
            int total = 0;
            for(int j = 0; j < n; ++ j){
                if(i==j) {
                    continue;
                }
                
                double dist = dis(points[i],points[j]);
                if(dist>2*r) {
                    continue;
                }
                
                double base = calAngle(points[i],points[j]);
                double extra = acos(dist/2.0/r);
                angle[total].data = base+extra;
                angle[total++].is = -1;
                angle[total].data = base-extra;
                angle[total++].is = 1;
            }
            if(total<=res) continue;
            
            sort(angle,angle+total);
            
            int tmp = 1;
            for(int j = 0; j < total; ++ j){
                tmp += angle[j].is;
                res = max(res,tmp);
            }
        }
        return res;
    }
private:
    inline double dis(vector<int> a, vector<int> b){
        return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
    }

    inline double calAngle(vector<int> a, vector<int> b){
        double res=atan2(b[1]-a[1], b[0]-a[0]);
        return res;
    }
};
