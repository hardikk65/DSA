class Solution {
public:
    int lengthOfLIS(vector<int>& a) {

        vector<int> nums;
       nums.push_back(a[0]);
       
       for(int i = 1;i < a.size();i++){
           if(a[i] > nums.back())nums.push_back(a[i]);
           
           else{
               int index = lower_bound(nums.begin(),nums.end(),a[i]) - nums.begin();
               nums[index] = a[i];
           }
       }
       
       return nums.size();

        
        
    }
};