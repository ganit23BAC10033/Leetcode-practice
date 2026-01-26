class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
         int mindiff=INT_MAX;
        for(int i=0;i<n-1;i++){
            mindiff=min(mindiff,arr[i+1]-arr[i]);
        }
        for(int i=0;i<n-1;i++){
            int diff=arr[i+1]-arr[i];
            if(diff==mindiff){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};