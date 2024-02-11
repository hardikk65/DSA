class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int final_answer = 0;
        int subarray_size = pattern.size() + 1;
        for(int i = 0;i < nums.size() - pattern.size();i++){
            int count = 0;
            for(int k = 0;k < pattern.size();k++){
                if(pattern[k] == 1 && nums[i + k + 1] > nums[i + k]){
                    count++;
                }
                if(pattern[k] == 0 && nums[i + k + 1] == nums[i + k]){
                    count++;
                }
                if(pattern[k] == -1 && nums[i + k + 1] < nums[i + k]){
                    count++;
                }
            }
            if(count == pattern.size()){
                final_answer++;
            }
        }
        return final_answer;
        
    }
};