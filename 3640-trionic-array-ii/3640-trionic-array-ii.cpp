class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;

        const long long NEG = LLONG_MIN / 4;

        vector<long long> inc(n, NEG);
        vector<long long> incDec(n, NEG);
        vector<long long> incDecInc(n, NEG);

         
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                inc[i] = max(inc[i - 1], (long long)nums[i - 1]) + nums[i];
            }
        }

          
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                if (inc[i - 1] != NEG)
                    incDec[i] = inc[i - 1] + nums[i];
                if (incDec[i - 1] != NEG)
                    incDec[i] = max(incDec[i], incDec[i - 1] + nums[i]);
            }
        }

        long long ans = NEG;

        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                if (incDec[i - 1] != NEG)
                    incDecInc[i] = incDec[i - 1] + nums[i];
                if (incDecInc[i - 1] != NEG)
                    incDecInc[i] = max(incDecInc[i], incDecInc[i - 1] + nums[i]);
            }
            if (incDecInc[i] != NEG)
                ans = max(ans, incDecInc[i]);
        }

        return ans == NEG ? -1 : ans;
    }
};
