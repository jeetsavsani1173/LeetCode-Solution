class Solution {
public:
    int addDigits(int num) {
        if(num<10)
            return num;
        int temp_ans=0;
        int n=num;
        while(n)
        {
            temp_ans+=(n%10);
            n/=10;
        }
        return addDigits(temp_ans);
    }
};