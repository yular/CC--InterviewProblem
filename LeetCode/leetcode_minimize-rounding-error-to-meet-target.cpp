/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    const double EPS = 1e-12;
public:
    string minimizeError(vector<string>& prices, int target) {
        if(prices.size() == 0) {
            return "0";
        }
        
        ostringstream out;
        out << std::fixed;
        out << std::setprecision(3);
        
        int upperSum = 0, n = prices.size();
        double tmp = 0, sum = 0;
        vector<pair<double,double>> arr(n);
        for(int i = 0; i < n; ++ i) {
            double v = stod(prices[i]);
            double c = ceil(v);
            arr[i] = make_pair(v, c);
            upperSum += c;
            sum += v;
            tmp += (c - v);
        }
        if(upperSum == target) {
            out<<tmp;
            return out.str();
        } else if(upperSum < target) {
            return "-1";
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        int lowerSum = 0;
        tmp = 0;
        for(int i = n - 1; i >= 0; -- i){
            double v = floor(arr[i].first);
            lowerSum += v;
            tmp += (arr[i].first - v);
        }
        if(lowerSum == target) {
            out<<tmp;
            return out.str();
        } else if(lowerSum > target) {
            return "-1";
        }
        
        double ans = 0;
        int curSum = 0;
        for(int i = 0; i < n; ++ i) {
            ans += (arr[i].second - arr[i].first);
            curSum += arr[i].second;
            lowerSum -= floor(arr[i].first);
            tmp -= (arr[i].first - floor(arr[i].first));
            if(curSum + lowerSum == target) {
                ans += tmp;
                break;
            }
        }
        
        out << ans;
        return out.str();
    }
    
private:
    struct comparator {
        bool operator() (const pair<double,double> &a, const pair<double,double> &b) {
            return a.second - a.first < b.second - b.first;
        }
    }cmp;
};
