class Solution {
public:
    int peak(vector<int> nums,int start,int end){
    int mid = start + (end - start)/2;
    while(start <= end){

        if(mid == 0){
            if(nums[mid + 1] < nums[mid]){
                return mid;
            }
            else{
                start = mid + 1;
            }
        }
        else if (mid == nums.size() - 1){
            if(nums[mid - 1] < nums[mid]){
                return mid;
            }
            else{
                end = mid - 1;
            }
        }
        else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
            return mid;
        }
        else if (nums[mid + 1] > nums[mid]){
            start = mid  + 1;
        }
        else if(nums[mid - 1] > nums[mid]){
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return mid;
}
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        return peak(nums,0,nums.size()-1);
        
    }
};