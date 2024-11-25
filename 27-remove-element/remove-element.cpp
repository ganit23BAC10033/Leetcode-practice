class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int outlen = 0;       
        for (int i = 0; i < nums.size(); i++) {    
            if (nums[i] != val) {
                nums[outlen] = nums[i];  
                outlen++;                
            }
        }     
        return outlen;  
    }
};
