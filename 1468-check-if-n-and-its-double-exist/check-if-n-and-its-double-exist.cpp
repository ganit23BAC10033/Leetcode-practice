class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
         
        unordered_set<int>seen_number;
        for(int ele: arr){
            if(seen_number.count(2*ele) or (ele % 2==0 and seen_number.count(ele/2))){
                return true;
                
            }
            seen_number.insert(ele);
        }
        return false ; 
    }
};