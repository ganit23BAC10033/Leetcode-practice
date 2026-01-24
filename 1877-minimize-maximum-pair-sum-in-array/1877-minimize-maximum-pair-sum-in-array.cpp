class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        int first=0;
        int last=n-1;
        while(first<last){
            ans=max(ans,nums[first]+nums[last]);
            first++;
            last--;
        }
        return ans;
        
    }
};