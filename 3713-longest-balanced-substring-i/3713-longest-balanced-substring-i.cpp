class Solution {
public:
    bool isbalaced(map<char,int>&mpp){
        int n=mpp.size();
        bool ans=true;
        auto it=mpp.begin();
        auto val=it->second;
        it++;
        for(;it!=mpp.end();it++){
            if(val!=it->second){
                ans=false;
                break;
            }
        }
        return ans;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            map<char,int>mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                if(mpp.size()>=1 && isbalaced(mpp)){
                    count=max(count,j-i+1);
                }
                
            }
        }
        return count;
    }
};