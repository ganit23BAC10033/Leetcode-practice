class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=0;
        int r=0;
        while(r<n){
            while(nums[r]-nums[l]>2*k){
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};