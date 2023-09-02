class Solution {
    HashMap<String,Integer> map;
    int[] dp;
    int helper(int idx,String s){
        if(idx==s.length()) return 0;
        int ans=100;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx+1;i<=s.length();i++){
            String tmp=s.substring(idx,i);
            if(map.containsKey(tmp)) ans=Math.min(ans,helper(i,s));
            else ans=Math.min(ans,(i-idx)+helper(i,s));
        }
        return dp[idx]=ans;
    }
    public int minExtraChar(String s, String[] dictionary) {
        map = new HashMap<>();
        dp = new int[100];
        for(int i=0;i<100;i++) dp[i]=-1;
        for(String it:dictionary){
            map.put(it,1);
        }
        
        return helper(0,s);
    }
}