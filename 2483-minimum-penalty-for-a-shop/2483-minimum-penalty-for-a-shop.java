class Solution {
    public int bestClosingTime(String customers) {
        int ys=0,ns=0;
        for(int i=0;i<customers.length();i++){
            if(customers.charAt(i)=='Y') ys++;
            else ns++;
        }
        int mn=Integer.MAX_VALUE;
        int ans=-1;
        int newYs=0,newNs=0;
        for(int i=0;i<customers.length();i++){
            int newPenalty=newNs+(ys-newYs);
            if(newPenalty<mn){
                mn=newPenalty;
                ans=i;
            }
            if(customers.charAt(i)=='Y') newYs++;
            else newNs++;
        }
        
        int newPenalty=newNs+(ys-newYs);
        if(newPenalty<mn){
            mn=newPenalty;
            ans=customers.length();
        }
        return ans;
    }
}