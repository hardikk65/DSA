class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m1;

        for(auto i: nums)m1[i]++;

        int sum = 0;

        for(auto i: m1){
            if(i.second > 1){
                sum += i.second*(i.second - 1)/2;
            }
        }
        return sum;
        
    }
};