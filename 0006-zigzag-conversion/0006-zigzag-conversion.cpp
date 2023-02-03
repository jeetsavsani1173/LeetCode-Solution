class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> mat(numRows,vector<char>(1000,'?'));
        if(numRows==1) return s;
        int i=0,j=0;
        int dir=0;
        for(auto it:s)
        {
            mat[i][j]=it;
            if(i==0) dir=0;
            else if(i==numRows-1) dir=1;
            
            if(dir==0) i++;
            else i--,j++;
        }
        
        string ans;
        
        for(auto it:mat)
        {
            for(auto it1:it)
            {
                if(it1!='?')
                    ans.push_back(it1);
            }
        }
        return ans;
    }
};