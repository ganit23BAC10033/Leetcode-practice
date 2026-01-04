class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            int el=nums[i];
            int sum=0;
            for(int j=1;j<=sqrt(el);j++){
                if(el%j==0 && j*j==el){
                    count++;
                    sum+=j;
                }
                else{
                    if(el%j==0){
                    sum+=j+(el/j);
                    count+=2;
                   }
                }
                
            }
            if(count==4){
                ans+=sum;
            }
        }
        return ans;
    }
};