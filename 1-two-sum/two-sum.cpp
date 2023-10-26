class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mymap;
        vector<int> ans;
        for(int i = 0;i < nums.size();i++){
            int diff = target - nums[i];
            if (mymap.count(diff) == 0)mymap.insert({nums[i],i});
            else if(mymap.count(diff) == 1){
                ans.push_back(mymap.at(diff));
                ans.push_back(i);
                return ans;
            }
        }return {};        
    }
};