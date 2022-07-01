class Solution {
public:
    static bool comp(vector<int> &v1,vector<int> &v2)
    {
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int ans=0;
        for(int i=0;i<boxTypes.size();i++)
        {
            int mn=min(boxTypes[i][0],truckSize);
            ans+=(mn*boxTypes[i][1]);
            truckSize-=mn;
            if(!truckSize) break;
        }
        return ans;
    }
};