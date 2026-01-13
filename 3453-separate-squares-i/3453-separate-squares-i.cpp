#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low=9e-9;
        double high=-9e-9;
        for(int i=0;i<squares.size();i++){
            double y=squares[i][1];
            double l=squares[i][2];

            low=min(y,low);
            high=max(high,y+l);
        }
        for(int i=0;i<100;i++){
            double mid=(low+high)/2.0;
            double abovearea=0.0;
            double belowarea=0.0;
            for(int j=0;j<squares.size();j++){
                double y=squares[j][1];
                double l=squares[j][2];
                double top=y+l;
                if(mid>=top){
                    belowarea+=l*l;
                }
                else if(mid<=y){
                    abovearea+=l*l;
                }
                else{
                    belowarea+=(mid-y)*l;
                    abovearea+=(top-mid)*l;
                }
            }
            if(abovearea>belowarea){
                low=mid;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};
