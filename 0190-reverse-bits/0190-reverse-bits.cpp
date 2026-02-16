class Solution {
public:
    int binarytodecimal(string &s){
         
        int n=s.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ans+=(1<<(n-i-1));
            }
        }
        return ans;
    }
    string decimaltobinary(int n){
        string ans="";
        for(int i=31;i>=0;i--){
            if(n&(1<<i)) ans+='1';
            else ans+='0';
        }
        return ans;
    }
    int reverseBits(int n) {
        string bin=decimaltobinary(n);
        reverse(bin.begin(),bin.end());
        int ans=binarytodecimal(bin);
        return ans;
    }
};