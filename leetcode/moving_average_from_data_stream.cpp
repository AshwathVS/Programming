class MovingAverage {
public:
    list<int> ll;
    int sum=0, size;

    MovingAverage(int _size) {
        size = _size;
    }
    
    double next(int val) {
        if(ll.size() == size) {
            sum-=ll.front();
            ll.pop_front();
        }
        
        ll.push_back(val);
        sum+=val;
        
        return (double)sum/ll.size();
    }
};