class Solution {
public:
    int minDeletions(string s) {
        vector<int> vect[s.size()+1];
        map<char,int> mp;
        for(auto &it:s) mp[it]++;
        int mxFreq=0;
        for(auto &it:mp) 
        {
            vect[it.second].push_back(1);
            mxFreq=max(mxFreq,it.second);
        }
        int ans=0;
        for(int i=mxFreq;i>=1;i--)
        {
            int size=vect[i].size();
            if(size<=1) continue;
            else{
                size--;
                for(int j=i-1;j>0;j--)
                {
                    if(vect[j].size()==0)
                    {
                        vect[j].push_back(0);
                        size--;
                        ans+=(i-j);
                    }
                    if(size==0) break;
                }
                if(size) ans+=(i*size);
            }
        }
        
        return ans;
    }
};