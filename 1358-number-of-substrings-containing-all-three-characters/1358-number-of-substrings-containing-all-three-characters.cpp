class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int ans=0;
        
        int i=0;
        int prev=-1;
        int j=0;
        for(;j<s.size();j++)
        {
            mp[s[j]]++;
            if(mp.size()<3){
                // prev=i;
                continue;
            }
            while(mp.size()==3)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp[s[i]]++;
                    break;
                }else{
                    i++;
                }
            }
            
            ans+=(i-prev)*(s.size()-j);
            // cout<<"index "<<j<<"=> ";
            // cout<<"i->"<<i<<" prev->"<<prev<<endl;
            // cout<<ans<<endl;
            prev=i;
        }
        
        return ans;
    }
};