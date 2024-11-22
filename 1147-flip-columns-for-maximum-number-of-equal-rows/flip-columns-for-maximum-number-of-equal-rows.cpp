class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int ans = 0;
        for(int row=0;row<n;row++){
             
            vector<int> bin = mat[row];
             
            vector<int> inv_bin;
            for(auto val:bin){
                int inverse_bit = (val==0)?1:0;
                inv_bin.push_back(inverse_bit);
            }  
            int tmp=0;
            for(int row=0;row<n;row++){
                vector<int> cur = mat[row];
                if(cur==bin or cur==inv_bin){
                    tmp++;
                }
            }

            ans = max(tmp, ans);
        }
        return ans;
    }
};