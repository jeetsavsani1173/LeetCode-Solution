class MedianFinder {
public:
    int size;
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int> > mn;
    MedianFinder() {
        size=0;
    }
    
    void balance(){
        int mx_size=mx.size();
        int mn_size=mn.size();
        while(abs(mn_size-mx_size)>1){
            if(mn.size()>mx.size()){
                mx.push(mn.top());
                mn.pop();
                mx_size++,mn_size--;
            }else{
                mn.push(mx.top());
                mx.pop();
                mn_size++,mx_size--;
            }
        }
    }
    
    void addNum(int num) {
        if(mn.size()==0 || mx.size()==0){
            mx.push(num);
        }else{
            int top1=mx.top();
            
            if(num<=top1){
                mx.push(num);
            }else{
                mn.push(num);
            }
        }
        balance();
        size++;
    }
    
    double findMedian() {
        if(size==1){
            if(mx.size()>mn.size())
                return (double)mx.top()*1.0;
            else
                return (double)mn.top()*1.0;
        }
        
        if(size%2==0){
            double ans=mx.top()+mn.top();
            return ans/2.0;
        }else{
            if(mx.size()<mn.size()){
                return mn.top()*1.0;
            }else{
                return mx.top()*1.0;
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */