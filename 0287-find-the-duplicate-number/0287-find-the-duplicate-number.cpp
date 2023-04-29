class Solution {
public:
    // Logic : Use concept of finding cycle in LL
    // use slow and fast pointer approach to find the cycle in LL.
    // if there is any duplicate then it will always create cycle that for sure..
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        // find the cycle 
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        // finding the intersect point of cycle..
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};