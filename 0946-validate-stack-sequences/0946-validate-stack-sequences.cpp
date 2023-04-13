class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int> st;
        int i=0,j=0;
        
        while(true){
            if(st.size()>0 && st.top()==popped[j]){
                st.pop();
                j++;
            }else if(i<n){
                st.push(pushed[i]);
                i++;
            }else{
                break;
            }
        }
        // cout<<i<<" "<<j<<endl;
        // cout<<st.size()<<endl;
        return (st.size()==0);
    }
};