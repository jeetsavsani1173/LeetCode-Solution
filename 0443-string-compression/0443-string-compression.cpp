class Solution {
public:
    void put(vector<char> &ans,int count){
        if(count==1) return;
        vector<int> vect;
        while(count){
            vect.push_back(count%10);
            count/=10;
        }
        reverse(vect.begin(),vect.end());
        for(auto it:vect)
            ans.push_back('0'+it);
    }
    int compress(vector<char>& chars) {
        vector<char> ans;
        
        char prev=chars[0];
        int count=1;
        ans.push_back(chars[0]);
        for(int i=1;i<chars.size();i++)
        {
            if(prev==chars[i]){
                count++;
            }else{
                put(ans,count);
                prev=chars[i];
                count=1;
                ans.push_back(chars[i]);
            }
        }
        if(count>1){
            put(ans,count);
        }
        for(int i=0;i<ans.size();i++)
            chars[i]=ans[i];
        return ans.size();
    }
};