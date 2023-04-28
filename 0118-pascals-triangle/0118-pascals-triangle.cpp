class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat;
        vector<int> v;
        v.push_back(1);
        mat.push_back(v);
        if(numRows==1)
            return mat;
        v.push_back(1);
        mat.push_back(v);
        for(int i=3;i<=numRows;i++)
        {
            vector<int> temp;
            temp.push_back(v[0]);
            for(int i=0;i<v.size()-1;i++)
                temp.push_back(v[i]+v[i+1]);
            temp.push_back(v[v.size()-1]);
            v=temp;
            mat.push_back(temp);
        }
        return mat;
    }
};