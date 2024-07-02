class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> freq;
        for(auto i:nums)freq[i]++;

        for(auto c: freq){
            if(c.second > 1)return true;
        }
        return false;
    }
};