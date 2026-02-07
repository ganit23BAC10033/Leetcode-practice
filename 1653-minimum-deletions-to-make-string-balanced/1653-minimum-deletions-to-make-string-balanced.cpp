class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int bcount=0;
        int mindeletions=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b') bcount++;
            else{
                 mindeletions=min(mindeletions+1,bcount);
            }
            
        }
        return mindeletions;
    }
};