class Solution {
public:
    int trap(vector<int>& height) {
        vector <int> left;
        vector<int> right;
        int ans=0;
        int size=height.size();
        
        int leftMax=0;
        int rightMax=0;
        
        for(int i=size-1;i>=0;i--){
            rightMax=max(height[i],rightMax);
            right.push_back(rightMax);   
        }
        
        for(int i=0;i<size;i++){
            leftMax=max(height[i],leftMax);
            left.push_back(leftMax);
        }
        reverse(right.begin(),right.end());
        for(int i=0;i<size;i++){
            ans+=(min(left[i],right[i])-height[i]);
        }
        
        return ans;
    }
};