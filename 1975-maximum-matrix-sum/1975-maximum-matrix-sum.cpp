class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count=0;
        long long sum=0;
        int minel=INT_MAX;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                minel=min(minel,abs(matrix[i][j]));
                if((matrix[i][j])<0){
                    count++;
                     
                }
            }
        }
        if(count%2==1){
            sum=sum-(minel*2);
        }
        return sum;
    }
};