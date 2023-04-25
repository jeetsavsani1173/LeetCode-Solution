class SmallestInfiniteSet {
public:
    int counter;
    // priority_queue<int, vector<int>, greater<int> > pq;
    set<int> st;
    SmallestInfiniteSet() {
        counter=1;
    }
    
    int popSmallest() {
        if(st.empty()){
            counter++;
            return counter-1;
        }
        int peek=*st.begin();
        
        if(counter==peek){
            counter++;
            // pq.pop();
            st.erase(peek);
        }else if(counter<peek){
            peek=counter;
            counter++;
        }else{
            // pq.pop();
            st.erase(peek);
        }
        
        return peek;
    }
    
    void addBack(int num) {
        // pq.push(num);
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */