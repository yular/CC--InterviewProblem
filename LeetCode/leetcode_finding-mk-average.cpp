/*
*
* Tag: heap
* Time: O(mlgm)
* Space: O(m)
*/

class MKAverage {
private:
    long long sum;
    int tot, m, k, pos, len;
    multiset<int> small, mid, large;
    vector<int> arr;
public:
    MKAverage(int _m, int _k) {
        sum = 0;
        tot = pos = 0;
        m = _m, k = _k;
        arr.resize(m);
        len = m - 2*k;
    }
    
    void addElement(int num) {
        if(tot >= m) {
            updateQ(arr[pos%m]);
        }
        addQ(num);
        arr[pos%m] = num;
        ++ pos;
        ++ tot;
        return ;
    }
    
    int calculateMKAverage() {
        if(tot < m) {
            return -1;
        }
        return sum/len;
    }
private:
    void updateQ(int v){
        auto sit = small.rbegin(), mit = mid.rbegin(), lit = large.rbegin();
        if(v <= *sit) {
            auto it = small.find(v);
            small.erase(it);
        } else if(v <= *mit) {
            auto it = mid.find(v);
            sum -= *it;
            mid.erase(it);
        } else {
            auto it = large.find(v);
            large.erase(it);
        }
        
        if(small.size() < k) {
            auto it = mid.begin();
            small.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
        if(mid.size() < len) {
            auto it = large.begin();
            mid.insert(*it);
            sum += *it;
            large.erase(it);
        }
    }
    
    void addQ(int v) {
        small.insert(v);
        if(small.size() > k) {
            auto it = prev(small.end());
            mid.insert(*it);
            sum += *it;
            small.erase(it);
        }
        if(mid.size() > len) {
            auto it = prev(mid.end());
            large.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
        return ;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
