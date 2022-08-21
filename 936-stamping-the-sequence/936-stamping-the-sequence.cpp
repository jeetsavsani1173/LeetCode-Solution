class Solution {
public:
    bool canRepalce(string &target,int pos,string &stamp)
    {
        for(int i=0;i<stamp.size();i++){
            if(target[i+pos]!='?' && target[i+pos]!=stamp[i])
                return false;
        }
        return true;
    }
    
    void replace(string &target,int pos,int len,int &count)
    {
        for(int i=0;i<len;i++){
            if(target[i+pos]!='?'){
                target[i+pos]='?';
                count++;
            }
        }
    }
    vector<int> movesToStamp(string stamp, string target) {
        int count=0;
        vector<bool> visited(target.size(),false);
        vector<int> ans;
        while(count!=target.size()){
            bool didchange=false;
            for(int i=0;i<=target.size()-stamp.size();i++){
                if(!visited[i] && canRepalce(target,i,stamp)){
                    replace(target,i,stamp.size(),count);
                    visited[i]=true;
                    didchange=true;
                    ans.push_back(i);
                    if(count==target.size()) break;
                }
            }
            if(!didchange) return {};
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};