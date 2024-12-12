class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        sort(gifts.begin(), gifts.end());  
        while (k > 0 && n > 0) {
            int maxIndex = n - 1;   
            int newValue = sqrt(gifts[maxIndex]);  
            gifts[maxIndex] = newValue;  
            k--;
            sort(gifts.begin(), gifts.end()); 
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += gifts[i];  
        }
        return sum;
    }
};
