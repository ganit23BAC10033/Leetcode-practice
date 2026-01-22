class Solution {
public:
    int minsumindex(vector<int>&nums){
        int n=nums.size();
        int minindex=-1;
        int sum=INT_MAX;
        for(int i=0;i<n-1;i++){
            int s=nums[i]+nums[i+1];
            if(sum>s){
                sum=s;
                minindex=i;
            }
        }
        return minindex;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        while(!is_sorted(nums.begin(),nums.end())){
            int index=minsumindex(nums);
            nums[index]=nums[index]+nums[index+1];
            nums.erase(nums.begin()+index+1);
            count++;
             
             
        }
        return count;
    }
};