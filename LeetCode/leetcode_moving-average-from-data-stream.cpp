class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        arr.resize(size);
        id = 0;
        sum = 0;
        n = 0;
    }
    
    double next(int val) {
        if(n < arr.size()){
            arr[id ++] = val;
            sum += val;
            ++ n;
        }else{
            id = (id + 1)%n;
            sum -= arr[id];
            arr[id] = val;
            sum += val;
        }
        return (double)sum/(double)n;
    }
private:
vector<int> arr;
int id;
int sum, n;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
