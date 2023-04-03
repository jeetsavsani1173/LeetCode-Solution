class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        if(people.size()==1)
            return 1;
        int n=people.size();
        sort(people.begin(),people.end());
        int i=0;
        int j=n-1;
        
        while(i<=j)
        {
            if((people[i]+people[j])<=limit)
            {
                j--;
                i++;
                ans++;
            }
            else 
            {
                j--;
                ans++;
            }
        }
        return ans;
    }
};