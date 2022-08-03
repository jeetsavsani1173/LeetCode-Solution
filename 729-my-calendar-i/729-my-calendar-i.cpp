class MyCalendar {
public:
    set<pair<int,int>> stpr;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(stpr.size()==0){
            stpr.insert({start,end});
            return true;
        }
        auto it=stpr.lower_bound({start,INT_MAX});
        if(it!=stpr.end()){
            pair<int,int> curr=(*it);
            if(end>curr.first) return false;
        }
        if(it!=stpr.begin()){
            pair<int,int> prev=(*(--it));
            if(start<prev.second) return false;
        }
        stpr.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */