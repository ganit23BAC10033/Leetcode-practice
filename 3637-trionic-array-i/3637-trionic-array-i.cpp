class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        int count2=0;
        int count3=0;
        int i=0;
        bool ans=false;
        while(i<n-1 && nums[i]<nums[i+1] ){
            count1=1;
            i++;
        }
        while(i<n-1 && nums[i]>nums[i+1]){
            count2=1;
            i++;
        }
        while(i<n-1){
            count3=1;
            if(nums[i]>=nums[i+1]){
                count3=0;
                break;
            }
            i++;
            
        }
        if(count1==1 && count2==1 && count3==1){
            ans=true;
        }
          
        return ans;
    }
};