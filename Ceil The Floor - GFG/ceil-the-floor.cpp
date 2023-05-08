//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int floorOfArray(int start,int end,int target,vector<pair<int,int>> &vpr){
        int idx=-1;
        while(start<=end){
            int mid=(end-start)/2+start;
            if(vpr[mid].first<=target){
                idx=vpr[mid].second;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return idx;
    }
    int CeilOfArray(int start,int end,int target,vector<pair<int,int>> &vpr){
        int idx=-1;
        while(start<=end){
            int mid=(end-start)/2+start;
            if(vpr[mid].first>=target){
                idx=vpr[mid].second;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return idx;
    }
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    vector<pair<int,int>> vpr;
    for(int i=0;i<n;i++){
        vpr.push_back({arr[i],i});
    }
    sort(vpr.begin(),vpr.end());
    int floorr=floorOfArray(0,n-1,x,vpr);
    int ceilr=CeilOfArray(0,n-1,x,vpr);
    if(floorr!=-1) floorr=arr[floorr];
    if(ceilr!=-1) ceilr=arr[ceilr];
    return {floorr,ceilr};
}