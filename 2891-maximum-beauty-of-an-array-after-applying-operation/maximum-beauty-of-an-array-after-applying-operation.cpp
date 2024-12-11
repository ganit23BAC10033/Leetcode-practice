class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=0;
        int h=0;
        while(h<n){
            while(nums[h]-nums[l]>2*k){
                l++;
            }
            ans=max(ans,h-l+1);
            h++;
        }
        return ans;
        
    }
};