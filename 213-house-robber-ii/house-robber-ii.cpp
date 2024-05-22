class Solution {
public:

    int maxrobi(int index,vector<int> &nums, vector<int> &dp1){

        if(index >= nums.size())return 0;
        if(dp1[index] != -1)return dp1[index];

        int maxi = INT_MIN;
        for(int k = 2;k <= nums.size();k++){
            if(index + k == nums.size() - 1){
                continue;
            }
            else{
                maxi = max(maxi,nums[index] + maxrobi(index + k,nums,dp1));
            }
            
        }
        dp1[index] = maxi;

        return dp1[index];

    }

    int maxrob(int index,vector<int> &nums,vector<int> &dp){

        if(index >= nums.size())return 0;
        if(dp[index] != -1)return dp[index];

        int maxi = INT_MIN;
        for(int k = 2;k < nums.size();k++){
            maxi = max(maxi,nums[index] + maxrob(index + k,nums,dp));
        }
        dp[index] = maxi;

        return dp[index];

    }
    int rob(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2)return max(nums[0],nums[1]);
        
        vector<int> dp(nums.size(),-1);
        vector<int> dp1(nums.size(),-1);
        
        cout<<maxrobi(0,nums,dp1)<<endl;

        for(auto c: dp1){
            cout<<c<<endl;
        }
        return max(maxrobi(0,nums,dp1),max(maxrob(1,nums,dp),maxrob(2,nums,dp)));
    }
};