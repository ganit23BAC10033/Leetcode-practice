class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         long xora=0;
         for(int i=0;i<nums.size();i++){
            xora=xora^nums[i];
         }
         int bucket1=0;
         int bucket2=0;
         int rightmost=(xora&xora-1)^xora;
         for(int i=0; i<nums.size();i++){
            if(nums[i]&rightmost){
                bucket1=bucket1^nums[i];
            }
            else{
                bucket2=bucket2^nums[i];
            }
         }

         return {bucket1,bucket2};
    }
};