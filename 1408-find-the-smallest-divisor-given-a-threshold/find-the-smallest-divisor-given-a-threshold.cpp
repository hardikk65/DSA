class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max = -1;
        int min = 1;
        int answer = 1;
        for(int j = 0; j < nums.size();j++){
            if(nums[j] > max){
                max = nums[j];
            }
        }
        int mid = min + (max - min)/2;
        int final_ans;
        while(min <= max){
            mid = min + (max - min)/2;
            answer = 0;
            for(int i = 0;i < nums.size();i++){
                // answer = answer + floor(nums[i]/mid);
                if(nums[i]%mid != 0){
                    answer = answer + (nums[i]/mid) + 1;
                }
                else{
                    answer = answer + nums[i]/mid;
                }
            }
            if(answer > threshold){
                min = mid + 1;
            }
            if(answer <= threshold){
                max = mid - 1;
                final_ans = mid;

            }
            
        }
        // cout<<ceil(9/5)<<endl;
        return final_ans;

        
    }
};