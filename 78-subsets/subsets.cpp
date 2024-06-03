class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        for(int i = 0;i < 1<<nums.size();i++){
            int a = i;
            int count = 0;
            vector<int> ans;
            while(a != 0){
                if(a&1)ans.push_back(nums[count]);
                a = a>>1;
                count++;
            }
            powerset.push_back(ans);
        }
        return powerset;

        
    }
};