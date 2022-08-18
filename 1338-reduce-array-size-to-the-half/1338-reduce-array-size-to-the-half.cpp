class Solution {
public:
    static bool comp(int &a,int &b){
        return a>b;
    }
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(auto it:arr) mp[it]++;
        vector<int> vect;
        for(auto it:mp) vect.push_back(it.second);
        sort(vect.begin(),vect.end(),comp);
        int size=arr.size();
        int i=0;
        while(size>arr.size()/2){
            size-=vect[i++];
        }
        
        return i;
    }
};