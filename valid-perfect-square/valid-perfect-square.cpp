class Solution {
public:
    bool isPerfectSquare(int num) {
        int temp=(int)sqrt(num);
        return (temp*temp)==num;
    }
};