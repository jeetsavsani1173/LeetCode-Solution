class Solution {
public:
    int partitionString(string s) {
        map<char,int> mp;
        set<char> st;
        for(auto it:s) st.insert(it);
        if(st.size()==s.size()) return 1;
        int last_Tick=0;
        map<char,int> temp;
        while(last_Tick<s.size()){
            if(temp[s[last_Tick]]==1){
                break;
            }else{
                temp[s[last_Tick]]++;
                last_Tick++;
            }
        }
        last_Tick--;
        int ans=1;
        cout<<last_Tick<<endl;
        for(int i=0;i<=last_Tick;i++)
            mp[s[i]]=i;
        for(int i=last_Tick;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=i;
                continue;
            }
            int prev_idx=mp[s[i]];
            
            if(prev_idx>last_Tick){
                last_Tick=i-1;
                ans++;
            }
            mp[s[i]]=i;
        }
        if(last_Tick!=(s.size()-1)) ans++;
        return ans;
    }
};