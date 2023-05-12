class Solution {
public:
    vector<vector<int>> ans;
    void combineSum(int idx,vector<int>& num,int target,vector<int> &temp_ans,map<int,int> &mp)
    {
        if(idx==num.size())
        {
            if(target==0){
                ans.push_back(temp_ans);
            }
            return;
        }
        // if(target<0)
        //     return;
        // take then check howmany times 0 or 1 or 2 or 3 ....
        int freq=mp[num[idx]];
        for(int i=0;i<=freq;i++)
        {
            int newTarget=target;
            for(int j=0;j<i;j++)
            {
                temp_ans.push_back(num[idx]);
                newTarget-=num[idx];
            }
            if(newTarget>=0)
                combineSum(idx+1,num,newTarget,temp_ans,mp);
            for(int j=0;j<i;j++) 
                temp_ans.pop_back(); // back-Track
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp_ans;
        map<int,int> mp;
        for(auto it:candidates) mp[it]++;
        vector<int> num;
        for(auto it:mp) num.push_back(it.first);
        combineSum(0,num,target,temp_ans,mp);
        return ans;
    }
};