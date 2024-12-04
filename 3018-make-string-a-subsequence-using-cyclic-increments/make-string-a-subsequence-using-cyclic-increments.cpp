class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int sf1 = 0;  
        int sf2 = 0;  

        if (n < m) return false;

        while (sf1 < n && sf2 < m) {
            char nextch = char((str1[sf1] - 'a' + 1) % 26 + 'a');
            if (str1[sf1] == str2[sf2] || str2[sf2] == nextch) {
                sf2++;  
            }
            sf1++;  
        }
        return sf2 == m;
    }
};
