//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        int r=0,c=0;
        int dir=0;
        while(r>=0 && r<R && c>=0 && c<C)
        {
            if(matrix[r][c]==1){
                matrix[r][c]=0;
                dir=(dir+1)%4;
            }
            
            if(dir==0) c++;
            if(dir==1) r++;
            if(dir==2) c--;
            if(dir==3) r--;
        }
        
        if(dir==0) c--;
        if(dir==1) r--;
        if(dir==2) c++;
        if(dir==3) r++;
        return {r,c};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends