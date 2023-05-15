class Solution {
public:
    vector<int> nextSmallestToLeft(vector<int>& heights){
        int n=heights.size();
        vector<int> ans(n,-1);
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
            
            if(!stk.empty()) ans[i]=stk.top();
            
            stk.push(i);
        }
        return ans;
    }
    vector<int> nextSmallestToRight(vector<int>& heights){
        int n=heights.size();
        vector<int> ans(n,n);
        stack<int> stk;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && heights[stk.top()]>=heights[i]) stk.pop();
            
            if(!stk.empty()) ans[i]=stk.top();
            
            stk.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        vector<int> nsel=nextSmallestToLeft(heights);
        vector<int> nser=nextSmallestToRight(heights);
        
        for(int i=0;i<n;i++){
            ans=max(ans,(nser[i]-nsel[i]-1)*heights[i]);
        }
        return ans;
    }
};