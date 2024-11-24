class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int minval=INT_MAX;
        int negativen=0;
        long long sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                minval=min(minval,abs(matrix[i][j]));
                if(matrix[i][j]<0) negativen++;
            }
        }
        if(negativen%2==0){
            return sum;
        }
        return sum-2*minval;
        
    }
};