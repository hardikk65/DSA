class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest_alt = 0;
        int sum = 0;
        for(auto i: gain){
            sum += i;
            highest_alt = max(highest_alt,sum);
        }
        return highest_alt;
        
    }
};